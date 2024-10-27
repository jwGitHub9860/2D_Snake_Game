#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL.h"

class Snake {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight }; // Snake travel directions

  Snake(int grid_width, int grid_height)  // grid parameters
      : grid_width(grid_width),
        grid_height(grid_height),
        head_x(grid_width / 2), // initial X-coordinate position for Snake head (middle of screen)
        head_y(grid_height / 2) {}  // initial X-coordinate position for Snake head (middle of screen)

  void Update();  // Updating Snake method

  void GrowBody();  // grows Snake body
  bool SnakeCell(int x, int y); // boolean telling if some integers that are passed in are part of snake in grid

  Direction direction = Direction::kUp; // initial Snake traveling direction

  float speed{0.1f};  // initial Snake speed
  int size{1};  // initial Snake size
  bool alive{true}; // boolean representing if Snake is alive or not
  float head_x; // X-coordinate of Snake head
  float head_y; // Y-coordinate of Snake head
  std::vector<SDL_Point> body;  // vector of SDL points for Snake body  SDL point - struct that has X & Y coordinates

 private:
  void UpdateHead();  // updates coordinates head
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  bool growing{false};  // boolean telling whether Snake is growing
  int grid_width;
  int grid_height;
};

#endif