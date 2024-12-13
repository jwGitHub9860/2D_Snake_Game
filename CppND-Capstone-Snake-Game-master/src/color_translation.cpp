#include "color_translation.h"
#include <algorithm>    // defines "transform"
#include <fstream>
#include <iostream>
#include <memory>   // defines "unique_ptr"
#include <string>
#include <vector>

using namespace std;

color_translation::color_translation() : stream_(stream) {}   // Constructor WITHOUT memory allocation (does NOT use "new")     "stream_(stream)" - initializes "stream_" with "stream" NOT SAME AS "stream_ = stream"

color_translation::color_translation()  // TEST 1 Constructor WITH memory allocation (uses "new")    MUST USE & (reference to) ---> can NOT directly content in "choosing_color_string.txt"     "stream_(stream)" - initializes "stream_" with "stream" NOT SAME AS "stream_ = stream"
{
  colorPtr_ = new unsigned char[];   // initializes "colorPtr_"
  //colorPtr_ = nullptr;    // invalid data handles (initializes "colorPtr_")
}

/*color_translation::color_translation(const &ifstream stream) : stream_(stream)  // NOT ALLOWED TEST 2 Constructor WITH memory allocation (uses "new")    MUST USE & (reference to) ---> can NOT directly content in "choosing_color_string.txt"     "stream_(stream)" - initializes "stream_" with "stream" NOT SAME AS "stream_ = stream"
{
  colorPtr_ = new unsigned char[];   // initializes "colorPtr_"
  //colorPtr_ = nullptr;    // invalid data handles (initializes "colorPtr_")
}*/

color_translation::~color_translation() // 1 : destructor
{
  if (ChoosenHexColor[] != nullptr)
  {
    delete[] ChoosenHexColor[];   // deallocates heap memory
  }
}

color_translation::color_translation(const color_translation &source)   // 2. copy constructor
{
  colorPtr_ = source.colorPtr_;     // creates copy of "colorPtr_" from source
}

color_translation::color_translation(const color_translation &source)   // 3. copy assignment operator
{
  colorPtr_ = source.colorPtr_;     // creates copy of "colorPtr_" from source
}

color_translation::color_translation(color_translation &&source)  // 4. move constructor
{
  colorPtr_ = source.colorPtr_;     // creates copy of "colorPtr_" from source
  source.colorPtr_ = nullptr;    // prevents "colorPtr_" from being used again
}

color_translation::color_translation(color_translation &&source)  // 5. move assignment operator
{
  if (this != &source) // protects against self-assignment    
  {
    delete[] colorPtr_;
    colorPtr_ = source.colorPtr_; // creates copy of "colorPtr_" from source
    source.colorPtr_ = nullptr;    // prevents "colorPtr_" from being used again
  }
  return *this;   // returns reference to current object
}

unsigned char color_translation::ColorWordToHex(string ChoosenColor) // translates Word color into Hex color USING MOVE SEMANTICS ---> MUST Move (or copy) Values Into Array or ERROR WILL OCCUR
{
  if (ChoosenColor == "red")
  {
    return ChoosenHexColor[4] = { 0xFF, 0x0, 0x0, 0xFF };
  }
  else if (ChoosenColor == "orange")
  {
    return ChoosenHexColor[4] = { 0xFF, 0xA5, 0x0, 0xFF };
  }
  else if (ChoosenColor == "yellow")
  {
    return ChoosenHexColor[4] = { 0xFF, 0xCC, 0x00, 0xFF }; // Default Food color
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
  else if (ChoosenColor == "white") // Default snake Body color
  {
    return ChoosenHexColor[4] = { 0xFF, 0xFF, 0xFF, 0xFF };
  }
  else if (ChoosenColor == "default blue")  // Default snake Head color
  {
    return ChoosenHexColor[4] = { 0x00, 0x7A, 0xCC, 0xFF };
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
		
    //ifstream stream("choosing_color_string.txt"); // accesses "choosing_color_string.txt" file
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
  snakeBodyColorHex[4] = ColorWordToHex(wordColorHolder[0]);  // obtains chosen Body color
  snakeHeadColorHex[4] = ColorWordToHex(wordColorHolder[1]);  // obtains chosen Head color
  foodHexColor[4] = ColorWordToHex(wordColorHolder[2]);  // obtains chosen Food color
}