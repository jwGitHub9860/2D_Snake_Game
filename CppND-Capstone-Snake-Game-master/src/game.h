#ifndef GAME_H
#define GAME_H

#include <random>
#include <memory> // defines "unique_ptr"
#include "SDL.h"
#include "color_translation.h"  // allows access to MAIN "unique_ptr" & "color_translation" move constructor
#include "controller.h"
#include "renderer.h"
#include "snake.h"

using namespace std;

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,  // calls game loop to start
           std::size_t target_frame_duration, color_translation &colorTranslation, string colorPartChoice);  // ADDED "colorPartChoice" & "&colorTranslation" AS MY OWN CODE (delete comment later?)
  int GetScore() const;
  int GetSize() const;


  string colorPartChoice = ""; // initializes Snake Color Change choice; "game.cpp" & "main.cpp" USE IT
  unique_ptr<unsigned char[]> gameBodyHexPtr = make_unique<unsigned char[]>(4);   // Game "unique_ptr" (1st)
  unique_ptr<unsigned char[]> gameHeadHexPtr = make_unique<unsigned char[]>(4);   // Game "unique_ptr" (1st)
  unique_ptr<unsigned char[]> gameFoodHexPtr = make_unique<unsigned char[]>(4);   // Game "unique_ptr" (1st)


 private:
  Snake snake;  // stores Snake object
  SDL_Point food; // SDL point - struct that has X & Y coordinates

  // random numbers used to place food
  std::random_device dev; // random number generator
  std::mt19937 engine;  // random number engine based on Mersenne Twister algorithm     produces high-quality unsigned integer random numbers
  std::uniform_int_distribution<int> random_w;  // limits random numbers for grid
  std::uniform_int_distribution<int> random_h;  // limits random numbers for grid

  int score{0}; // initial game score

  void PlaceFood();
  void Update();
};

#endif