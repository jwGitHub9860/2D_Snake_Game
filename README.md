# Snake Game Instructions: How to Play
* Move the snake using the arrow keys
* Move the snake to eat the food & grow
* Do NOT let the snake eat itself

## Code Structure Overview:
The program allows the user to play the Snake Game with the option of choosing the snake body, head, and food colors before playing the game.

## New Features Added with Output Explanation:
I added a new feature that gives the player the choice to change the snake body, head, and/or food colors.
The feature first displays the request in the terminal telling the user to choose if they want to change the body, head, and/or food colors. Next, the user types and enters their answer into the terminal. The answers are case insensitive. However, if the answer that the user entered is misspelled or not one of the following color options listed in the displayed request, the question will loop until the user enters a valid color. Next, the program either changes the colors or leaves the default colors depending on the user's answer. The game window will then pop up and the user can play the game.

## Rubric Points Addressed by Feature:
The player choice to change Snake and/or Food color(s)

#### <ins>Loops, Functions, I/O:</ins>
- reads data from "choosing_color_string.txt" text file telling the user to choose a color and outputs text to terminal
  - text file is accessed using a constant string variable 
- accepts user's answers as input uses it to answer the given questions
- uses vector called "colorHolder" as data structure to hold the strings of the food, snake body and head colors

<ins>Object Oriented Programming:</ins>
- involved adding 1 new class to project called "color_translation"
- all class functions in "color_translation" class and other functions of my own in the original files have comments explaining their effects while their names generalize them
- uses template in "main.cpp" file to obtain user's choice of what color or colors to specify

##### <ins>Memory Management:</ins>
- In the "color_translation" class, the first function, "ColorWordToHex()", uses the pass-by-references, "&ChoosenColor" and "&HexColorHolder", and the second function, "ColorChoice()", uses the pass-by-reference, &colorPartChoice.
- Resource Acquisition Is Initialization (RAII) is used when handling the "choosing_color_string.txt" file
- Both the "color_translation" and "renderer" classes have their destructor, copy constructor, copy assignment operator, move constructor, and move assignment operator defined, making the project follow the Rule of 5.

###### <ins>Concurrency:</ins>
- The project uses two threads to ensure that the user is able to choose whether they want to change the given game colors or not before the game window pops up for them to play.
- A lock guard is used to protect the hex values 

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
