#ifndef COLOR_TRANSLATION_H
#define COLOR_TRANSLATION_H

#pragma once

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
    color_translation();    // Constructor
    ~color_translation();   // 1 : destructor

    color_translation(const color_translation &source); // 2. copy constructor
    color_translation& operator=(const color_translation &source);  // 3. copy assignment operator
    color_translation(color_translation &&source);    // 4. move constructor
    color_translation& operator=(color_translation &&source); // 5. move assignment operator

    string snakeBodyColor = "white"; // initializes Snake Body Color choice
    string snakeHeadColor = "default blue"; // initializes Snake Head Color choice
    string foodColor = "yellow";  // initializes Food Color choice

    unsigned char snakeBodyColorHex[] = { 0xFF, 0xFF, 0xFF, 0xFF }; // initializes Snake Body Color Hex to default color (white)        "unsigned char" ----> holds values from 0 to 255 & covers hexadecimal values ranging from 0x00 to 0xFF
    unsigned char snakeHeadColorHex[] = { 0x00, 0x7A, 0xCC, 0xFF }; // initializes Snake Head Color Hex to default color (default blue)        "unsigned char" ----> holds values from 0 to 255 & covers hexadecimal values ranging from 0x00 to 0xFF
    unsigned char foodHexColor[] = { 0xFF, 0xCC, 0x00, 0xFF }; // initializes Food Color Hex to default color (yellow)        "unsigned char" ----> holds values from 0 to 255 & covers hexadecimal values ranging from 0x00 to 0xFF
    
    unique_ptr<unsigned char[]> color_translationBodyHexPtr(snakeBodyColorHex);   // color_translation "unique_ptr" (MAIN)
    unique_ptr<unsigned char[]> color_translationHeadHexPtr(snakeHeadColorHex[]);   // color_translation "unique_ptr" (MAIN)
    unique_ptr<unsigned char[]> color_translationFoodHexPtr(foodHexColor[]);        // color_translation "unique_ptr" (MAIN)

    unsigned char ColorWordToHex(string ChoosenColor); // translates Word color into Hex color
    void ColorChoice(string colorPartChoice);  // allows user to change "Body", "Head", and/or "Food"

    vector<string> colorHolder{ snakeBodyColor, snakeHeadColor, foodColor };

private:
    string line;  // used to access text in "choosing_color_string.txt" file
    string ChoosenColor = ""; // initializes Choosen Color
    unsigned char ChoosenHexColor[] = { 0xFF, 0xFF, 0xFF, 0xFF }; // initializes Choosen Hex Color     NEED CHANGING? [] to [4] (neccesary?)    Default values (white)

    vector<string> colorType{ "Body ", "Head ", "Food " };
    int num_loops = 1;

    unique_ptr<unsigned char[]> color_;
};

#endif