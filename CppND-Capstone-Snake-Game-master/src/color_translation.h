#ifndef COLOR_TRANSLATION_H
#define COLOR_TRANSLATION_H

#pragma once

#include <fstream>
#include <iostream>
//#include <memory>   // defines "unique_ptr"
#include <string>
#include <vector>
#include "SDL.h"
//#include "controller.h"   // (DO I NEED IT?)
//#include "game.h"         // (DO I NEED IT?)
//#include "renderer.h"     // (DO I NEED IT?)
//#include "snake.h"        // (DO I NEED IT?)

using namespace std;

class color_translation
{
public:
    color_translation(const string &filename);    // Constructor WITH memory allocation        initializes "snakeBodyColorHex", "snakeHeadColorHex", and "foodHexColor" to default colors (white, default blue, yellow)
    ~color_translation();   // 1 : destructor

    color_translation(const color_translation &source); // 2. copy constructor
    color_translation& operator=(const color_translation &source);  // 3. copy assignment operator
    color_translation(color_translation &&source);    // 4. move constructor
    color_translation& operator=(color_translation &&source); // 5. move assignment operator
    
    uint8_t snakeBodyColorHex[4]; // holds Snake Body Hex Color        "uint8_t" ----> holds values from 0 to 255 & covers hexadecimal values ranging from 0x00 to 0xFF
    uint8_t snakeHeadColorHex[4]; // holds Snake Head Hex Color        "uint8_t" ----> holds values from 0 to 255 & covers hexadecimal values ranging from 0x00 to 0xFF
    uint8_t foodHexColor[4]; // holds Food Hex Color                   "uint8_t" ----> holds values from 0 to 255 & covers hexadecimal values ranging from 0x00 to 0xFF

    void ColorWordToHex(string &ChoosenColor, uint8_t (&HexColorHolder)[4]); // translates Word color into Hex color
    void ColorChoice(string &colorPartChoice);  // allows user to change "Body", "Head", and/or "Food"       MUST USE "&colorPartChoice" NOT "colorPartChoice" TO CHANGE "snakeBodyColorHex", "snakeHeadColorHex", and "foodHexColor" HEX VALUES (even though "colorPartChoice" will NOT be Changed or Returned)

private:
    string line;  // used to access TEXT in "choosing_color_string.txt" file
    string filename;   // used to hold file name: "choosing_color_string.txt"

    string snakeBodyColorWord = "white"; // initializes Snake Body Color choice
    string snakeHeadColorWord = "default blue"; // initializes Snake Head Color choice
    string foodColorWord = "yellow";  // initializes Food Color choice
    
    vector<string> wordColorHolder{ snakeBodyColorWord, snakeHeadColorWord, foodColorWord };

    vector<string> colorType{ "Body ", "Head ", "Food " };
    int num_loops = 1;

    ifstream stream;    // used to access "choosing_color_string.txt" FILE
};

#endif