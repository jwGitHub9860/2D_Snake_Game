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
    color_translation(const string &filename);    // Constructor WITH memory allocation
    ~color_translation();   // 1 : destructor

    color_translation(const color_translation &source); // 2. copy constructor
    color_translation& operator=(const color_translation &source);  // 3. copy assignment operator
    color_translation(color_translation &&source);    // 4. move constructor
    color_translation& operator=(color_translation &&source); // 5. move assignment operator
    
    unsigned char snakeBodyColorHex[4] = { 0xFF, 0xFF, 0xFF, 0xFF }; // initializes Snake Body Color Hex to default color (white)        "unsigned char" ----> holds values from 0 to 255 & covers hexadecimal values ranging from 0x00 to 0xFF
    unsigned char snakeHeadColorHex[4] = { 0x00, 0x7A, 0xCC, 0xFF }; // initializes Snake Head Color Hex to default color (default blue)        "unsigned char" ----> holds values from 0 to 255 & covers hexadecimal values ranging from 0x00 to 0xFF
    unsigned char foodHexColor[4] = { 0xFF, 0xCC, 0x00, 0xFF }; // initializes Food Color Hex to default color (yellow)        "unsigned char" ----> holds values from 0 to 255 & covers hexadecimal values ranging from 0x00 to 0xFF
    
    unique_ptr<unsigned char[]> color_translationBodyHexPtr;// = make_unique<unsigned char[]>(4);   // color_translation "unique_ptr" (MAIN)        MUST SPECIFY ARRAY SIZE ---> [4] NOT []        MUST USE (new unsigned char[4]) NOT (snakeBodyColorHex[4]) ---> error will occur
    unique_ptr<unsigned char[]> color_translationHeadHexPtr;// = make_unique<unsigned char[]>(4);   // color_translation "unique_ptr" (MAIN)        MUST SPECIFY ARRAY SIZE ---> [4] NOT []        MUST USE (new unsigned char[4]) NOT (snakeHeadColorHex[4]) ---> error will occur
    unique_ptr<unsigned char[]> color_translationFoodHexPtr;// = make_unique<unsigned char[]>(4);   // color_translation "unique_ptr" (MAIN)        MUST SPECIFY ARRAY SIZE ---> [4] NOT []        MUST USE (new unsigned char[4]) NOT (foodHexColor[4]) ---> error will occur

    void ColorWordToHex(string ChoosenColor, unsigned char HexColorHolder[4]); // translates Word color into Hex color
    void ColorChoice(string colorPartChoice);  // allows user to change "Body", "Head", and/or "Food"

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