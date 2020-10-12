#include "pixel.h"
#include<fstream>
#include<iostream>

void
mapper (uint8_t array[4096])
{
  std::ifstream file ("output.picc", std::ios::binary | std::ios::in);
  uint8_t x;
  int i = 0;
  while (!file.eof ())
    {
      file.read (reinterpret_cast < char *>(&x), sizeof (x));
      array[i++] = x;
    }
  i -= 2;
  for (int j = i; j < 4096; j++)
    array[j] = 255;
}

int
main ()
{
  pixelMap map;
  map.setTitle ("Title");
  map.setFPS (2);
  map.start (mapper);
  return 0;
}
