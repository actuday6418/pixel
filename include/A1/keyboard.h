#ifndef KEYBOARD_H
#define KEYBOARD_H
#include<SFML/Graphics.hpp>
#include<string>
#include<iostream>

class keyboard {
	static sf::Keyboard::Key key(std::string name){
		for(int i=0;i<name.length();i++){
			std::tolower(name[i]);
		}
		if(name == "left")
			return sf::Keyboard::Left;
		else if(name == "right")
			return sf::Keyboard::Right;
		else if(name == "up")
			return sf::Keyboard::Up;
		else if(name == "down")
			return sf::Keyboard::Down;
		else {
			std::cout<<"Invalid Key\n";
			return sf::Keyboard::Up;
		}
	}
	static 
};

#endif
