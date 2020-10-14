#include<cstdlib>
#include<iostream>

class noise
{
public:
  static void whiteNoise (uint8_t (&array)[256], const int seed)
  {
  for (auto x:array)
      {
	if ((std::rand () % 256) % 2 == 0)
	  x = (uint8_t) 255;
	else
	  x = (uint8_t) 0;
      }
  }
};
