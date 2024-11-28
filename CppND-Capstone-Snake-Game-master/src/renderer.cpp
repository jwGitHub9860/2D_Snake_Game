#include "renderer.h"
#include "snake.h"  // allows access to "Color" result
#include <fstream>
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

void Renderer::Render(Snake const snake, SDL_Point const &food, unsigned char snakeBodyColorHex[4], unsigned char snakeHeadColorHex[4], unsigned char foodHexColor[4]) {
  SDL_Rect block;
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF); // sets screen color to black
  SDL_RenderClear(sdl_renderer);

  // Render food
  SDL_SetRenderDrawColor(sdl_renderer, foodHexColor[4]); // sets screen color to yellow
  block.x = food.x * block.w;
  block.y = food.y * block.h;
  SDL_RenderFillRect(sdl_renderer, &block);

  // Render snake's body
  SDL_SetRenderDrawColor(sdl_renderer, snakeBodyColorHex[4]); // sets screen color to white
  for (SDL_Point const &point : snake.body) {
    block.x = point.x * block.w;
    block.y = point.y * block.h;
    SDL_RenderFillRect(sdl_renderer, &block);
  }

  // Render snake's head
  block.x = static_cast<int>(snake.head_x) * block.w;
  block.y = static_cast<int>(snake.head_y) * block.h;
  if (snake.alive) {
    SDL_SetRenderDrawColor(sdl_renderer, snakeHeadColorHex[4]); // render Snake 1 color
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

unsigned char Renderer::ColorWordToHex(string ChoosenColor) // translates Word color into Hex color
{
  if (ChoosenColor == "red")
  {
    ChoosenHexColor[4] = { 0xFF, 0x0, 0x0, 0xFF };
    return ChoosenHexColor[4];
  }
  else if (ChoosenColor == "orange")
  {
    ChoosenHexColor[4] = { 0xFF, 0xA5, 0x0, 0xFF };
    return ChoosenHexColor[4];
  }
  else if (ChoosenColor == "yellow")
  {
    return ChoosenHexColor[4] = { 0xFF, 0xCC, 0x00, 0xFF }; // Default Food color
  }
  else if (ChoosenColor == "green")
  {
    return ChoosenHexColor[4] = { 0x00, 0x80, 0x00, 0xFF };
  }
  else if (ChoosenColor == "blue")
  {
    return ChoosenHexColor[4] = { 0x00, 0x00, 0xFF, 0xFF };
  }
  else if (ChoosenColor == "indigo")
  {
    return ChoosenHexColor[4] = { 0x4B, 0x00, 0x82, 0xFF };
  }
  else if (ChoosenColor == "violet")
  {
    return ChoosenHexColor[4] = { 0xEE, 0x82, 0xEE, 0xFF };
  }
  else if (ChoosenColor == "dark red")
  {
    return ChoosenHexColor[4] = { 0x8B, 0x00, 0x00, 0xFF };
  }
  else if (ChoosenColor == "dark orange")
  {
    return ChoosenHexColor[4] = { 0xFF, 0x8C, 0x00, 0xFF };
  }
  else if (ChoosenColor == "goldenrod")
  {
    return ChoosenHexColor[4] = { 0xDA, 0xA5, 0x20, 0xFF };
  }
  else if (ChoosenColor == "light green")
  {
    return ChoosenHexColor[4] = { 0x90, 0xEE, 0x90, 0xFF };
  }
  else if (ChoosenColor == "light blue")
  {
    return ChoosenHexColor[4] = { 0xAD, 0xD8, 0xE6, 0xFF };
  }
  else if (ChoosenColor == "pink")
  {
    return ChoosenHexColor[4] = { 0xFF, 0xC0, 0xCB, 0xFF };
  }
  else if (ChoosenColor == "dark violet")
  {
    return ChoosenHexColor[4] = { 0x94, 0x00, 0xD3, 0xFF };
  }
  else if (ChoosenColor == "white") // Default snake Body color
  {
    return ChoosenHexColor[4] = { 0xFF, 0xFF, 0xFF, 0xFF };
  }
  else if (ChoosenColor == "default blue")  // Default snake Head color
  {
    return ChoosenHexColor[4] = { 0x00, 0x7A, 0xCC, 0xFF };
  }
}

void Renderer::ColorChoice(string colorPartChoice)   // allows user to change "Body", "Head", and/or "Food"
{	
	if (colorPartChoice == "body" || colorPartChoice == "head" || colorPartChoice == "food")
	{
		num_loops = 1;
	}
	if (colorPartChoice == "whole snake")
	{
		num_loops = 2;
	}
	if (colorPartChoice == "all")
	{
		num_loops = 3;
	}

	for (int i = 0; i < num_loops; i++)
	{
		int j = i;
		if (colorPartChoice == "head")
		{
			j = 1;
		}
		if (colorPartChoice == "food")
		{
			j = 2;
		}
		
    ifstream stream("choosing_color_string.txt"); // accesses "choosing_color_string.txt" file
    if (stream.open())
    {
      while (getline(stream, line))  // accesses text inside "choosing_color_string.txt" file & stores in "line"
      {
        line.insert(11, colorType[j]);
        cout << line;
      }
      stream.close();
    }
    else
    {
      cout << "Text file failed to open.\n";
    }
		getline(cin, colorHolder[j]); // includes MORE THAN 1 word
		transform(colorHolder[j].begin(), colorHolder[j].end(), colorHolder[j].begin(), [](unsigned char c) { return tolower(c); });  // sets "snakeBodyColor", "snakeHeadColor", and/or "foodColor" to lowercase, makes case insensitive
	}
  snakeBodyColorHex[4] = ColorWordToHex(colorHolder[0]);  // obtains chosen Body color
  snakeHeadColorHex[4] = ColorWordToHex(colorHolder[1]);  // obtains chosen Head color
  foodHexColor[4] = ColorWordToHex(colorHolder[2]);  // obtains chosen Food color
}