// KillerFish.hpp
#ifndef KILLERFISH_HPP
#define KILLERFISH_HPP

#include "fish.hpp"
#include <vector>

class KillerFish : public Fish {
public:
    KillerFish(int x, int y);
    ~KillerFish(); 

    void update(); // Override the virtual functions from the base class
    void drawObjects(SDL_Renderer* renderer, SDL_Texture* assets);

    // void addToVector(int x, int y); // Function to add to the vector
    // void updateVector(); // Function to update the vector

private:
    
    int frame;
    void pushToVector();
    std::vector<KillerFish> killerFishList;
};

#endif // KILLERFISH_HPP

// #ifndef KILLERFISH_HPP
// #define KILLERFISH_HPP

// #include <SDL.h>

// class KillerFish {
// public:
//     KillerFish(int x, int y);
//     ~KillerFish(); 
//     void update();
//     void draw(SDL_Renderer* renderer, SDL_Texture* assets);

// private:
//     SDL_Rect srcRect;
//     SDL_Rect moverRect;
//     int frame;
// };
/***class KillerFish {
public:
    KillerFish(int x, int y);
    ~KillerFish(); // Destructor (if needed, you can leave it empty)

    void update();
    void draw(SDL_Renderer* renderer, SDL_Texture* assets);

private:
    SDL_Rect srcRect;
    SDL_Rect moverRect;
    int frame;
};
**/

// #endif // KILLERFISH_HPP
