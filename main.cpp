#include<iostream>
#include "include/A1/application.h"
#include "include/A1/keyboard.h"
#include "include/utilities/standard_background_generators.h"

using namespace std;

//First define whatever rules (functions that are run each frame of the game) you want
//as lambdas. Each rule must take a passed by reference vector of uint8_ts as an array 
//and return a boolean value that represents success / failure.
auto noise_gen =
    [](vector < uint8_t > &array) { background::whiteNoise(array, rand());
	return true;
};

void print(application* app, void(application::*f)(int, int, int, int), int a, int b, int c, int d){
	app->*f(a,b,c,d);
}

int main()
{
	application app;

	srand(43);
	//RULE is a function pointer type defined in application.h and representing
	//a rule lambda. Create a vector of RULE* and push your rules into it.
	vector < RULE * >rule_set;
	rule_set.push_back(noise_gen);
	//set your RULE* vector to be the application rule set.
	app.setRules(rule_set);
	//Use layers and sprites to load, display and animate sprites.
	layer lay;

	lay.addSprite("white.sprite", 20, 20, 25, 25);
	print(&app, &application::setSpritePosition,0,0,0,0);
	//Add your layer to the application once you're done defining it.
	app.addLayer(lay);
	//Let the games begin!!
	app.begin();
}
