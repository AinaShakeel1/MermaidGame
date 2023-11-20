// // mermaid.cpp

// #include "Mermaid.hpp"
// #include "util.hpp"

// Mermaid::Mermaid()
//     : mermaidTexture(nullptr), mermaidRenderer(nullptr), x(0), y(0), speed(5)
// {
// }

// Mermaid::~Mermaid()
// {
//     SDL_DestroyTexture(mermaidTexture);
// }

// void Mermaid::init(SDL_Renderer* renderer, int initialX, int initialY)
// {
//     mermaidRenderer = renderer;
//     mermaidTexture = loadTexture("mermaid.jpg"); // Load your mermaid texture
//     x = initialX;
//     y = initialY;
// }

// void Mermaid::handleEvent(const SDL_Event& e)
// {
//     if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RIGHT)
//     {
//         // Handle other events if needed
//     }
// }

// void Mermaid::move()
// {
//     // Move the mermaid to the right
//     x += speed;
// }

// void Mermaid::draw()
// {
//     SDL_Rect destRect = { x, y, /* width */, /* height */ }; // Adjust width and height accordingly
//     SDL_RenderCopy(mermaidRenderer, mermaidTexture, nullptr, &destRect);
// }
