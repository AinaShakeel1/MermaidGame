#include "game.hpp"
#include "HUMania.hpp"

bool Game::init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "HU Mania", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}

			}
		}
	}

	return success;
}

bool Game::loadMedia()
{
	//Loading success flag
	bool success = true;
	
	assets = loadTexture("killerfish.png");
	assets2=loadTexture("fish2.png");
    gTexture = loadTexture("underwater.jpg");
	if(assets==NULL || gTexture==NULL || assets2==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	return success;
}

void Game::close()
{
	//Free loaded images
	SDL_DestroyTexture(assets);
	SDL_DestroyTexture(assets2);
	assets=NULL;
	assets2=NULL;
	SDL_DestroyTexture(gTexture);
	
	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* Game::loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}

void Game::run( )

{
	//HUMania humania;
	bool quit = false;
	SDL_Event e;

	Uint32 lastkillerspawntime=SDL_GetTicks();
	Uint32 spawnkillerinterval=3000;
	Uint32 lastHarmlessSpawnTime = SDL_GetTicks();
    Uint32 harmlessSpawnInterval = 5000; // Adjust the interval as needed




	while( !quit )
	{
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}
		}

			Uint32 currenttime=SDL_GetTicks();
			//killer fish spwans
			 if (currenttime - lastkillerspawntime >= spawnkillerinterval)
			{
				lastkillerspawntime = currenttime;
				int x = rand() % SCREEN_WIDTH;
				int y = rand() % SCREEN_HEIGHT;
				KillerFish newKillerFish(x, y);
				killerFishList.push_back(newKillerFish);
			}

			// if(currenttime-lastspawntime>=spawninterval){
			// 		lastspawntime=currenttime;
			// 		int x = rand() % SCREEN_WIDTH;
            // 		int y = rand() % SCREEN_HEIGHT;
			// 		humania.createObject(x, y);
			// }
			

			//spawnharmlessfish
			if (currenttime - lastHarmlessSpawnTime >= harmlessSpawnInterval)
			{
				lastHarmlessSpawnTime = currenttime;
				int x = rand() % SCREEN_WIDTH;
				int y = rand() % SCREEN_HEIGHT;
				HarmlessFish newHarmlessFish(x, y);
				harmlessfishlist.push_back(newHarmlessFish);
			}
			// Update objects
        for (size_t i = 0; i < killerFishList.size(); ++i)
		{
			killerFishList[i].update();
		}
		for (size_t i = 0; i < harmlessfishlist.size(); ++i)
		{
			harmlessfishlist[i].update();
		}


       

			
			// if(e.type == SDL_MOUSEBUTTONDOWN){
			// //this is a good location to add pigeon in linked list.
			// 	int xMouse, yMouse;
			// 	SDL_GetMouseState(&xMouse,&yMouse);
			// 	createObject(xMouse, yMouse);
			// }
		// humania.update();

		SDL_RenderClear(gRenderer); //removes everything from renderer
		SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);//Draws background to renderer
		//***********************draw the objects here********************

		//drawObjects(gRenderer, assets);
		// humania.drawObjects(gRenderer, assets);


		// Draw the objects
        for (size_t i = 0; i < killerFishList.size(); ++i)
		{
			killerFishList[i].drawObjects(gRenderer, assets);
		}

// Draw HarmlessFish objects using a traditional for loop
		for (size_t i = 0; i < harmlessfishlist.size(); ++i)
		{
			harmlessfishlist[i].drawObjects(gRenderer, assets2);
		}
		//****************************************************************
    	SDL_RenderPresent(gRenderer); //displays the updated renderer

	    SDL_Delay(200);	//causes sdl engine to delay for specified miliseconds
	}
			
}
