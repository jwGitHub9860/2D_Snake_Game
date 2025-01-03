#include "color_translation.h"  // allows access to "unique_ptr" for INDIVIDUAL Snake Body, Snake Head, and Food Hex Values & "color_translation" move constructor
#include "renderer.h"
//#include <memory>   // defines "unique_ptr"
#include <iostream>
#include <string>

using namespace std;

Renderer::Renderer(const std::size_t &screen_width,
                   const std::size_t &screen_height,
                   const std::size_t &grid_width, const std::size_t &grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) {
  // Initialize SDL     ORIGINAL FUNCTION CODE
  /*if (SDL_Init(SDL_INIT_VIDEO) < 0) {
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
  }*/  // ORIGINAL FUNCTION CODE

  

  
}

Renderer::~Renderer() {   // 1. destructor
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

Renderer::Renderer(const Renderer &source)   // 2. copy constructor
{
  screen_width = source.screen_width; // creates copy of "screen_width" from source
  screen_height = source.screen_height; // creates copy of "screen_height" from source
  grid_width = source.grid_width; // creates copy of "grid_width" from source
  grid_height = source.grid_height; // creates copy of "grid_height" from source
}

Renderer &Renderer::operator=(const Renderer &source)   // 3. copy assignment operator
{
  if (this != &source)  // protects against self assignment
  {
    screen_width = source.screen_width; // creates copy of "screen_width" from source
    screen_height = source.screen_height; // creates copy of "screen_height" from source
    grid_width = source.grid_width; // creates copy of "grid_width" from source
    grid_height = source.grid_height; // creates copy of "grid_height" from source
  }
  return *this;   // returns reference to current object
}

Renderer::Renderer(const Renderer &&source) : screen_width(move(screen_width)), screen_height(move(screen_height)), grid_width(move(grid_width)), grid_height(move(grid_height)) {}   // 4. move constructor

Renderer &Renderer::operator=(const Renderer &&source)   // 5. move assignment operator
{
  if (this != &source)  // protects against self-assignment
  {
    screen_width = move(screen_width);  // moves SOURCE "screen_width" into "screen_width"
    screen_height = move(screen_height);  // moves SOURCE "screen_height" into "screen_height"
    grid_width = move(grid_width);  // moves SOURCE "grid_width" into "grid_width"
    grid_height = move(grid_height);  // moves SOURCE "grid_height" into "grid_height"
  }
  return *this;   // returns reference to current object
}

void Renderer::Render(Snake const snake, SDL_Point const &food, const uint8_t snakeBodyColorHex[4], const uint8_t snakeHeadColorHex[4], const uint8_t foodHexColor[4]) {
  SDL_Rect block;
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF); // sets screen color to black
  SDL_RenderClear(sdl_renderer);

  // Render food
  SDL_SetRenderDrawColor(sdl_renderer, foodHexColor[0], foodHexColor[1], foodHexColor[2], foodHexColor[3]); // sets Food Color to User's Color Choice or Default Yellow
  block.x = food.x * block.w;
  block.y = food.y * block.h;
  SDL_RenderFillRect(sdl_renderer, &block);

  // Render snake's body
  SDL_SetRenderDrawColor(sdl_renderer, snakeBodyColorHex[0], snakeBodyColorHex[1], snakeBodyColorHex[2], snakeBodyColorHex[3]); // sets Snake Body Color to User's Color Choice or Default White
  for (SDL_Point const &point : snake.body) {
    block.x = point.x * block.w;
    block.y = point.y * block.h;
    SDL_RenderFillRect(sdl_renderer, &block);
  }

  // Render snake's head
  block.x = static_cast<int>(snake.head_x) * block.w;
  block.y = static_cast<int>(snake.head_y) * block.h;
  if (snake.alive) {
    SDL_SetRenderDrawColor(sdl_renderer, snakeHeadColorHex[0], snakeHeadColorHex[1], snakeHeadColorHex[2], snakeHeadColorHex[3]); // sets Snake Head Color to User's Color Choice or Default Blue
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

/**/void createAndOpenWindow()  // opens game window AFTER user chooses snake body, head, and/or food colors      PUT IN SEPARATE FUNCTION OR NOT???      ADDED "createAndOpenWindow()" function NOT Function Content AS MY OWN CODE (delete comment later?)
{
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
}/**/      