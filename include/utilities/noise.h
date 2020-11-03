#include<cstdlib>

//encapsulates noise functions for generating random values in each pixel
class noise {
 public:
	//the argument 'seed' must itself be random
	static void whiteNoise(std::vector < uint8_t > &array, const int seed) {
		srand(seed);
		for (int i = 0; i < array.size(); i++) {
			if (rand() % 2 == 0)
				array[i] = (uint8_t) 255;
			else
				array[i] = (uint8_t) 0;
}}};
