// HarmlessFish.hpp
#ifndef HARMLESSFISH_HPP
#define HARMLESSFISH_HPP

#include "fish.hpp"

class HarmlessFish : public Fish {
public:
    HarmlessFish(int x, int y);
    ~HarmlessFish() ; // Override the destructor if necessary
    void update() ;   // Override the update method
    void drawObjects(SDL_Renderer* renderer, SDL_Texture* assets) ; // Override the draw method

private:
    int frame;
    void pushToVector() ;
    std::vector<HarmlessFish>harmlessfishlist;
};

#endif // HARMLESSFISH_HPP
