#include <iostream>
#include <string> // defines "string choice"
#include <algorithm>  // defines "transform"
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "snake.h"  // allows access to "SnakeColor()" function

using namespace std;

int main() {
  // Constant Expression definitions
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond}; // computes ms per frame
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  string choice = ""; // initializes Snake Color Change choice; limits to ONLY "main.cpp"

  cout << "Please choose whether you want to specify the snake's body, head, and/or food colors? (Body, Head, Food, Whole Snake, All, or None)" << endl;
  getline(cin, choice); // includes MORE THAN 1 word
  transform(choice.begin(), choice.end(), choice.begin(), [](unsigned char c){ return tolower(c); });  // sets "choice" to lowercase, makes "choice" case insensitive
  
  while (choice != "none")
  {
    if (choice == "body" || choice == "whole snake" || choice == "all")
    {
      cout << "Choose the Body Color (Red, Orange, Yellow, Green, Blue, Indigo, Violet, Dark Red, Dark Orange, Goldenrod, Light Green, Light Blue, Pink and Dark Violet): ";
      getline(cin, Snake::snakeBodyColor); // includes MORE THAN 1 word
      Snake::snakeBodyColor = transform(Snake::snakeBodyColor.begin(), Snake::snakeBodyColor.end(), Snake::snakeBodyColor.begin(), [](unsigned char c){ return tolower(c); });  // sets "snakeBodyColor" to lowercase, makes "snakeBodyColor" case insensitive
      Snake::snakeBodyColorHex = Snake::ColorWordToHex(Snake::snakeBodyColor);  // obtains chosen Body color
      if (choice == "body")
      {
        break;
      }
      else
			{
				cout << endl;
			}
    }
    if (choice == "head" || choice == "whole snake" || choice == "all")
    {
      cout << "Choose the Head Color (Red, Orange, Yellow, Green, Blue, Indigo, Violet, Dark Red, Dark Orange, Goldenrod, Light Green, Light Blue, Pink and Dark Violet): ";
      getline(cin, Snake::snakeHeadColor); // includes MORE THAN 1 word
      Snake::snakeHeadColor = transform(Snake::snakeHeadColor.begin(), Snake::snakeHeadColor.end(), Snake::snakeHeadColor.begin(), [](unsigned char c){ return tolower(c); });  // sets "snakeHeadColor" to lowercase, makes "snakeHeadColor" case insensitive
      Snake::snakeHeadColorHex = Snake::ColorWordToHex(Snake::snakeHeadColor);  // obtains chosen Head color
      if (choice != "all")
			{
				break;
			}
      else
			{
				cout << endl;
			}
    }
    if (choice == "food" || choice == "all")
    {
      cout << "Choose the Food Color (Red, Orange, Yellow, Green, Blue, Indigo, Violet, Dark Red, Dark Orange, Goldenrod, Light Green, Light Blue, Pink and Dark Violet): ";
      getline(cin, Snake::foodColor); // includes MORE THAN 1 word
      Snake::foodColor = transform(Snake::foodColor.begin(), Snake::foodColor.end(), Snake::foodColor.begin(), [](unsigned char c){ return tolower(c); });  // sets "foodColor" to lowercase, makes "foodColor" case insensitive
      Snake::foodHexColor = Snake::ColorWordToHex(Snake::foodColor);  // obtains chosen Food color
      cout << endl;
      break;
    }
    else
    {
      cout << "Please choose one of the following options (Body, Head, Food, Whole Snake, All, or None): ";
      cin >> choice;
      transform(choice.begin(), choice.end(), choice.begin(), [](unsigned char c){ return tolower(c); });  // sets "choice" to lowercase, makes "choice" case insensitive
    }
  }

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);  // creates Renderer object
  Controller controller;  // creates Controller object
  Game game(kGridWidth, kGridHeight); // creates Game object
  game.Run(controller, renderer, kMsPerFrame);  // starts game loop
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}