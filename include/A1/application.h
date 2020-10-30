#ifndef APPLICATION_H
#define APPLICATION_H

#include "../A0/pixel.h"
#include "../utilities/sprite.h"

struct layer {
	sprite* sprite_list;
	layer(){
		sprite_list = NULL;
	}
	addSprite(string path, int side){
	}
}

class game: public pixelMap {
	// see ../A0/pixel.h for definition of pixelMAp
	layer* layer_list;	
	void begin(){
	}
}

#endif
