#ifndef COLOR_TRANSLATION_H
#define COLOR_TRANSLATION_H

#pragma once

#include <fstream>
#include <iostream>
#include <memory>   // defines "unique_ptr"
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
    
    unsigned char snakeBodyColorHex[4]; // Snake Body Color Hex "unique_ptr" (MAIN)        "unsigned char" ----> holds values from 0 to 255 & covers hexadecimal values ranging from 0x00 to 0xFF
    unsigned char snakeHeadColorHex[4]; // Snake Head Color Hex "unique_ptr" (MAIN)        "unsigned char" ----> holds values from 0 to 255 & covers hexadecimal values ranging from 0x00 to 0xFF
    unsigned char foodHexColor[4]; // Food Color Hex "unique_ptr" (MAIN)                   "unsigned char" ----> holds values from 0 to 255 & covers hexadecimal values ranging from 0x00 to 0xFF
    
    // unique pointers for INDIVIDUAL Snake Body Hex Values
    unique_ptr<unsigned char[]> snakeBodyHexPtr_1;
    unique_ptr<unsigned char[]> snakeBodyHexPtr_2;
    unique_ptr<unsigned char[]> snakeBodyHexPtr_3;
    unique_ptr<unsigned char[]> snakeBodyHexPtr_4;
    
    // unique pointers for INDIVIDUAL Snake Head Hex Values
    unique_ptr<unsigned char[]> snakeHeadHexPtr_1;
    unique_ptr<unsigned char[]> snakeHeadHexPtr_2;
    unique_ptr<unsigned char[]> snakeHeadHexPtr_3;
    unique_ptr<unsigned char[]> snakeHeadHexPtr_4;

    // unique pointers for INDIVIDUAL Food Hex Values
    unique_ptr<unsigned char[]> foodHexPtr_1;
    unique_ptr<unsigned char[]> foodHexPtr_2;
    unique_ptr<unsigned char[]> foodHexPtr_3;
    unique_ptr<unsigned char[]> foodHexPtr_4;

    void ColorWordToHex(string &ChoosenColor, unsigned char[] (&HexColorHolder)[4]); // translates Word color into Hex color
    void ColorChoice(string &colorPartChoice);  // allows user to change "Body", "Head", and/or "Food"       MUST USE "&colorPartChoice" NOT "colorPartChoice" TO CHANGE "snakeBodyColorHex", "snakeHeadColorHex", and "foodHexColor" HEX VALUES (even though "colorPartChoice" will NOT be Changed or Returned)

private:
    string line = "";  // used to access TEXT in "choosing_color_string.txt" file
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