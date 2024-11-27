#ifndef RENDERER_H
#define RENDERER_H

#include <string>
#include <vector>
#include "SDL.h"
#include "snake.h"

using namespace std;

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(Snake const snake, SDL_Point const &food, unsigned char snakeBodyColorHex[4], unsigned char snakeHeadColorHex[4], unsigned char foodHexColor[4]);  // used to render Snake object & food to screen
  void UpdateWindowTitle(int score, int fps); // updates bar at top of game window with score & frames per second


  string snakeBodyColor = "white"; // initializes Snake Body Color choice
  string snakeHeadColor = "default blue"; // initializes Snake Head Color choice
  string foodColor = "yellow";  // initializes Food Color choice

  unsigned char snakeBodyColorHex[4] = { 0xFF, 0xFF, 0xFF, 0xFF }; // initializes Snake Body Color Hex to default color (white)        "unsigned char" ----> holds values from 0 to 255 & covers hexadecimal values ranging from 0x00 to 0xFF
  unsigned char snakeHeadColorHex[4] = { 0x00, 0x7A, 0xCC, 0xFF }; // initializes Snake Head Color Hex to default color (default blue)        "unsigned char" ----> holds values from 0 to 255 & covers hexadecimal values ranging from 0x00 to 0xFF
  unsigned char foodHexColor[4] = { 0xFF, 0xCC, 0x00, 0xFF }; // initializes Food Color Hex to default color (yellow)        "unsigned char" ----> holds values from 0 to 255 & covers hexadecimal values ranging from 0x00 to 0xFF

  unsigned char ColorWordToHex(string ChoosenColor); // translates Word color into Hex color
  void ColorChoice(string colorPartChoice);  // allows user to change "Body", "Head", and/or "Food"

  vector<string> colorHolder{ snakeBodyColor, snakeHeadColor, foodColor };
	

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;


  string ChoosenColor = ""; // initializes Choosen Color
  unsigned char ChoosenHexColor[4] = {}; // initializes Choosen Hex Color

  vector<string> colorType{ "Body ", "Head ", "Food " };
  int num_loops = 1;
};

#endif