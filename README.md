# Snake Game Instructions: How to Play

* Move the snake to eat the food & grow
* Move the snake using the arrow keys
* Do NOT let the snake eat itself

## Code Structure Overview:


## New Features paragraph:
* Give player choice to change Snake and/or Food color(s)

## Rubric Submission Explaination:
The player choice to change Snake and/or Food color(s)
- reads data from "choosing_color_string.txt" text file telling the user to choose a color and outputs text to terminal
- accepts user's answers as input uses it to answer the given questions
- uses vector called "colorHolder" as data structure to hold the strings of the food, snake body and head colors
- STILL NEEDS CONSTANT VARIABLES
- 

## New Features added:
# Options [delete later]
* Allow players to enter their names and save their high scores to a text file.
* Add fixed and moving obstacles to the game.
* Add different types of food to the game.
* Allow players to select the initial speed of the game.
* Add another snake to the game that is controlled by the computer using the A* search algorithm.


## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build & Run Instructions

1. Clone this [repo](https://github.com/udacity/CppND-Capstone-Snake-Game).
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
