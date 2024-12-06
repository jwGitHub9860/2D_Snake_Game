#ifndef RENDERER_H
#define RENDERER_H

#include <memory>   // defines "unique_ptr"
#include <string>
#include <vector>
#include "SDL.h"
#include "snake.h"

using namespace std;

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();    // 1 : destructor

  void Render(Snake const snake, SDL_Point const &food, unsigned char snakeBodyColorHex[], unsigned char snakeHeadColorHex[], unsigned char foodHexColor[]);  // used to render Snake object & food to screen
  void UpdateWindowTitle(int score, int fps); // updates bar at top of game window with score & frames per second


  
	

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;


  
};

#endif