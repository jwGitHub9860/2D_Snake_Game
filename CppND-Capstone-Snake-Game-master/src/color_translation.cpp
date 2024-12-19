#include "color_translation.h"
#include "SDL.h"
#include <algorithm>    // defines "transform"
#include <fstream>
#include <iostream>
#include <memory>   // defines "unique_ptr"
#include <string>
#include <vector>

using namespace std;

//color_translation::color_translation() : stream(stream) {}   // Constructor WITHOUT memory allocation (does NOT use "new")     "stream(stream)" - initializes "stream" with "stream" NOT SAME AS "stream = stream"

/*color_translation::color_translation()  // TEST 1 Constructor WITH memory allocation (uses "new")    MUST USE & (reference to) ---> can NOT directly content in "choosing_color_string.txt"     "stream(stream)" - initializes "stream" with "stream" NOT SAME AS "stream = stream"
{
  colorPtr_ = new unsigned char[];   // initializes "colorPtr_"
  //colorPtr_ = nullptr;    // invalid data handles (initializes "colorPtr_")
}*/

/*color_translation::color_translation(const int HexSize) : HexSize(HexSize)  // TEST 1 Constructor WITH memory allocation (uses "new")    MUST USE & (reference to) ---> can NOT directly content in "choosing_color_string.txt"     "stream(stream)" - initializes "stream" with "stream" NOT SAME AS "stream = stream"
{
  cout << "Success" << endl;
  colorPtr_ = new unsigned char[];   // initializes "colorPtr_"
  //colorPtr_ = nullptr;    // invalid data handles (initializes "colorPtr_")
}*/

// CONSTRUCTOR input in "color_translation" class MUST BE "unsigned char*" NOT "unsigned char[]" ----> ERROR WILL OCCUR; CONSTRUCTOR Can NOT Be ()

/*color_translation::color_translation(unsigned char* defaultHexBodyColor, unsigned char* defaultHexHeadColor, unsigned char* defaultHexFoodColor)// : stream(stream)  // NOT ALLOWED TEST 2 Constructor WITH memory allocation (uses "new")    MUST USE & (reference to) ---> can NOT directly content in "choosing_color_string.txt"     "stream(stream)" - initializes "stream" with "stream" NOT SAME AS "stream = stream"
{
  for (int i = 0; i < 4; i++)
  {
    unsigned char snakeBodyColorHex[i] = defaultHexBodyColor[i];  // initializes Snake Body Color Hex to default color (white)
    unsigned char snakeHeadColorHex[i] = defaultHexHeadColor[i];  // initializes Snake Head Color Hex to default color (default blue)
    unsigned char foodHexColor[i] = defaultHexFoodColor[i];  // initializes Food Color Hex to default color (yellow)
  }
  
  unique_ptr<unsigned char[]> color_translationBodyHexPtr(new unsigned char[4]);  // allocates heap memory (initializes "color_translationBodyHexPtr")    MUST INCLUDE "unique_ptr<unsigned char[]>" ---> Error will occur
  unique_ptr<unsigned char[]> color_translationHeadHexPtr(new unsigned char[4]);  // allocates heap memory (initializes "color_translationHeadHexPtr")    MUST INCLUDE "unique_ptr<unsigned char[]>" ---> Error will occur
  unique_ptr<unsigned char[]> color_translationFoodHexPtr(new unsigned char[4]);  // allocates heap memory (initializes "color_translationFoodHexPtr")    MUST INCLUDE "unique_ptr<unsigned char[]>" ---> Error will occur
  //colorPtr_(new unsigned char[4]);   // initializes "colorPtr_"
  //colorPtr_ = nullptr;    // invalid data handles (initializes "colorPtr_")
}*/

/*color_translation::color_translation(const unsigned char* defaultHexBodyColor, const unsigned char* defaultHexHeadColor, const unsigned char* defaultHexFoodColor, const string filename)// : stream(stream)  // NOT ALLOWED TEST 2 Constructor WITH memory allocation (uses "new")    MUST USE & (reference to) ---> can NOT directly content in "choosing_color_string.txt"     "stream(stream)" - initializes "stream" with "stream" NOT SAME AS "stream = stream"
{
  // MOVE POINTER DATA INTO DIFFERENT ARRAY
  move(defaultHexBodyColor.begin(), defaultHexBodyColor.end(), snakeBodyColorHex.begin());  // initializes Snake Body Color Hex to default color (white)
  move(defaultHexHeadColor.begin(), defaultHexHeadColor.end(), snakeHeadColorHex.begin());  // initializes Snake Head Color Hex to default color (default blue)
  move(defaultHexFoodColor.begin(), defaultHexFoodColor.end(), foodHexColor.begin());  // initializes Food Color Hex to default color (yellow)
  for (int i = 0; i < 4; i++)
  {
    unsigned char snakeBodyColorHex[i] = defaultHexBodyColor[i];  // initializes Snake Body Color Hex to default color (white)
    unsigned char snakeHeadColorHex[i] = defaultHexHeadColor[i];  // initializes Snake Head Color Hex to default color (default blue)
    unsigned char foodHexColor[i] = defaultHexFoodColor[i];  // initializes Food Color Hex to default color (yellow)
  }

  ifstream stream(filename); // accesses "choosing_color_string.txt" file

  unique_ptr<unsigned char[]> color_translationBodyHexPtr(new unsigned char[4]);  // allocates heap memory (initializes "color_translationBodyHexPtr")    MUST INCLUDE "unique_ptr<unsigned char[]>" ---> Error will occur
  unique_ptr<unsigned char[]> color_translationHeadHexPtr(new unsigned char[4]);  // allocates heap memory (initializes "color_translationHeadHexPtr")    MUST INCLUDE "unique_ptr<unsigned char[]>" ---> Error will occur
  unique_ptr<unsigned char[]> color_translationFoodHexPtr(new unsigned char[4]);  // allocates heap memory (initializes "color_translationFoodHexPtr")    MUST INCLUDE "unique_ptr<unsigned char[]>" ---> Error will occur
  //colorPtr_(new unsigned char[4]);   // initializes "colorPtr_"
  //colorPtr_ = nullptr;    // invalid data handles (initializes "colorPtr_")
}*/

color_translation::color_translation(const string &filename) : filename_(filename)  // NOT ALLOWED TEST 2 Constructor WITH memory allocation (uses "new")    MUST USE & (reference to) ---> can NOT directly content in "choosing_color_string.txt"     "filename_(filename)" - initializes "filename_" with "filename" NOT SAME AS "filename_ = filename"
{
  ifstream stream(filename_); // accesses "choosing_color_string.txt" file
  stream.open(filename_);
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
  /*if (color_translationBodyHexPtr != nullptr && color_translationHeadHexPtr != nullptr && color_translationFoodHexPtr != nullptr)   // can NOT deallocate "ifstream" ---> "stream != NULL"
  {
    delete[] stream;//color_translationBodyHexPtr[];   // deallocates heap memory
  }*/
}

color_translation::color_translation(const color_translation &source) : filename_(source.filename)   // 2. copy constructor
{
  if (source.stream.is_open())  // Checks if COPIED stream opened
  {
    source.stream.open();
  }
  
  //colorPtr_ = source.colorPtr_;     // creates copy of "colorPtr_" from source
}

color_translation::color_translation &operator=(const color_translation &source)   // 3. copy assignment operator
{
  if (this != &source)  // protects against self-assignment
  {
    if (stream.is_open())
    {
      stream.close();
    }
    
    ifstream source.stream.open();  // opens COPIED Stream
    if (source.stream.is_open())  // checks COPIED Stream
    {
      source.stream.close();
    }
  }
  return *this;   // returns reference to current object
  //colorPtr_ = source.colorPtr_;     // creates copy of "colorPtr_" from source
}

color_translation::color_translation(color_translation &&source) : filename_(source.filename), stream_(source.stream)  // 4. move constructor    ONLY NEED TO INITIALIZE "filename_"
{
  /*colorPtr_ = source.colorPtr_;     // creates copy of "colorPtr_" from source
  source.colorPtr_ = nullptr;    // prevents "colorPtr_" from being used again*/
}

color_translation::color_translation &operator=(color_translation &&source)  // 5. move assignment operator
{
  if (this != &source)  // protects against self-assignment
  {
    if (stream.open())  // Must Open ORIGINAL file FIRST before access elements inside file
    {
      stream.close();
    }
    filename_ = move(source.filename); // moves SOURCE "filename" into "filename"
    stream_ = move(source.stream); // moves "stream" into "stream_"
  }
  /*if (this != &source) // protects against self-assignment    
  {
    delete[] colorPtr_;
    colorPtr_ = source.colorPtr_; // creates copy of "colorPtr_" from source
    source.colorPtr_ = nullptr;    // prevents "colorPtr_" from being used again
  }*/
  return *this;   // returns reference to current object
}

unsigned char color_translation::ColorWordToHex(string ChoosenColor) // translates Word color into Hex color USING MOVE SEMANTICS ---> MUST Move (or copy) Values Into Array or ERROR WILL OCCUR
{
  if (ChoosenColor == "red")
  {
    return ChoosenHexColor = { 0xFF, 0x0, 0x0, 0xFF };
  }
  else if (ChoosenColor == "orange")
  {
    return ChoosenHexColor = { 0xFF, 0xA5, 0x0, 0xFF };
  }
  else if (ChoosenColor == "yellow")
  {
    return ChoosenHexColor = { 0xFF, 0xCC, 0x00, 0xFF }; // Default Food color
  }
  else if (ChoosenColor == "green")
  {
    return ChoosenHexColor = { 0x00, 0x80, 0x00, 0xFF };
  }
  else if (ChoosenColor == "blue")
  {
    return ChoosenHexColor = { 0x00, 0x00, 0xFF, 0xFF };
  }
  else if (ChoosenColor == "indigo")
  {
    return ChoosenHexColor = { 0x4B, 0x00, 0x82, 0xFF };
  }
  else if (ChoosenColor == "violet")
  {
    return ChoosenHexColor = { 0xEE, 0x82, 0xEE, 0xFF };
  }
  else if (ChoosenColor == "dark red")
  {
    return ChoosenHexColor = { 0x8B, 0x00, 0x00, 0xFF };
  }
  else if (ChoosenColor == "dark orange")
  {
    return ChoosenHexColor = { 0xFF, 0x8C, 0x00, 0xFF };
  }
  else if (ChoosenColor == "goldenrod")
  {
    return ChoosenHexColor = { 0xDA, 0xA5, 0x20, 0xFF };
  }
  else if (ChoosenColor == "light green")
  {
    return ChoosenHexColor = { 0x90, 0xEE, 0x90, 0xFF };
  }
  else if (ChoosenColor == "light blue")
  {
    return ChoosenHexColor = { 0xAD, 0xD8, 0xE6, 0xFF };
  }
  else if (ChoosenColor == "pink")
  {
    return ChoosenHexColor = { 0xFF, 0xC0, 0xCB, 0xFF };
  }
  else if (ChoosenColor == "dark violet")
  {
    return ChoosenHexColor = { 0x94, 0x00, 0xD3, 0xFF };
  }
  else if (ChoosenColor == "white") // Default snake Body color
  {
    return ChoosenHexColor = { 0xFF, 0xFF, 0xFF, 0xFF };
  }
  else if (ChoosenColor == "default blue")  // Default snake Head color
  {
    return ChoosenHexColor = { 0x00, 0x7A, 0xCC, 0xFF };
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
  snakeBodyColorHex[4] = ColorWordToHex(wordColorHolder[0]);  // obtains chosen Body color
  snakeHeadColorHex[4] = ColorWordToHex(wordColorHolder[1]);  // obtains chosen Head color
  foodHexColor[4] = ColorWordToHex(wordColorHolder[2]);  // obtains chosen Food color
}