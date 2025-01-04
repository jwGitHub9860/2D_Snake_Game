#ifndef RENDERER_H
#define RENDERER_H

#include <mutex>  // defines "mutex"
#include <vector>
#include "SDL.h"
#include "snake.h"

using namespace std;

class Renderer {
 public:
  Renderer(const std::size_t &screen_width, const std::size_t &screen_height,
           const std::size_t &grid_width, const std::size_t &grid_height);
  ~Renderer();    // 1 : destructor

  Renderer(const Renderer &source);   // 2. copy constructor
  Renderer& operator=(const Renderer &source);   // 3. copy assignment operator
  Renderer(const Renderer &&source);   // 4. move constructor
  Renderer& operator=(const Renderer &&source);   // 5. move assignment operator

  void Render(Snake const snake, SDL_Point const &food, const uint8_t snakeBodyColorHex[4], const uint8_t snakeHeadColorHex[4], const uint8_t foodHexColor[4]);  // used to render Snake object & food to screen
  void UpdateWindowTitle(int score, int fps); // updates bar at top of game window with score & frames per second


  void createAndOpenWindow(); // opens game window AFTER user chooses snake body, head, and/or food colors
	

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  // MUST BE "size_t" NOT "const size_t" to USE CONSTRUCTOR
  size_t screen_width;
  size_t screen_height;
  size_t grid_width;
  size_t grid_height;

  
  mutex mtx;  // used for "lock_guard" to secure data
};

#endif