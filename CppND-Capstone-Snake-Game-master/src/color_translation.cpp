#include "color_translation.h"
#include "SDL.h"
#include <algorithm>    // defines "transform"
#include <fstream>
#include <iostream>
#include <memory>   // defines "unique_ptr"
#include <string>
#include <vector>

using namespace std;

color_translation::color_translation(const string &filename) : filename(filename)  // NOT ALLOWED TEST 2 Constructor WITH memory allocation (uses "new")    MUST USE & (reference to) ---> can NOT directly content in "choosing_color_string.txt"     "filename(filename)" - initializes "filename" with "filename" NOT SAME AS "filename = filename"
{
  stream.open(filename);  // opens "choosing_color_string.txt" file     do NOT use WITH "ifstream stream(filename)" in constructor ---> "if(stream.is_open())" in "ColorChoice()" will NOT pass
  if (!stream.is_open()) // CHECKS if "stream" OPENED
  {
    cout << "Text file failed to open.\n";
  }

  unique_ptr<unsigned char[]> color_translationBodyHexPtr(new unsigned char[4]);  // allocates heap memory (initializes "color_translationBodyHexPtr")    MUST INCLUDE "unique_ptr<unsigned char[]>" ---> Error will occur
  unique_ptr<unsigned char[]> color_translationHeadHexPtr(new unsigned char[4]);  // allocates heap memory (initializes "color_translationHeadHexPtr")    MUST INCLUDE "unique_ptr<unsigned char[]>" ---> Error will occur
  unique_ptr<unsigned char[]> color_translationFoodHexPtr(new unsigned char[4]);  // allocates heap memory (initializes "color_translationFoodHexPtr")    MUST INCLUDE "unique_ptr<unsigned char[]>" ---> Error will occur
}

color_translation::~color_translation() // 1 : destructor
{
  if (stream.is_open())
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

void color_translation::ColorWordToHex(string ChoosenColor, unsigned char HexColorHolder[4]) // translates Word color into Hex color USING MOVE SEMANTICS ---> MUST Move (or copy) Values Into Array or ERROR WILL OCCUR
{
  if (ChoosenColor == "red")
  {
    unsigned char ChoosenHexColor[4] = { 0xFF, 0x0, 0x0, 0xFF };  // MUST DEFINE "ChoosenHexColor" with "unsigned char" & "[4]" HERE Not in Header File or ERROR WILL OCCUR
    HexColorHolder = move(ChoosenHexColor); // moves hex values into "HexColor" USING MOVE SEMANTICS
  }
  else if (ChoosenColor == "orange")
  {
    unsigned char ChoosenHexColor[4] = { 0xFF, 0xA5, 0x0, 0xFF };  // MUST DEFINE "ChoosenHexColor" with "unsigned char" & "[4]" HERE Not in Header File or ERROR WILL OCCUR
    HexColorHolder = move(ChoosenHexColor); // moves hex values into "HexColor" USING MOVE SEMANTICS
  }
  else if (ChoosenColor == "yellow")  // Default Food color
  {
    unsigned char ChoosenHexColor[4] = { 0xFF, 0xCC, 0x00, 0xFF };  // MUST DEFINE "ChoosenHexColor" with "unsigned char" & "[4]" HERE Not in Header File or ERROR WILL OCCUR
    HexColorHolder = move(ChoosenHexColor); // moves hex values into "HexColor" USING MOVE SEMANTICS
  }
  else if (ChoosenColor == "green")
  {
    unsigned char ChoosenHexColor[4] = { 0x00, 0x80, 0x00, 0xFF };  // MUST DEFINE "ChoosenHexColor" with "unsigned char" & "[4]" HERE Not in Header File or ERROR WILL OCCUR
    HexColorHolder = move(ChoosenHexColor); // moves hex values into "HexColor" USING MOVE SEMANTICS
  }
  else if (ChoosenColor == "blue")
  {
    unsigned char ChoosenHexColor[4] = { 0x00, 0x00, 0xFF, 0xFF };  // MUST DEFINE "ChoosenHexColor" with "unsigned char" & "[4]" HERE Not in Header File or ERROR WILL OCCUR
    HexColorHolder = move(ChoosenHexColor); // moves hex values into "HexColor" USING MOVE SEMANTICS
  }
  else if (ChoosenColor == "indigo")
  {
    unsigned char ChoosenHexColor[4] = { 0x4B, 0x00, 0x82, 0xFF };  // MUST DEFINE "ChoosenHexColor" with "unsigned char" & "[4]" HERE Not in Header File or ERROR WILL OCCUR
    HexColorHolder = move(ChoosenHexColor); // moves hex values into "HexColor" USING MOVE SEMANTICS
  }
  else if (ChoosenColor == "violet")
  {
    unsigned char ChoosenHexColor[4] = { 0xEE, 0x82, 0xEE, 0xFF };  // MUST DEFINE "ChoosenHexColor" with "unsigned char" & "[4]" HERE Not in Header File or ERROR WILL OCCUR
    HexColorHolder = move(ChoosenHexColor); // moves hex values into "HexColor" USING MOVE SEMANTICS
  }
  else if (ChoosenColor == "dark red")
  {
    unsigned char ChoosenHexColor[4] = { 0x8B, 0x00, 0x00, 0xFF };  // MUST DEFINE "ChoosenHexColor" with "unsigned char" & "[4]" HERE Not in Header File or ERROR WILL OCCUR
    HexColorHolder = move(ChoosenHexColor); // moves hex values into "HexColor" USING MOVE SEMANTICS
  }
  else if (ChoosenColor == "dark orange")
  {
    unsigned char ChoosenHexColor[4] = { 0xFF, 0x8C, 0x00, 0xFF };  // MUST DEFINE "ChoosenHexColor" with "unsigned char" & "[4]" HERE Not in Header File or ERROR WILL OCCUR
    HexColorHolder = move(ChoosenHexColor); // moves hex values into "HexColor" USING MOVE SEMANTICS
  }
  else if (ChoosenColor == "goldenrod")
  {
    unsigned char ChoosenHexColor[4] = { 0xDA, 0xA5, 0x20, 0xFF };  // MUST DEFINE "ChoosenHexColor" with "unsigned char" & "[4]" HERE Not in Header File or ERROR WILL OCCUR
    HexColorHolder = move(ChoosenHexColor); // moves hex values into "HexColor" USING MOVE SEMANTICS
  }
  else if (ChoosenColor == "light green")
  {
    unsigned char ChoosenHexColor[4] = { 0x90, 0xEE, 0x90, 0xFF };  // MUST DEFINE "ChoosenHexColor" with "unsigned char" & "[4]" HERE Not in Header File or ERROR WILL OCCUR
    HexColorHolder = move(ChoosenHexColor); // moves hex values into "HexColor" USING MOVE SEMANTICS
  }
  else if (ChoosenColor == "light blue")
  {
    unsigned char ChoosenHexColor[4] = { 0xAD, 0xD8, 0xE6, 0xFF };  // MUST DEFINE "ChoosenHexColor" with "unsigned char" & "[4]" HERE Not in Header File or ERROR WILL OCCUR
    HexColorHolder = move(ChoosenHexColor); // moves hex values into "HexColor" USING MOVE SEMANTICS
  }
  else if (ChoosenColor == "pink")
  {
    unsigned char ChoosenHexColor[4] = { 0xFF, 0xC0, 0xCB, 0xFF };  // MUST DEFINE "ChoosenHexColor" with "unsigned char" & "[4]" HERE Not in Header File or ERROR WILL OCCUR
    HexColorHolder = move(ChoosenHexColor); // moves hex values into "HexColor" USING MOVE SEMANTICS
  }
  else if (ChoosenColor == "dark violet")
  {
    unsigned char ChoosenHexColor[4] = { 0x94, 0x00, 0xD3, 0xFF };  // MUST DEFINE "ChoosenHexColor" with "unsigned char" & "[4]" HERE Not in Header File or ERROR WILL OCCUR
    HexColorHolder = move(ChoosenHexColor); // moves hex values into "HexColor" USING MOVE SEMANTICS
  }
  else if (ChoosenColor == "white") // Default snake Body color
  {
    unsigned char ChoosenHexColor[4] = { 0xFF, 0xFF, 0xFF, 0xFF };  // MUST DEFINE "ChoosenHexColor" with "unsigned char" & "[4]" HERE Not in Header File or ERROR WILL OCCUR
    HexColorHolder = move(ChoosenHexColor); // moves hex values into "HexColor" USING MOVE SEMANTICS
  }
  else if (ChoosenColor == "default blue")  // Default snake Head color
  {
    unsigned char ChoosenHexColor[4] = { 0x00, 0x7A, 0xCC, 0xFF };  // MUST DEFINE "ChoosenHexColor" with "unsigned char" & "[4]" HERE Not in Header File or ERROR WILL OCCUR
    HexColorHolder = move(ChoosenHexColor); // moves hex values into "HexColor" USING MOVE SEMANTICS
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
		
    if (stream.is_open()) // "stream" INITIALIZED, OPENED, and CHECKED IF OPENED in constructor, CLOSED in destructor
    {
      getline(stream, line);  // accesses text inside "choosing_color_string.txt" file & stores in "line"    do NOT need "while loop" ---> 1 LINE ONLY
      line.insert(11, colorType[j]);
      cout << line;
    }
		getline(cin, wordColorHolder[j]); // includes MORE THAN 1 word
		transform(wordColorHolder[j].begin(), wordColorHolder[j].end(), wordColorHolder[j].begin(), [](unsigned char c) { return tolower(c); });  // sets "snakeBodyColorWord", "snakeHeadColorWord", and/or "foodColorWord" to lowercase, makes case insensitive
	}
  ColorWordToHex(wordColorHolder[0], snakeBodyColorHex);  // obtains chosen Body color
  ColorWordToHex(wordColorHolder[1], snakeHeadColorHex);  // obtains chosen Head color
  ColorWordToHex(wordColorHolder[2], foodHexColor);  // obtains chosen Food color
}