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


  string snakeBodyColor = "white"; // initializes Snake Body Color choice
  string snakeHeadColor = "default blue"; // initializes Snake Head Color choice
  string foodColor = "yellow";  // initializes Food Color choice

  unsigned char snakeBodyColorHex[] = { 0xFF, 0xFF, 0xFF, 0xFF }; // initializes Snake Body Color Hex to default color (white)        "unsigned char" ----> holds values from 0 to 255 & covers hexadecimal values ranging from 0x00 to 0xFF
  unsigned char snakeHeadColorHex[] = { 0x00, 0x7A, 0xCC, 0xFF }; // initializes Snake Head Color Hex to default color (default blue)        "unsigned char" ----> holds values from 0 to 255 & covers hexadecimal values ranging from 0x00 to 0xFF
  unsigned char foodHexColor[] = { 0xFF, 0xCC, 0x00, 0xFF }; // initializes Food Color Hex to default color (yellow)        "unsigned char" ----> holds values from 0 to 255 & covers hexadecimal values ranging from 0x00 to 0xFF

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


  string line;  // used to access text in "choosing_color_string.txt" file
  string ChoosenColor = ""; // initializes Choosen Color
  unsigned char ChoosenHexColor[] = { 0xFF, 0xFF, 0xFF, 0xFF }; // initializes Choosen Hex Color     NEED CHANGING? [] to [4] (neccesary?)    Default values (white)

  vector<string> colorType{ "Body ", "Head ", "Food " };
  int num_loops = 1;
};

#endif