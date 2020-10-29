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
	int side_dimension;
	int position[2];
public:
	sprite(int side){
		position[0] = 0;
		position[1] = 0;
		side_dimension = side;
		side *= side;
		map = new sprite_pixel;
		map->data = 0;
		sprite_pixel* x = map;
		for(int i=0;i<side-1;i++) {
			sprite_pixel* next = new sprite_pixel;
			next->data = 0;
			x->next = next;
			x = next;
			x->next = NULL;
		}
		iter = NULL;
	}
	~sprite(){
		sprite_pixel* x = map;
		sprite_pixel* y;
		while(x != NULL){
			y = x;
			x = x->next;
			delete y;
		}
	}
	void setPosition(int x, int y){
		position[0] = x;
		position[1] = y;
	}
	uint8_t next(){
		if(iter == NULL) {
			iter = map;
		}
		else {
		iter = iter->next;
		}
		return iter->data;
	}
	void reset_iter(){
		iter = map;
	}
	int loadSprite(std::string path){
		uint8_t no;
		int side;
		sprite_pixel* x = map;
		std::ifstream file(path, std::ios::in | std::ios::binary);
		if(!file) {
			std::cout<<"Invalid sprite!";
			return -1;
		}
		file.read((char*)&side,sizeof(side));
		if(side != side_dimension)
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
