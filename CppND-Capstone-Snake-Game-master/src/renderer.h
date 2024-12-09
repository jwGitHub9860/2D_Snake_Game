#ifndef RENDERER_H
#define RENDERER_H

#include <memory>   // defines "unique_ptr"
#include <string>
#include <vector>
#include "SDL.h"
#include "color_translation.h"  // allows access to MAIN "unique_ptr" & "color_translation" move constructor
#include "snake.h"

using namespace std;

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();    // 1 : destructor

  void Render(Snake const snake, SDL_Point const &food, unsigned char snakeBodyColorHex[4], unsigned char snakeHeadColorHex[4], unsigned char foodHexColor[4]);  // used to render Snake object & food to screen
  void UpdateWindowTitle(int score, int fps); // updates bar at top of game window with score & frames per second


  //unique_ptr<unsigned char[]> rendererBodyHexPtr; //= move(snakeBodyColorHex[4]);  // Renderer "unique_ptr" (2nd) TEMPORARY
  //unique_ptr<unsigned char[]> rendererHeadHexPtr; //= move(snakeHeadColorHex[4]);  // Renderer "unique_ptr" (2nd)  TEMPORARY
  //unique_ptr<unsigned char[]> rendererFoodHexPtr; //= move(color_translationFoodHexPtr);       // Renderer "unique_ptr" (2nd)  TEMPORARY
	

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;


  
};

#endif