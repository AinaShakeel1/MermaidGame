#ifndef GAME_HPP
#define GAME_HPP
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "KillerFish.hpp"
#include "harmlessfish.hpp"


class Game {
public:
    bool init();
    bool loadMedia();
    void close();
    SDL_Texture* loadTexture(std::string path);
    void run();

private:
    const int SCREEN_WIDTH = 1000;
    const int SCREEN_HEIGHT = 600;

    SDL_Window* gWindow = nullptr;
    SDL_Renderer* gRenderer = nullptr;
    SDL_Texture* gTexture = nullptr;
    SDL_Texture* assets = nullptr;
    SDL_Texture* assets2=nullptr;

    std::vector<KillerFish> killerFishList;
    std::vector<HarmlessFish>harmlessfishlist;

    Uint32 lastSpawnTime;
    Uint32 spawnInterval;
};

#endif // GAME_HPP
