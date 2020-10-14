#include "include/pixel.h"
#include<iostream>
#include "include/noise.h"
#include<chrono>

void
mapper (uint8_t array[4096])
{
  uint8_t array_temp[256];
  for (int i = 0, j = 0; i < 4096; i++, j++)
    {
      if (j == 256)
	{
	  noise::whiteNoise (array_temp,
			     (int) std::chrono::system_clock::now ().
			     time_since_epoch ().count ());
	  j = 0;
	  for (int k = i - 256, l = 0; k < i; k++, l++)
	    array[i] = array_temp[l];
	}
      array_temp[j] = array[i];
    }
}

int
main ()
{
  pixelMap map;
  map.setTitle ("Title");
  map.setFPS (2);
  map.logger ();
  map.start (mapper);
  return 0;
}
