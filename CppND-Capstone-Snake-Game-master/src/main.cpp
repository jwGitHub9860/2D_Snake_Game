#include <iostream>
#include <string> // defines "string choice" & "string filename"
#include <algorithm>  // defines "transform"
#include <fstream>  // defines "ifstream"
#include "color_translation.h"  // allows "colorTranslation()" object to be created
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
  const string filename = "../src/choosing_color_string.txt"; // accesses "choosing_color_string.txt" file

  string choice = ""; // initializes Snake Color Change choice; limits to ONLY "main.cpp"

  cout << "Please choose whether you want to specify the snake's body, head, and/or food colors? (Body, Head, Food, Whole Snake, All, or None)\n";
  getline(cin, choice); // includes MORE THAN 1 word
  transform(choice.begin(), choice.end(), choice.begin(), [](unsigned char c){ return tolower(c); });  // sets "choice" to lowercase, makes "choice" case insensitive
  
  while (choice != "body" && choice != "head" && choice != "food" && choice != "whole snake" && choice != "all" && choice != "none")
  {
    cout << "Please choose one of the following options (Body, Head, Food, Whole Snake, All, or None): ";
    getline(cin, choice); // includes MORE THAN 1 word
    transform(choice.begin(), choice.end(), choice.begin(), [](unsigned char c){ return tolower(c); });  // sets "choice" to lowercase, makes "choice" case insensitive
  }

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);  // creates Renderer object
  Controller controller;  // creates Controller object
  Game game(kGridWidth, kGridHeight); // creates Game object
  color_translation colorTranslation(filename);  // creates Color_Translation object
  game.Run(controller, renderer, kMsPerFrame, colorTranslation, choice);  // starts game loop   ADDED "choice" AS MY OWN CODE (delete comment later?)
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}