#include "color_translation.h"  // allows access to "unique_ptr" for INDIVIDUAL Snake Body, Snake Head, and Food Hex Values & "color_translation" move constructor
#include "renderer.h"
#include <memory>   // defines "unique_ptr"
#include <iostream>
#include <string>

using namespace std;

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);  // returns pointer stored in SDL renderer
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::Render(Snake const snake, SDL_Point const &food, unique_ptr<unsigned char[]> snakeBodyHexPtr_1, unique_ptr<unsigned char[]> snakeBodyHexPtr_2, unique_ptr<unsigned char[]> snakeBodyHexPtr_3, unique_ptr<unsigned char[]> snakeBodyHexPtr_4, unique_ptr<unsigned char[]> snakeHeadHexPtr_1, unique_ptr<unsigned char[]> snakeHeadHexPtr_2, unique_ptr<unsigned char[]> snakeHeadHexPtr_3, unique_ptr<unsigned char[]> snakeHeadHexPtr_4, unique_ptr<unsigned char[]> foodHexPtr_1, unique_ptr<unsigned char[]> foodHexPtr_2, unique_ptr<unsigned char[]> foodHexPtr_3, unique_ptr<unsigned char[]> foodHexPtr_4) {
  SDL_Rect block;
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF); // sets screen color to black
  SDL_RenderClear(sdl_renderer);

  // Render food
  SDL_SetRenderDrawColor(sdl_renderer, foodHexPtr_1, foodHexPtr_2, foodHexPtr_3, foodHexPtr_4); // sets Food Color to User's Color Choice or Default Yellow
  block.x = food.x * block.w;
  block.y = food.y * block.h;
  SDL_RenderFillRect(sdl_renderer, &block);

  // Render snake's body
  SDL_SetRenderDrawColor(sdl_renderer, snakeBodyHexPtr_1, snakeBodyHexPtr_2, snakeBodyHexPtr_3, snakeBodyHexPtr_4); // sets Snake Body Color to User's Color Choice or Default White
  for (SDL_Point const &point : snake.body) {
    block.x = point.x * block.w;
    block.y = point.y * block.h;
    SDL_RenderFillRect(sdl_renderer, &block);
  }

  // Render snake's head
  block.x = static_cast<int>(snake.head_x) * block.w;
  block.y = static_cast<int>(snake.head_y) * block.h;
  if (snake.alive) {
    SDL_SetRenderDrawColor(sdl_renderer, snakeHeadHexPtr_1, snakeHeadHexPtr_2, snakeHeadHexPtr_3, snakeHeadHexPtr_4); // sets Snake Head Color to User's Color Choice or Default Blue
  } else {
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF); // render Snake different color
  }
  SDL_RenderFillRect(sdl_renderer, &block);

  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int score, int fps) {
  std::string title{"Snake Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}

