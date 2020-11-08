#include<iostream>
#include "include/A1/application.h"
#include "include/utilities/standard_background_generators.h"

using namespace std;

//First define whatever rules (functions that are run each frame of the game and modify the mapping. These are
//run before the sprite maps are evaluated.) you want
//as lambdas. Each rule must take a passed by reference vector of uint8_ts as an array 
//and return a boolean value that represents success / failure.

auto noise_gen =
    [](vector < uint8_t > &array) { background::whiteNoise(array, rand());
	return true;
};

void move_left(application * app)
{
	app->transformSpritePosition(0, 0, -1, 0);
}

void move_down(application * app)
{
	app->transformSpritePosition(0, 0, 0, 1);
}

void move_up(application * app)
{
	app->transformSpritePosition(0, 0, 0, -1);
}

void move_right(application * app)
{
	app->transformSpritePosition(0, 0, 1, 0);
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

	app.addKeyboardRule(application::key("left"), move_left);
	app.addKeyboardRule(application::key("up"), move_up);
	app.addKeyboardRule(application::key("down"), move_down);
	app.addKeyboardRule(application::key("right"), move_right);
	app.setTickFactor(2);
	lay.addSprite("white.sprite", 20, 20, 25, 25);
	//Add your layer to the application once you're done defining it.
	app.addLayer(lay);
	//Let the games begin!!
	app.begin();
}
