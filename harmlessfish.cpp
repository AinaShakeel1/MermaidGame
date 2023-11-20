// HarmlessFish.cpp
#include "harmlessfish.hpp"
#include <vector>

HarmlessFish::HarmlessFish(int x, int y) : Fish(x, y, 34, 17,247,265), frame(0) {
    // Set specific initial poses for HarmlessFish
    // Note: You can modify these values as needed
    srcRect = {247, 265, 34, 17};
}

HarmlessFish::~HarmlessFish() {
    // If there's any cleanup needed when a HarmlessFish object is destroyed, you can put it here.
}

void HarmlessFish::update() {
    // Update logic goes here (if needed)
    moverRect.x += 5;

    // Update the frame
    frame = (frame + 1) % 3; // Assuming 3 animation frames
}

void HarmlessFish::drawObjects(SDL_Renderer* renderer, SDL_Texture* assets) {
    // Set srcRect based on the current frame
    if (frame == 1) {
        srcRect = {199, 265, 34, 17};
    } else if (frame == 2) {
        srcRect = {151, 263, 33, 19};
    }

    // Draw logic goes here
    SDL_RenderCopy(renderer, assets, &srcRect, &moverRect);
}
void HarmlessFish::pushToVector() {
    // Push the current object to its own vector
    harmlessfishlist.push_back(*this);
}
