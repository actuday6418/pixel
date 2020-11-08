//I don't think this builds
#include "include/A0/pixel.h"
#include<iostream>
#include "include/utilities/noise.h"
#include "include/utilities/sprite.h"
#include<chrono>
#include<cstdlib>

class app:public pixelMap {
	void mapper(std::vector < uint8_t > &array) {
		noise::whiteNoise(array, rand());
}};

int main()
{
	app map;

	srand(45);
	map.setTitle("Title");
	map.setFPS(60);
	map.logger();
	map.mainLoop();
	return 0;
}
