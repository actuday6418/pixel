#ifndef APPLICATION_H
#define APPLICATION_H

#include "../A0/pixel.h"
#include "sprite.h"
#include<iostream>
#include<string>

using RULE = bool (std::vector < uint8_t > &);

struct layer {
	std::vector < sprite > sprite_vec;
	//add a new sprite to the sprite list.
	void addSprite(std::string path, int side_x, int side_y, int posx,
		       int posy) {
		sprite s(side_x, side_y);
		 s.loadSprite(path);
		 s.setPosition(posx, posy);
		 sprite_vec.push_back(s);
}};

class application:public pixelMap {
	std::vector < layer > layer_vec;
	//contains the set of rules that are called each frame.
	std::vector < RULE * >rule_book;
	std::vector < sf::Keyboard::Key > key_vec;
	std::vector < void (*)(application *) > fun_vec;

	//internal function for rules callback
	void rulesEnforcer(std::vector < uint8_t > &map) {
		for (auto r:rule_book) {
			r(map);
		}
	}
	//returns the bounds of the part of a sprite that is visible
	    auto pixelCuller(int topLeftX, int topLeftY, int dimx, int dimy) {
		struct returnDimensions {
			int a, b, c, d, x, y, z, h;
		};

		if (topLeftY > 64 || topLeftY + dimy < 0 || topLeftX > 255
		    || topLeftX + dimx < 0) {
			std::cout << "Zilch";
			return returnDimensions {
			0, 0, 0, 0, 0, 0, 0, 0};
		} else {
			//return the global coordinate covered by the sprite map
			int left = std::max(topLeftX, 0);
			int right = std::min(topLeftX + dimx, 64);
			int top = std::max(topLeftY, 0);
			int bottom = std::min(topLeftY + dimy, 64);

			//return the local coordinates of the sprite map to be used
			int local_top = topLeftY < 0 ? 0 - topLeftY : 0;
			int local_bottom =
			    topLeftY + dimy > 64 ? 64 - topLeftY : dimy;
			int local_left = topLeftX < 0 ? 0 - topLeftX : 0;
			int local_right =
			    topLeftX + dimx > 64 ? 64 - topLeftX : dimx;
			return returnDimensions {
			left, right, top, bottom,
			            local_left, local_right, local_top,
			            local_bottom};
		}

	}
	//assign sprite maps, noise maps, etc to the pixel array
	void mapper(std::vector < uint8_t > &map) {
		rulesEnforcer(map);
		for (auto x:layer_vec) {
			for (auto y:x.sprite_vec) {
				auto[topLeftX, topLeftY] = y.getPosition();
				auto[dimx, dimy] = y.getDimensions();
				auto[g_left, g_right, g_top, g_bottom, l_left,
				     l_right, l_top, l_bottom] =
				    pixelCuller(topLeftX, topLeftY, dimx, dimy);
				//-----variables used for iteration-------
				int i = 64 * g_top + g_left;
				int j = dimx * l_top + l_left;
				int line_characters_counter = 0;

				//--------------------------------------
				while (i < 64 * (g_bottom - 1) + g_right) {
					if (line_characters_counter ==
					    l_right - l_left) {
						i += 64 -
						    line_characters_counter;
						j += dimx - l_right + l_left;
						line_characters_counter = 0;
					} else {
						map[i] = y.at(j);
						line_characters_counter++;
						i++;
						j++;
					}
				}
			}
		}
	}
	void eventsExec() {
		for (int i = 0; i < key_vec.size(); i++) {
			if (sf::Keyboard::isKeyPressed(key_vec[i])) {
				fun_vec[i] (this);
			}
		}
	}

 public:
	void begin() {
		mainLoop();
	}
	//called to add new rules to the app
	void setRules(std::vector < RULE * >arg) {
		rule_book = arg;
	}
	void addKeyboardRule(sf::Keyboard::Key k,
		             void (*function)(application * app)) {
		key_vec.push_back(k);
		fun_vec.push_back(function);
	}
	void transformSpritePosition(int layer, int sprite, int movx, int movy) {
		layer_vec[layer].sprite_vec[sprite].transformPosition(movx,
		                                                      movy);
	}
	//called to add layers to the app
	void addLayer(layer arg) {
		layer_vec.push_back(arg);
	}
	int getNumberOfLayers() {
		return layer_vec.size();
	}
	layer layerAt(int i) {
		if (i >= layer_vec.size()) {
			throw
			    "Out of bounds call to layer vec. Returning NULL\n";
		} else {
			return layer_vec[i];
		}
	}
	static sf::Keyboard::Key key(std::string name) {
		for (int i = 0; i < name.length(); i++) {
			std::tolower(name[i]);
		}
		if (name == "left")
			return sf::Keyboard::Left;
		else if (name == "right")
			return sf::Keyboard::Right;
		else if (name == "up")
			return sf::Keyboard::Up;
		else if (name == "down")
			return sf::Keyboard::Down;
		else {
			std::cout << "Invalid Key\n";
			return sf::Keyboard::Up;
		}
	}
};

#endif
