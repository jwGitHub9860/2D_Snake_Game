#include "color_translation.h"
#include <algorithm>    // defines "transform"
#include <fstream>
#include <iostream>
#include <memory>   // defines "unique_ptr"
#include <string>
#include <vector>

using namespace std;

color_translation::color_translation()  // Constructor
{
    color_ = nullptr;    // invalid data handles (initializes "color_")
}

color_translation::~color_translation() // 1 : destructor
{
    if (ChoosenHexColor[] != nullptr)   // deallocates heap memory      
    {
        delete[] ChoosenHexColor[];
    }
}

color_translation::color_translation(const color_translation &source)   // 2. copy constructor
{
    color_ = source.color_;     // creates copy of "color_" from source
}

color_translation::color_translation(const color_translation &source)   // 3. copy assignment operator
{
    color_ = source.color_;     // creates copy of "color_" from source
}

color_translation::color_translation(color_translation &&source)  // 4. move constructor
{
    color_ = source.color_;     // creates copy of "color_" from source
    source.color_ = nullptr;    // prevents "color_" from being used again
}

color_translation::color_translation(color_translation &&source)  // 5. move assignment operator
{
    if (this != &source) // protects against self-assignment    
    {
        delete[] data;
        color_ = source.color_; // creates copy of "color_" from source
        source.color_ = nullptr;    // prevents "color_" from being used again
    }
    return *this;   // returns reference to current object
}

unsigned char color_translation::ColorWordToHex(string ChoosenColor, unsigned char ChoosenHexColor[4]) // translates Word color into Hex color USING MOVE SEMANTICS ---> MUST Move (or copy) Values Into Array or ERROR WILL OCCUR
{
  if (ChoosenColor == "red")
  {
    HexColor[4] = { 0xFF, 0x0, 0x0, 0xFF };
    for (int i = 0; i < 4; i++)
    {
        ChoosenHexColor[i] = move(HexColor[i]); // Moves array into dynamically allocated array
    }
    return ChoosenHexColor[4];
  }
  else if (ChoosenColor == "orange")
  {
    HexColor[4] = { 0xFF, 0xA5, 0x0, 0xFF };
    for (int i = 0; i < 4; i++)
    {
        ChoosenHexColor[i] = move(HexColor[i]); // Moves array into dynamically allocated array
    }
    return ChoosenHexColor[4];
  }
  else if (ChoosenColor == "yellow")
  {
    HexColor[4] = { 0xFF, 0xCC, 0x00, 0xFF }; // Default Food color
    for (int i = 0; i < 4; i++)
    {
        ChoosenHexColor[4] = move(HexColor[i]); // Moves array into dynamically allocated array
    }
    return ChoosenHexColor[4];
  }
  else if (ChoosenColor == "green")
  {
    HexColor[4] = { 0x00, 0x80, 0x00, 0xFF };
    for (int i = 0; i < 4; i++)
    {
        ChoosenHexColor[4] = move(HexColor[i]); // Moves array into dynamically allocated array
    }
    return ChoosenHexColor[4];
  }
  else if (ChoosenColor == "blue")
  {
    HexColor[4] = { 0x00, 0x00, 0xFF, 0xFF };
    for (int i = 0; i < 4; i++)
    {
        ChoosenHexColor[4] = move(HexColor[i]); // Moves array into dynamically allocated array
    }
    return ChoosenHexColor[4];
  }
  else if (ChoosenColor == "indigo")
  {
    HexColor[4] = { 0x4B, 0x00, 0x82, 0xFF };
    for (int i = 0; i < 4; i++)
    {
        ChoosenHexColor[4] = move(HexColor[i]); // Moves array into dynamically allocated array
    }
    return ChoosenHexColor[4];
  }
  else if (ChoosenColor == "violet")
  {
    HexColor[4] = { 0xEE, 0x82, 0xEE, 0xFF };
    for (int i = 0; i < 4; i++)
    {
        ChoosenHexColor[4] = move(HexColor[i]); // Moves array into dynamically allocated array
    }
    return ChoosenHexColor[4];
  }
  else if (ChoosenColor == "dark red")
  {
    HexColor[4] = { 0x8B, 0x00, 0x00, 0xFF };
    for (int i = 0; i < 4; i++)
    {
        ChoosenHexColor[4] = move(HexColor[i]); // Moves array into dynamically allocated array
    }
    return ChoosenHexColor[4];
  }
  else if (ChoosenColor == "dark orange")
  {
    HexColor[4] = { 0xFF, 0x8C, 0x00, 0xFF };
    for (int i = 0; i < 4; i++)
    {
        ChoosenHexColor[4] = move(HexColor[i]); // Moves array into dynamically allocated array
    }
    return ChoosenHexColor[4];
  }
  else if (ChoosenColor == "goldenrod")
  {
    HexColor[4] = { 0xDA, 0xA5, 0x20, 0xFF };
    for (int i = 0; i < 4; i++)
    {
        ChoosenHexColor[4] = move(HexColor[i]); // Moves array into dynamically allocated array
    }
    return ChoosenHexColor[4];
  }
  else if (ChoosenColor == "light green")
  {
    HexColor[4] = { 0x90, 0xEE, 0x90, 0xFF };
    for (int i = 0; i < 4; i++)
    {
        ChoosenHexColor[4] = move(HexColor[i]); // Moves array into dynamically allocated array
    }
    return ChoosenHexColor[4];
  }
  else if (ChoosenColor == "light blue")
  {
    HexColor[4] = { 0xAD, 0xD8, 0xE6, 0xFF };
    for (int i = 0; i < 4; i++)
    {
        ChoosenHexColor[4] = move(HexColor[i]); // Moves array into dynamically allocated array
    }
    return ChoosenHexColor[4];
  }
  else if (ChoosenColor == "pink")
  {
    HexColor[4] = { 0xFF, 0xC0, 0xCB, 0xFF };
    for (int i = 0; i < 4; i++)
    {
        ChoosenHexColor[4] = move(HexColor[i]); // Moves array into dynamically allocated array
    }
    return ChoosenHexColor[4];
  }
  else if (ChoosenColor == "dark violet")
  {
    HexColor[4] = { 0x94, 0x00, 0xD3, 0xFF };
    for (int i = 0; i < 4; i++)
    {
        ChoosenHexColor[4] = move(HexColor[i]); // Moves array into dynamically allocated array
    }
    return ChoosenHexColor[4];
  }
  else if (ChoosenColor == "white") // Default snake Body color
  {
    HexColor[4] = { 0xFF, 0xFF, 0xFF, 0xFF };
    for (int i = 0; i < 4; i++)
    {
        ChoosenHexColor[4] = move(HexColor[i]); // Moves array into dynamically allocated array
    }
    return ChoosenHexColor[4];
  }
  else if (ChoosenColor == "default blue")  // Default snake Head color
  {
    HexColor[4] = { 0x00, 0x7A, 0xCC, 0xFF };
    for (int i = 0; i < 4; i++)
    {
        ChoosenHexColor[4] = move(HexColor[i]); // Moves array into dynamically allocated array
    }
    return ChoosenHexColor[4];
  }
}

void color_translation::ColorChoice(string colorPartChoice)   // allows user to change "Body", "Head", and/or "Food"
{	
	if (colorPartChoice == "body" || colorPartChoice == "head" || colorPartChoice == "food")
	{
		num_loops = 1;
	}
	if (colorPartChoice == "whole snake")
	{
		num_loops = 2;
	}
	if (colorPartChoice == "all")
	{
		num_loops = 3;
	}

	for (int i = 0; i < num_loops; i++)
	{
		int j = i;
		if (colorPartChoice == "head")
		{
			j = 1;
		}
		if (colorPartChoice == "food")
		{
			j = 2;
		}
		
    ifstream stream("choosing_color_string.txt"); // accesses "choosing_color_string.txt" file
    if (stream.open())
    {
      while (getline(stream, line))  // accesses text inside "choosing_color_string.txt" file & stores in "line"
      {
        line.insert(11, colorType[j]);
        cout << line;
      }
      stream.close();
    }
    else
    {
      cout << "Text file failed to open.\n";
    }
		getline(cin, wordColorHolder[j]); // includes MORE THAN 1 word
		transform(wordColorHolder[j].begin(), wordColorHolder[j].end(), wordColorHolder[j].begin(), [](unsigned char c) { return tolower(c); });  // sets "snakeBodyColorWord", "snakeHeadColorWord", and/or "foodColorWord" to lowercase, makes case insensitive
	}
  snakeBodyColorHex[4] = ColorWordToHex(wordColorHolder[0], snakeBodyColorHex[4]);  // obtains chosen Body color
  snakeHeadColorHex[4] = ColorWordToHex(wordColorHolder[1], snakeHeadColorHex[4]);  // obtains chosen Head color
  foodHexColor[4] = ColorWordToHex(wordColorHolder[2], foodHexColor[4]);  // obtains chosen Food color
}