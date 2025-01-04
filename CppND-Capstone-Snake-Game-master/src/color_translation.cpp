#include "color_translation.h"
#include "SDL.h"
#include <algorithm>    // defines "transform"
#include <fstream>
#include <iostream>
#include <mutex>  // defines "mutex"
#include <string>
#include <vector>

using namespace std;

color_translation::color_translation(const string &filename) : filename(filename)  // Constructor WITH memory allocation (uses "new")    MUST USE & (reference to) ---> can NOT directly content in "choosing_color_string.txt"     "filename(filename)" - initializes "filename" with "filename" NOT SAME AS "filename = filename"
{
  stream.open(filename);  // opens "choosing_color_string.txt" file     do NOT use WITH "ifstream stream(filename)" in constructor ---> "if(stream.is_open())" in "ColorChoice()" will NOT pass
  if (!stream.is_open()) // CHECKS if "stream" OPENED
  {
    cout << "Text file failed to open.\n";
  }
  
  for (int i = 0; i < 4; i++) // initializes Snake Body Color Hex to default color (white)    MUST INITIALIZE "snakeBodyColorHex" THIS WAY ---> "ColorWordToHex()" WILL NOT BE ABLE TO CHANGE HEX VALUES
  {
    snakeBodyColorHex[i] = 0xFF;
  }
  
  // initializes Snake Head Color Hex to default color (default blue)    MUST INITIALIZE "snakeBodyColorHex" THIS WAY ---> "ColorWordToHex()" WILL NOT BE ABLE TO CHANGE HEX VALUES
  snakeHeadColorHex[0] = 0x00;
  snakeHeadColorHex[1] = 0x7A;
  snakeHeadColorHex[2] = 0xCC;
  snakeHeadColorHex[3] = 0xFF;
  
  // initializes Food Color Hex to default color (yellow)    MUST INITIALIZE "snakeBodyColorHex" THIS WAY ---> "ColorWordToHex()" WILL NOT BE ABLE TO CHANGE HEX VALUES
  foodHexColor[0] = 0xFF;
  foodHexColor[1] = 0xCC;
  foodHexColor[2] = 0x00;
  foodHexColor[3] = 0xFF;
}

color_translation::~color_translation() // 1 : destructor
{
  if (stream.is_open()) // CHECKS if "stream" is open     (in case "stream" was NOT closed in "ColorChoice()" function)
  {
    stream.close();  // closes "choosing_color_string.txt" file AFTER using it
  }
}

color_translation::color_translation(const color_translation &source) : filename(source.filename)   // 2. copy constructor
{
  if (source.stream.is_open())  // Checks if COPIED stream opened
  {
    stream.open(filename);
  }
}

color_translation &color_translation::operator=(const color_translation &source)   // 3. copy assignment operator
{
  if (this != &source)  // protects against self-assignment
  {
    if (stream.is_open()) // opens ORIGINAL Stream
    {
      stream.close(); // closes ORIGINAL Stream
    }
    
    filename = source.filename; // creates copy of "filename" from source
    if (source.stream.is_open())  // Checks COPIED Stream
    {
      stream.close(); // closes COPIED Stream
    }
  }
  return *this;   // returns reference to current object
}

color_translation::color_translation(color_translation &&source) : filename(move(source.filename)), stream(move(source.stream)) {}  // 4. move constructor

color_translation &color_translation::operator=(color_translation &&source)  // 5. move assignment operator
{
  if (this != &source)  // protects against self-assignment
  {
    if (stream.is_open())  // Checks ORIGINAL file is Opened FIRST before access elements inside file
    {
      stream.close();
    }
    filename = move(source.filename); // moves SOURCE "filename" into "filename"
    stream = move(source.stream); // moves "stream" into "stream_"
  }
  return *this;   // returns reference to current object
}

void color_translation::ColorWordToHex(string &ChoosenColor, uint8_t (&HexColorHolder)[4]) // translates Word color into Hex color    "HexColorHolder" MUST BE A PASS-BY-REFERENCE to CHANGE HEX VALUES ---> CANNOT USE MOVE SEMANTICS or ERROR WILL OCCUR    MUST CHANGE "HexColorHolder" VALUES INDIVIDUALITY
{
  if (ChoosenColor == "red")
  {
    HexColorHolder[0] = 0xFF;
    HexColorHolder[1] = 0x0;
    HexColorHolder[2] = 0x0;
    HexColorHolder[3] = 0xFF;
  }
  else if (ChoosenColor == "orange")
  {
    HexColorHolder[0] = 0xFF;
    HexColorHolder[1] = 0xA5;
    HexColorHolder[2] = 0x0;
    HexColorHolder[3] = 0xFF;
  }
  else if (ChoosenColor == "yellow")  // Default Food color
  {
    HexColorHolder[0] = 0xFF;
    HexColorHolder[1] = 0xCC;
    HexColorHolder[2] = 0x00;
    HexColorHolder[3] = 0xFF;
  }
  else if (ChoosenColor == "green")
  {
    HexColorHolder[0] = 0x00;
    HexColorHolder[1] = 0x80;
    HexColorHolder[2] = 0x00;
    HexColorHolder[3] = 0xFF;
  }
  else if (ChoosenColor == "blue")
  {
    HexColorHolder[0] = 0x00;
    HexColorHolder[1] = 0x00;
    HexColorHolder[2] = 0xFF;
    HexColorHolder[3] = 0xFF;
  }
  else if (ChoosenColor == "indigo")
  {
    HexColorHolder[0] = 0x4B;
    HexColorHolder[1] = 0x00;
    HexColorHolder[2] = 0x82;
    HexColorHolder[3] = 0xFF;
  }
  else if (ChoosenColor == "violet")
  {
    HexColorHolder[0] = 0xEE;
    HexColorHolder[1] = 0x82;
    HexColorHolder[2] = 0xEE;
    HexColorHolder[3] = 0xFF;
  }
  else if (ChoosenColor == "dark red")
  {
    HexColorHolder[0] = 0x8B;
    HexColorHolder[1] = 0x00;
    HexColorHolder[2] = 0x00;
    HexColorHolder[3] = 0xFF;
  }
  else if (ChoosenColor == "dark orange")
  {
    HexColorHolder[0] = 0xFF;
    HexColorHolder[1] = 0x8C;
    HexColorHolder[2] = 0x00;
    HexColorHolder[3] = 0xFF;
  }
  else if (ChoosenColor == "goldenrod")
  {
    HexColorHolder[0] = 0xDA;
    HexColorHolder[1] = 0xA5;
    HexColorHolder[2] = 0x20;
    HexColorHolder[3] = 0xFF;
  }
  else if (ChoosenColor == "light green")
  {
    HexColorHolder[0] = 0x90;
    HexColorHolder[1] = 0xEE;
    HexColorHolder[2] = 0x90;
    HexColorHolder[3] = 0xFF;
  }
  else if (ChoosenColor == "light blue")
  {
    HexColorHolder[0] = 0xAD;
    HexColorHolder[1] = 0xD8;
    HexColorHolder[2] = 0xE6;
    HexColorHolder[3] = 0xFF;
  }
  else if (ChoosenColor == "pink")
  {
    HexColorHolder[0] = 0xFF;
    HexColorHolder[1] = 0xC0;
    HexColorHolder[2] = 0xCB;
    HexColorHolder[3] = 0xFF;
  }
  else if (ChoosenColor == "dark violet")
  {
    HexColorHolder[0] = 0x94;
    HexColorHolder[1] = 0x00;
    HexColorHolder[2] = 0xD3;
    HexColorHolder[3] = 0xFF;
  }
  else if (ChoosenColor == "white") // Default snake Body color
  {
    for (int i = 0; i < 4; i++)
    {
      HexColorHolder[i] = 0xFF;
    }
  }
  else if (ChoosenColor == "default blue")  // Default snake Head color
  {
    HexColorHolder[0] = 0x00;
    HexColorHolder[1] = 0x7A;
    HexColorHolder[2] = 0xCC;
    HexColorHolder[3] = 0xFF;
  }
}

void color_translation::ColorChoice(string &colorPartChoice)   // allows user to change "Body", "Head", and/or "Food"       MUST USE "&colorPartChoice" NOT "colorPartChoice" TO CHANGE "snakeBodyColorHex", "snakeHeadColorHex", and "foodHexColor" HEX VALUES (even though "colorPartChoice" will NOT be Changed or Returned)
{
  lock_guard<mutex> lock(mtx);  // protects hex values as they're passed
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
		
    if (stream.is_open()) // "stream" INITIALIZED, OPENED, and CHECKED IF OPENED in constructor, CLOSED in destructor
    {
      while (line[0] != 'C')   // checks if 1st letter in "line" matches "C" (1st line)
      {
        getline(stream, line);   // accesses text inside "choosing_color_string.txt" file & stores in "line"
      }
      line.insert(11, colorType[j]);  // INSERTS "colorType" text
      cout << line;
      line.erase(11, 5);   // REMOVES "colorType" text
      getline(cin, wordColorHolder[j]); // includes MORE THAN 1 word
		  transform(wordColorHolder[j].begin(), wordColorHolder[j].end(), wordColorHolder[j].begin(), [](uint8_t c) { return tolower(c); });  // sets "snakeBodyColorWord", "snakeHeadColorWord", or "foodColorWord" to lowercase, makes case insensitive
    }
		
    while (wordColorHolder[j] != "red" && wordColorHolder[j] != "orange" && wordColorHolder[j] != "yellow" && wordColorHolder[j] != "green" && wordColorHolder[j] != "blue" && wordColorHolder[j] != "indigo" && wordColorHolder[j] != "violet" && wordColorHolder[j] != "dark red" && wordColorHolder[j] != "dark orange" && wordColorHolder[j] != "goldenrod" && wordColorHolder[j] != "light green" && wordColorHolder[j] != "light blue" && wordColorHolder[j] != "pink" && wordColorHolder[j] != "dark violet" && wordColorHolder[j] != "white" && wordColorHolder[j] != "default blue")
    {
      while (line[0] != 'P')   // checks if 1st letter in "line" matches "P" (2nd line)
      {
        getline(stream, line);   // accesses text inside "choosing_color_string.txt" file & stores in "line"
      }
      cout << line;
      getline(cin, wordColorHolder[j]); // includes MORE THAN 1 word
      transform(wordColorHolder[j].begin(), wordColorHolder[j].end(), wordColorHolder[j].begin(), [](uint8_t c) { return tolower(c); });  // sets "snakeBodyColorWord", "snakeHeadColorWord", or "foodColorWord" to lowercase, makes case insensitive
      stream.close(); // MUST CLOSE "stream" THEN
      stream.open(filename);  // REOPEN "stream" ---> "getline()" Will START At 1ST LINE to PREVENT program STOPPING Then Goinghrough INIFINITE WHILE LOOP
    }
	}
  ColorWordToHex(wordColorHolder[0], snakeBodyColorHex);  // obtains chosen Body color
  ColorWordToHex(wordColorHolder[1], snakeHeadColorHex);  // obtains chosen Head color
  ColorWordToHex(wordColorHolder[2], foodHexColor);  // obtains chosen Food color
  stream.close(); // MUST CLOSE "stream" HERE ---> "stream" Text will INFINITLY LOOP & SHOW TEXT AFTER "ColorChoice()" ENDS
}