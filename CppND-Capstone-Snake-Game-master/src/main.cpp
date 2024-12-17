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

  // TEST VARIABLES FOR CONSTRUCTOR INPUT
  //const size_t kHexHolderSize{4}; // size of Hex array holders
  const string filename = "choosing_color_string.txt"; // accesses "choosing_color_string.txt" file
  unsigned char kDefaultHexBodyColor[4]{ 0xFF, 0xFF, 0xFF, 0xFF }; // default size of "snakeBodyColorHex"
  unsigned char kDefaultHexHeadColor[4]{ 0x00, 0x7A, 0xCC, 0xFF }; // default size of "snakeHeadColorHex"
  unsigned char kDefaultHexFoodColor[4]{ 0xFF, 0xCC, 0x00, 0xFF }; // default size of "foodHexColor"

  // TEST POINTERS FOR CONSTRUCTOR INPUT
  /*unsigned char* testkDefaultBodyPtr = kDefaultHexBodyColor[4];  // MUST INCLUDE [4]
  unsigned char* testkDefaultHexHeadColor = kDefaultHexHeadColor[4];  // MUST INCLUDE [4]
  unsigned char* testkDefaultHexFoodColor = kDefaultHexFoodColor[4];  // MUST INCLUDE [4]*/

  string choice = ""; // initializes Snake Color Change choice; limits to ONLY "main.cpp"

  cout << "Please choose whether you want to specify the snake's body, head, and/or food colors? (Body, Head, Food, Whole Snake, All, or None)\n";
  getline(cin, choice); // includes MORE THAN 1 word
  transform(choice.begin(), choice.end(), choice.begin(), [](unsigned char c){ return tolower(c); });  // sets "choice" to lowercase, makes "choice" case insensitive
  
  while (choice != "none")
  {
    cout << "Please choose one of the following options (Body, Head, Food, Whole Snake, All, or None): ";
    getline(cin, choice); // includes MORE THAN 1 word
    transform(choice.begin(), choice.end(), choice.begin(), [](unsigned char c){ return tolower(c); });  // sets "choice" to lowercase, makes "choice" case insensitive
  }

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);  // creates Renderer object
  Controller controller;  // creates Controller object
  Game game(kGridWidth, kGridHeight); // creates Game object
  //color_translation colorTranslation();  // creates Color_Translation object
  //color_translation colorTranslation(kHexHolderSize);  // creates Color_Translation object
  color_translation colorTranslation(kDefaultHexBodyColor, kDefaultHexHeadColor, kDefaultHexFoodColor, filename);  // creates Color_Translation object
  //color_translation colorTranslation(kDefaultHexBodyColor[4], kDefaultHexHeadColor[4], kDefaultHexFoodColor[4]);  // creates Color_Translation object
  //color_translation colorTranslation(testkDefaultBodyPtr, testkDefaultHexHeadColor, testkDefaultHexFoodColor);  // creates Color_Translation object
  game.Run(controller, renderer, kMsPerFrame, colorTranslation, choice);  // starts game loop   ADDED "choice" AS MY OWN CODE (delete comment later?)
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}