#ifndef SPRITE_H
#define SPRITE_H

#include<fstream>

class sprite {
	std::vector < uint8_t > map;
	int side_dimension_x, side_dimension_y;
	int topLeftX, topLeftY;
 public:
	//constructor
	 sprite(int side_x, int side_y) {
		topLeftX = 0;
		topLeftY = 0;
		side_dimension_x = side_x;
		side_dimension_y = side_y;
		for (int i = 0; i < side_dimension_x * side_dimension_y; i++)
			map.push_back(0);
	}
	//set the position of the top left of the sprite map.
	    void setPosition(int posx, int posy) {
		topLeftX = posx;
		topLeftY = posy;
	}
	uint8_t at(int index) {
		return map[index];
	}
	auto getPosition() {
		struct position {
			int x, y;
		};

		return position {
		topLeftX, topLeftY};
	}
	auto getDimensions() {
		struct dimensions {
			int x, y;
		};

		return dimensions {
		side_dimension_x, side_dimension_y};
	}
	//load sprite data from a .sprite file
	int loadSprite(std::string path) {
		uint8_t no;
		int fside_x, fside_y;   //size of the pixel map held in the file
		int i = 0;

		std::ifstream file(path, std::ios::in | std::ios::binary);
		if (!file) {
			std::cout << "Invalid sprite!";
			return -1;
		}
		file.read((char *)&fside_x, sizeof(int));
		file.read((char *)&fside_y, sizeof(int));
		if (fside_x != side_dimension_x || fside_y != side_dimension_y)
			std::cout <<
		            "File size is different from sprite dimension. Sprite will be padded!\n";
		while (i < side_dimension_x * side_dimension_y) {
			if (file.eof()) {
				map[i++] = 0;
			} else {
				file.read((char *)&no, 1);
				map[i++] = no;
			}
		}
		file.close();
		return 0;
	}
};
#endif
