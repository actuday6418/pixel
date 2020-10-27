#ifndef SPRITE_H	
#define SPRITE_H

#include<fstream>

struct node {
	uint8_t data;
	node* next;
};

class sprite {
	node* map;

public:
	sprite(uint8_t side){
		side *= side;
		map = new node;
		node* x = map;
		for(int i=0;i<side-1;i++) {
			node* next = new node;
			x->next = next;
			x = next;
			x->next = NULL;
		}
	}
	~sprite(){
		node* x = map;
		node* y;
		while(x != NULL){
			y = x;
			x = x->next;
			delete y;
		}
	}
	uint8_t loadSprite(std::string path){
		uint8_t no;
		node* x = map;
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
	}
};
#endif
