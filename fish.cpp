// Fish.cpp
#include "Fish.hpp"

Fish::Fish(int x, int y, int width, int height,int x_sor, int y_sor)  {
    // Set initial pose
    srcRect = { x_sor,y_sor, width, height };
    moverRect = { x, y, width, height };
}

Fish::~Fish() {
    // If there's any cleanup needed when a Fish object is destroyed, you can put it here.
}

void Fish::update() {
    // Update logic goes here (if needed)
    moverRect.x += 5;
}

void Fish::drawObjects(SDL_Renderer* renderer, SDL_Texture* assets) {
    // Draw logic goes here
    SDL_RenderCopy(renderer, assets, &srcRect, &moverRect);
}
void Fish::createObject(int x, int y) {
    // Create a new fish object (implementation in derived classes)
    pushToVector();
}

