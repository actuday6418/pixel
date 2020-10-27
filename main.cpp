#include "include/A0/pixel.h"
#include<iostream>
#include "include/utilities/noise.h"
#include "include/utilities/sprite.h"
#include<chrono>
#include<cstdlib>

void
white_noise_mapper (uint8_t array[4096])
{
  uint8_t array_temp[256];
  for (int i = 0, j = 0; i <= 4096; i++, j++)
    {
      if (j == 256)
	{
	  noise::whiteNoise (array_temp, rand ());
	  j = 0;
	  for (int k = i - 256, l = 0; k < i; k++, l++)
	    {
	      array[k] = array_temp[l];
	    }
	}
      array_temp[j] = array[i];
    }
}

int
main ()
{
  sprite s (16);
  if (s.loadSprite ("output.sprite") == -1)
    {
      std::cout << "ERR" << std::endl;
      return -1;
    }
  for (int i = 0; i < 256; i++)
    {
      std::cout << s.next () << std::endl;
    }
  pixelMap map;
  srand (45);
  map.setTitle ("Title");
  map.setFPS (60);
  map.start (white_noise_mapper);
  return 0;
}
