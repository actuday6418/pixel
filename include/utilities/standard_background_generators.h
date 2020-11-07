#include<cstdlib>

//encapsulates noise functions for generating random values in each pixel
class background {
 public:
	//the argument 'seed' must itself be random
	static void whiteNoise(std::vector < uint8_t > &array, const int seed) {
		srand(seed);
		for (int i = 0; i < array.size(); i++) {
			if (rand() % 2 == 0)
				array[i] = (uint8_t) 255;
			else
				array[i] = (uint8_t) 0;
		}
	}
	//use for generating plain white backgrounds
	    static void white(std::vector < uint8_t > &array) {
		for (int i = 0; i < array.size(); i++) {
			array[i] = 255;
		}
	}
	//use for generating plain black backgrounds
	static void black(std::vector < uint8_t > &array) {
		for (int i = 0; i < array.size(); i++) {
			array[i] = 0;
		}
	}
};
