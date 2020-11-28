#ifndef SPRITE_H
#define SPRITE_H

#include<fstream>
#include<iostream>
#include<vector>

class sprite
{

  std::vector < uint8_t > map;
protected:
  int side_dimension_x, side_dimension_y;
  int topLeftX, topLeftY;
public:
  //constructor
    sprite (int side_x, int side_y)
  {
    topLeftX = 0;
    topLeftY = 0;
    side_dimension_x = side_x;
    side_dimension_y = side_y;
    for (int i = 0; i < side_dimension_x * side_dimension_y; i++)
      map.push_back (0);
  }
  //set the position of the top left of the sprite map.
  void setPosition (int posx, int posy)
  {
    topLeftX = posx;
    topLeftY = posy;
  }
  void transformPosition (int pox, int poy)
  {
    topLeftX += pox;
    topLeftY += poy;
  }
  uint8_t at (int index)
  {
    return map[index];
  }
  auto getPosition ()
  {
    struct position
    {
      int x, y;
    };

    return position
    {
    topLeftX, topLeftY};
  }
  auto getDimensions ()
  {
    struct dimensions
    {
      int x, y;
    };

    return dimensions
    {
    side_dimension_x, side_dimension_y};
  }
  //load sprite data from a .sprite file
  int loadSprite (std::string path)
  {
    uint8_t no;
    int fside_x, fside_y;	//size of the pixel map held in the file
    int i = 0;

    std::ifstream file (path, std::ios::in | std::ios::binary);
    if (!file)
      {
	std::cout << "Invalid sprite!";
	return -1;
      }
    file.read ((char *) &fside_x, sizeof (int));
    file.read ((char *) &fside_y, sizeof (int));
    if (fside_x != side_dimension_x || fside_y != side_dimension_y)
      std::cout <<
	"File size is different from sprite dimension. Sprite will be padded!\n";
    while (i < side_dimension_x * side_dimension_y)
      {
	if (file.eof ())
	  {
	    map[i++] = 0;
	  }
	else
	  {
	    file.read ((char *) &no, 1);
	    map[i++] = no;
	  }
      }
    file.close ();
    return 0;
  }
};

//Animated sprite derived from sprite
class animatedSprite:public sprite
{
  int nof;			//number of frames
    std::vector < std::vector < uint8_t >> map;
  int currFrame;
public:
  //constructor
    animatedSprite (int side_x, int side_y, int nf):sprite (side_x, side_y)
  {
    nof = nf;
    currFrame = 0;
  }
  void nextFrame ()
  {
    if (currFrame != nof - 1)
      {
	currFrame += 1;
      }
    else
      {
	currFrame = 0;
      }
  }

  //load sprite data from a .sprite file
  int loadSprite (std::string path)
  {
    uint8_t no;
    int fside_x, fside_y;	//size of the pixel map held in the file
    int i = 0;
    int numberFrame;		//number of frames as read from file

    std::ifstream file (path, std::ios::in | std::ios::binary);
    if (!file)
      {
	std::cout << "Invalid sprite!";
	return -1;
      }
    file.read ((char *) &fside_x, sizeof (int));
    file.read ((char *) &fside_y, sizeof (int));
    if (fside_x != side_dimension_x || fside_y != side_dimension_y)
      {
	std::cout <<
	  "Dimension of the sprite in the file is different from sprite dimension. Sprite will be padded!\n";
      }
    file.read ((char *) &numberFrame, sizeof (int));
    if (numberFrame != nof)
      {
	if (numberFrame > nof)
	  {
	    std::cout << "This sprite file has extra frames!\n";
	  }
	else
	  {
	    std::cout <<
	      "This sprite has fewer frames than needed. Sprite will be padded\n";
	  }
      }
    for (int j = 0; j < numberFrame; j++)
      {
	i = 0;
	map.push_back (std::vector < uint8_t > ());
	while (i < side_dimension_x * side_dimension_y)
	  {
	    if (file.eof ())
	      {
		map[j].push_back (0);
		i++;
	      }
	    else
	      {
		file.read ((char *) &no, 1);
		map[j].push_back (no);
		i++;
	      }
	  }
      }
    file.close ();
    return 0;
  }
  //returns value at index of current frame's map
  int at (int index)
  {
    return map[currFrame][index];
  }
};
#endif
