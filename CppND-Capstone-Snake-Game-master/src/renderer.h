#ifndef RENDERER_H
#define RENDERER_H

#include <memory>   // defines "unique_ptr"
#include <vector>
#include "color_translation.h"  // allows access to "unique_ptr" for INDIVIDUAL Snake Body, Snake Head, and Food Hex Values & "color_translation" move constructor
#include "SDL.h"
#include "snake.h"

using namespace std;

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();    // 1 : destructor

  void Render(Snake const snake, SDL_Point const &food, unique_ptr<unsigned char[]> snakeBodyHexPtr_1, unique_ptr<unsigned char[]> snakeBodyHexPtr_2, unique_ptr<unsigned char[]> snakeBodyHexPtr_3, unique_ptr<unsigned char[]> snakeBodyHexPtr_4, unique_ptr<unsigned char[]> snakeHeadHexPtr_1, unique_ptr<unsigned char[]> snakeHeadHexPtr_2, unique_ptr<unsigned char[]> snakeHeadHexPtr_3, unique_ptr<unsigned char[]> snakeHeadHexPtr_4, unique_ptr<unsigned char[]> foodHexPtr_1, unique_ptr<unsigned char[]> foodHexPtr_2, unique_ptr<unsigned char[]> foodHexPtr_3, unique_ptr<unsigned char[]> foodHexPtr_4);  // used to render Snake object & food to screen
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