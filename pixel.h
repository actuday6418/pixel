#ifndef PIXEL_H
#define PIXEL_H

#include<SFML/Graphics.hpp>

class pixelMap
{
  sf::VertexArray varray;
  sf::RenderWindow window;

public:
  pixelMap ():varray (sf::Quads, 16384), window (sf::VideoMode (640, 640),
						 "New Window")
  {
    setPositions ();
  };
  void setTitle (const std::string & title)
  {
    window.setTitle (title);
  }
  void setFPS (unsigned int FPS)
  {
    window.setFramerateLimit (FPS);
  }
  void start (void (*mapper) (uint8_t[4096]))
  {
    while (window.isOpen ())
      {
	sf::Event event;
	while (window.pollEvent (event))
	  {
	    if (event.type == sf::Event::Closed)
	      window.close ();
	  }

	window.clear ();
	setColors (mapper);
	window.draw (varray);
	window.display ();
      }
  }
  void setPositions ()
  {
    for (int k = 0; k < 16384; k += 4)
      {
	int i = (k % 256) / 4;
	int j = k / 256;
	varray[k].position = sf::Vector2f (i * 10, j * 10);
	varray[k + 1].position = sf::Vector2f (i * 10 + 10, j * 10);
	varray[k + 2].position = sf::Vector2f (i * 10 + 10, j * 10 + 10);
	varray[k + 3].position = sf::Vector2f (i * 10, j * 10 + 10);
      }
  }
  void setColors (void (*mapper) (uint8_t[4096]))
  {
    uint8_t array[4096];
    (*mapper) (array);
    for (int k = 0, i = 0; k < 16384; k += 4, i++)
      {
	if (array[i] == 0)
	  {
	    varray[k].color = sf::Color::Black;
	    varray[k + 1].color = sf::Color::Black;
	    varray[k + 2].color = sf::Color::Black;
	    varray[k + 3].color = sf::Color::Black;
	  }
      }
  }
};
#endif
