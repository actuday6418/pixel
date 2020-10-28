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

public:
	sprite(int side){
		side *= side;
		map = new sprite_pixel;
		map->data = 0;
		sprite_pixel* x = map;
		std::cout<<(int)side<<std::endl;
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
		sprite_pixel* x = map;
		std::ifstream file(path, std::ios::in | std::ios::binary);
		if(!file) {
			std::cout<<"Invalid sprite!";
			return -1;
		}
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
