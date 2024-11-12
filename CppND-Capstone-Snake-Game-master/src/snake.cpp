#include "snake.h"
#include <cmath>
#include <iostream>
#include <string> // 

void Snake::Update() {
  SDL_Point prev_cell{
      static_cast<int>(head_x),
      static_cast<int>(
          head_y)};  // We first capture the head's cell before updating.
  UpdateHead();
  SDL_Point current_cell{
      static_cast<int>(head_x),
      static_cast<int>(head_y)};  // Capture the head's cell after updating.

  // Update all of the body vector items if the snake head has moved to a new
  // cell.
  if (current_cell.x != prev_cell.x || current_cell.y != prev_cell.y) {
    UpdateBody(current_cell, prev_cell);
  }
}

void Snake::UpdateHead() {  // holds direction of Snake
  switch (direction) {
    case Direction::kUp:
      head_y -= speed;
      break;

    case Direction::kDown:
      head_y += speed;
      break;

    case Direction::kLeft:
      head_x -= speed;
      break;

    case Direction::kRight:
      head_x += speed;
      break;
  }

  // Wrap the Snake around to the beginning if going off of the screen.
  head_x = fmod(head_x + grid_width, grid_width);
  head_y = fmod(head_y + grid_height, grid_height);
}

void Snake::UpdateBody(SDL_Point &current_head_cell, SDL_Point &prev_head_cell) { // body follows previous head position
  // Add previous head location to vector
  body.push_back(prev_head_cell);

  if (!growing) {
    // Remove the tail from the vector.
    body.erase(body.begin());
  } else {
    growing = false;
    size++;
  }

  // Check if the snake has died.
  for (auto const &item : body) {
    if (current_head_cell.x == item.x && current_head_cell.y == item.y) {
      alive = false;
    }
  }
}

void Snake::GrowBody() { growing = true; }

// Inefficient method to check if cell is occupied by snake.
bool Snake::SnakeCell(int x, int y) { // checks if food is in same cell as Snake head or body
  if (x == static_cast<int>(head_x) && y == static_cast<int>(head_y)) {
    return true;
  }
  for (auto const &item : body) {
    if (x == item.x && y == item.y) {
      return true;
    }
  }
  return false;
}

unsigned char ColorWordToHex(string ChoosenColor) // translates Word color into Hex color
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
    return ChoosenHexColor[4] = { 0xFF, 0xCC, 0x00, 0xFF };
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
}