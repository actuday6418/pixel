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
  void start ()
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
	setColors ();
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
  void setColors ()
  {
    for (int k = 0; k < 16384; k += 4)
      {
	varray[k].color = sf::Color::Red;
	varray[k + 1].color = sf::Color::Green;
	varray[k + 2].color = sf::Color::Blue;
	varray[k + 3].color = sf::Color::White;
      }
  }
};
#endif
