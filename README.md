# Snake Game Instructions: How to Play

* Move the snake to eat the food & grow
* Move the snake using the arrow keys
* Do NOT let the snake eat itself

## Code Structure Overview:


## New Features paragraph:
* Gives player choice to change Snake and/or Food color(s)

## Rubric Submission Explanation:
The player choice to change Snake and/or Food color(s)

Loops, Functions, I/O:
- reads data from "choosing_color_string.txt" text file telling the user to choose a color and outputs text to terminal
  - text file is accessed using a constant string variable 
- accepts user's answers as input uses it to answer the given questions
- uses vector called "colorHolder" as data structure to hold the strings of the food, snake body and head colors

Object Oriented Programming:
- involved adding 1 new class to project called "color_translation"
- all class functions in "color_translation" class and other functions of my own in the original files have comments explaining their effects while their names generalize them
- 

Memory Management:
- In the "color_translation" class, the first function, "ColorWordToHex()", uses the pass-by-references, "&ChoosenColor" and "&HexColorHolder", and the second function, "ColorChoice()", uses the pass-by-reference, &colorPartChoice.
- Resource Acquisition Is Initialization (RAII) is used when handling the "choosing_color_string.txt" file
- Both the "color_translation" and "renderer" classes have their destructor, copy constructor, copy assignment operator, move constructor, and move assignment operator defined, making the project follow the Rule of 5.

Concurrency:
- 
- 
- 

## New Features added:
I added a feature that gives the user the choice to change the snake body, head, and/or food colors. The feature displays the question in the terminal asking the user if they want to change the body, head, and/or food colors. Next, the user types and enters their answer into the terminal. The answers are case insensitive. However, if the answer that the user entered is not one of the following color options listed in the displayed question or misspelled, the question will loop until the user enters a valid color. Next, the program either changes or leaves the colors depending on the user's answer.

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
