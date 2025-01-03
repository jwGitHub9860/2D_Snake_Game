#include "game.h"
#include <iostream>
#include <memory> // defines "unique_ptr"
#include <thread> // defines "thread"
#include "SDL.h"

using namespace std;

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),  // limits random numbers to 0 - 'grid max'
      random_h(0, static_cast<int>(grid_height - 1)) {  // limits random numbers to 0 - 'grid max'
  PlaceFood();  // places food on screen
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration, color_translation &colorTranslation, string colorPartChoice) { // USES "using namespace std" ADDED "colorPartChoice" & "&colorTranslation" AS MY OWN CODE (delete comment later?)
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks(); // records start of frame (timestamp)
    
    if (colorPartChoice != "none")  // checks if user chose not to change any colors 
    {
      thread choosingColorThread(&color_translation::ColorChoice, &colorTranslation, ref(colorPartChoice)); // 1st thread calling "ColorChoice" function      MUST CONFIRM "colorPartChoice" Is Reference USING "ref()"
      choosingColorThread.join();  // WAITS for "choosingColorThread" to Finish BEFORE program exits
    }
    
    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(snake, food, colorTranslation.snakeBodyColorHex, colorTranslation.snakeHeadColorHex, colorTranslation.foodHexColor);  // ADDED IN MY OWN (delete comment later?)

    if (closedWindow) // checks if game window is already open
    {
      thread windowThread(&Renderer::createAndOpenWindow, &renderer);  // opens game window AFTER user chooses snake body, head, and/or food colors      ADDED "createAndOpenWindow()" function NOT Function Content AS MY OWN CODE (delete comment later?)
      windowThread.join();  // WAITS for thread to Finish BEFORE program exits      ADDED LINE AS MY OWN CODE (delete comment later?)
      closedWindow = false;  // indicates that game window is OPEN
    }
    
    frame_end = SDL_GetTicks(); // records end of frame (timestamp)

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;  // reset to 0
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) { // checks if random numbers are in Snake location
      food.x = x;
      food.y = y;
      return;
    }
  }
}

void Game::Update() {
  if (!snake.alive) return;

  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's food over here
  if (food.x == new_x && food.y == new_y) {
    score++;
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.02;
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }