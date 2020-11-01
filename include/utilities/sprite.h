#ifndef SPRITE_H	
#define SPRITE_H

#include<fstream>

struct sprite_pixel {
	uint8_t data;
	sprite_pixel* next;
};

class sprite {
	sprite_pixel* map;
	sprite_pixel* iter;
	int side_dimension_x,side_dimension_y;
	int topLeftX, topLeftY;
public:
	//constructor
	sprite(int side_x, int side_y){
		topLeftX = 0;
		topLeftY = 0;
		side_dimension_x = side_x;
		side_dimension_y = side_y;
		map = new sprite_pixel;
		map->data = 0;
		sprite_pixel* x = map;
		for(int i=0;i<side_x*side_y-1;i++) {
			sprite_pixel* next = new sprite_pixel;
			next->data = 0;
			x->next = next;
			x = next;
			x->next = NULL;
		}
		iter = NULL;
	}
	//destructor
	~sprite(){
		sprite_pixel* x = map;
		sprite_pixel* y;
		while(x != NULL){
			y = x;
			x = x->next;
			delete y;
		}
	}
	//set the position of the top left of the sprite map.
	void setPosition(int posx, int posy){
		topLeftX = posx;
		topLeftX = posy;
	}
	auto getPosition(){
		struct position {
			int x,y;
		};
		return position {topLeftX, topLeftY};
	}
	auto getDimensions(){
		struct dimensions {
			int x,y;
		};
		return dimensions {side_dimension_x, side_dimension_y};
	}
	//returns the next pixel in the sprite map
	uint8_t next(){
		if(iter == NULL) {
			std::cout<<"ED"<<std::endl;
			iter = map;
		}
		else {
		iter = iter->next;
		}
		return iter->data;
	}
	//reset the iter value to the first pixel of the sprite map.
	void reset_iter(){
		iter = map;
	}
	//load sprite data from a .sprite file
	int loadSprite(std::string path){
		uint8_t no;
		int side_x, side_y;
		sprite_pixel* x = map;
		std::ifstream file(path, std::ios::in | std::ios::binary);
		if(!file) {
			std::cout<<"Invalid sprite!";
			return -1;
		}
		file.read((char*)&side_x,sizeof(int));
		file.read((char*)&side_y,sizeof(int));
		if(side_x != side_dimension_x || side_y != side_dimension_y)
			std::cout<<"File size is different from sprite dimension. Sprite will be padded!\n";
		while(x != NULL) {
			if(file.eof()){
				x->data = 0;
				x = x->next;
			}
			else {
			file.read((char*)&no,1);
			x->data = no;
			x = x->next;
			}
		}
		file.close();
		return 0;
	}
};
#endif
