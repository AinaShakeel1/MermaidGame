// fish.hpp
#ifndef FISH_HPP
#define FISH_HPP

#include <SDL.h>
// #include "killerfish.hpp"
// #include "harmlessfish.hpp"
#include <vector>
class Fish {
public:
    Fish(int x, int y, int width, int height,int x_sor,int y_sor);
    virtual ~Fish(); // Make the destructor virtual for proper polymorphic behavior

    virtual void update(); // Make the update method virtual for polymorphism
    virtual void drawObjects(SDL_Renderer* renderer, SDL_Texture* assets);
    //virtual void drawObjects();
    virtual void createObject(int x, int y);
protected:
    SDL_Rect srcRect;
    SDL_Rect moverRect;
    virtual void pushToVector() = 0;
    // std::vector<HarmlessFish> harmlessFishList; 
    // std::vector<KillerFish> killerFishList;
    // std::vector<HarmlessFish>harmlessfislist;
    //int frame;
};

#endif // FISH_HPP
