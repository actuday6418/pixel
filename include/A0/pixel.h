#ifndef PIXEL_H
#define PIXEL_H

#include<SFML/Graphics.hpp>
#include<iostream>

class pixelMap
{
protected:
  sf::VertexArray varray;
  sf::RenderWindow window;
  //default value is sixty
  int FPS;

public:
    pixelMap ():varray (sf::Quads, 16384), window (sf::VideoMode (640, 640),
						   "New Window")
  {
    setPositions ();
    FPS = 60;
  };

  void setTitle (const std::string & title)
  {
    window.setTitle (title);
  }
  void setFPS (unsigned int FPS)
  {
    window.setFramerateLimit (FPS);
    this->FPS = FPS;
  }
  //virtual function that has to be overriden by the user for updating pixel map each frame.
  virtual void mapper (std::vector < uint8_t > &array) = 0;
  virtual void eventsExec (int frame) = 0;

  //contains main loop
  void mainLoop ()
  {
    sf::Clock clock;
    int tick = 1;
    int delta = 0, prev_sec = 0, new_sec;
    int frame = 1;

    while (window.isOpen ())
      {
	eventsExec (frame);
	sf::Event event;
	while (window.pollEvent (event))
	  {
	    if (event.type == sf::Event::Closed)
	      window.close ();
	  }

	window.clear ();
	setColors ();
	window.draw (varray);
	window.display ();
	if (frame == FPS)
	  {
	    frame = 1;
	  }
	else
	  {
	    frame++;
	  }
      }
  }
  //called once during construction to set positions of each pixel
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
  //called every frame to set color of each pixel.
  void setColors ()
  {
    std::vector < uint8_t > array (4096, 0);
    mapper (array);
    for (int k = 0, i = 0; k < 16384; k += 4, i++)
      {
	varray[k].color =
	  sf::Color (array[i], array[i], array[i], (uint8_t) 255);
	varray[k + 1].color =
	  sf::Color (array[i], array[i], array[i], (uint8_t) 255);
	varray[k + 2].color =
	  sf::Color (array[i], array[i], array[i], (uint8_t) 255);
	varray[k + 3].color =
	  sf::Color (array[i], array[i], array[i], (uint8_t) 255);
      }
  }
};
#endif
