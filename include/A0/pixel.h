#ifndef PIXEL_H
#define PIXEL_H

#include<SFML/Graphics.hpp>
#include<iostream>

class pixelMap
{
  sf::VertexArray varray;
  sf::RenderWindow window;
  bool log;

  //default value is sixty
  int FPS;

public:
    pixelMap ():varray (sf::Quads, 16384), window (sf::VideoMode (640, 640),
						   "New Window")
  {
    setPositions ();
    FPS = 60;
    log = false;
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
  void logger ()
  {
    log = true;
  }
  //contains main loop
  void start (void (*mapper) (uint8_t[4096]))
  {
    sf::Clock clock;
    uint8_t tick = 1;
    int delta = 0, prev_sec = 0, new_sec;
    while (window.isOpen ())
      {
	if (tick == FPS && log)
	  {
	    new_sec = (int) clock.getElapsedTime ().asSeconds ();
	    delta = new_sec - prev_sec;
	    std::cout << "Time to " << FPS << " frames: " << delta << std::
	      endl;
	    tick = 1;
	  }
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
	tick++;
      }
  }
  //called once to set positions of each pixel
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
  //the argument mapper is a function pointer to a function that returns an array of uint8_t 
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
	else
	  {
	    varray[k].color = sf::Color::White;
	    varray[k + 1].color = sf::Color::White;
	    varray[k + 2].color = sf::Color::White;
	    varray[k + 3].color = sf::Color::White;
	  }
      }
  }
};
#endif
