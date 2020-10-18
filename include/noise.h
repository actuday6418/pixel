#include<iostream>
#include<cstdlib>

class noise
{
public:
  static void whiteNoise (uint8_t array[256], const int seed)
  {
    srand (seed);
    for (int i = 0; i < 256; i++)
      {
	if (rand () % 2 == 0)
	  array[i] = (uint8_t) 255;
	else
	  array[i] = (uint8_t) 0;
      }
  }
};
