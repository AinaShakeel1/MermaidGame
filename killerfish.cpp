// KillerFish.cpp
#include "killerfish.hpp"
#include <vector>

KillerFish::KillerFish(int x, int y) : Fish(x, y, 50, 50,201,97), frame(0) {
    // Set initial pose
    srcRect = {201, 97, 49, 39};
}

KillerFish::~KillerFish() {
    // If there's any cleanup needed when a KillerFish object is destroyed, you can put it here.
}

void KillerFish::update() {
    // Update logic goes here (if needed)
    moverRect.x += 5;

    // Update the frame
    frame = (frame + 1) % 3;

    // Update the vector
   
}

void KillerFish::drawObjects(SDL_Renderer* renderer, SDL_Texture* assets)  {
    // Set srcRect based on the current frame
    if (frame == 1) {
        srcRect = {257, 98, 61, 38};
    } else if (frame == 2) {
        srcRect = {320, 98, 62, 38};
    }

    SDL_RenderCopy(renderer, assets, &srcRect, &moverRect);

    // Draw the objects from the vector
    // for (const auto& fishRect : fishVector) {
    //     SDL_RenderCopy(renderer, assets, &srcRect, &fishRect);
    // }
}

// void KillerFish::addToVector(int x, int y) {
//     // Add new coordinates to the vector
//     SDL_Rect newRect = {x, y, 50, 50}; // Adjust the size as needed
//     //fishVector.push_back(newRect);
// }

// void KillerFish::updateVector() {
//     // Update logic for the vector, if needed
// }
void KillerFish::pushToVector() {
    // Push the current object to its own vector
    killerFishList.push_back(*this);
}

// // KillerFish.cpp
// #include "KillerFish.hpp"

// KillerFish::KillerFish(int x, int y) : frame(0) {
//     // Set initial pose
//     srcRect = {201, 97, 49, 39};
//     moverRect = {x, y, 50, 50}; // Specific coordinates and size
// }

// KillerFish::~KillerFish() {
//     // If there's any cleanup needed when a KillerFish object is destroyed, you can put it here.
// }

// void KillerFish::update() {
//     // Update logic goes here (if needed)
//     moverRect.x += 5;

//     // Update the frame
//     frame = (frame + 1) % 3;
// }

// void KillerFish::draw(SDL_Renderer* renderer, SDL_Texture* assets) {
//     // Set srcRect based on the current frame
//     if (frame == 1) {
//         srcRect = {257, 98, 61, 38};
//     } else if (frame == 2) {
//         srcRect = {320, 98, 62, 38};
//     }

//     SDL_RenderCopy(renderer, assets, &srcRect, &moverRect);
// }
