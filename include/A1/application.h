#ifndef APPLICATION_H
#define APPLICATION_H

#include "../A0/pixel.h"
#include "../utilities/sprite.h"

struct layer {
	std::vector<sprite> sprite_vec;
	//add a new sprite to the sprite list.
	addSprite(string path, int side_x,int side_y){
		sprite s(side_x, side_y);
		s.loadSprite(path);
		sprite_vec.push(s);
	}
}

class game: public pixelMap {
	std::vector<layer> layer_vec;
	void tickTok () override {
		std::cout<<"Hello\n";
	}
	//returns the bounds of the part of a sprite that is visible
	void pixelCuller (int topLeftX, int topLeftY, int dimx, int dimy){
		if(topLeftX < 0){
			int left = std::max(topLeftX, 0);
			int right = std::min(topLeftX + dimx, 255);
			int top = std::max(topLeftY, 0);
			int bottom = std::min(topLeftY + dimy, 255);
		}
	}
	//assign the sprite maps, random layers, etc to the pixel array
	void mapThePixels(uint8_t array[4096]){
		for(auto x: layer_vec){
			for(auto y: x->sprite_vec){
				auto [topLftX,topLeftY] = y->getPosition();
				auto [dimx,dimy] = y->getDimensions();
			}
		}
	}
	public:
	void begin(){
		void start();
		
	}
}

#endif
