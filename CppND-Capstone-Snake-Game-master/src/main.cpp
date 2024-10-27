#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

int main() {
  // Constant Expression definitions
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond}; // computes ms per frame
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);  // creates Renderer object
  Controller controller;  // creates Controller object
  Game game(kGridWidth, kGridHeight); // creates Game object
  game.Run(controller, renderer, kMsPerFrame);  // starts game loop
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}