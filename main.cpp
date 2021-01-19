#include<iostream>
#include "include/A1/application.h"
#include "include/utilities/background_generators.h"

using namespace std;

//First define whatever rules (functions that are run each frame of the game and modify the mapping. These are
//run before the sprite maps are evaluated.) you want
//as lambdas. Each rule must take a passed by reference vector of uint8_ts as an array 
//and return a boolean value that represents success / failure.

auto noise_gen =[](vector < uint8_t > &array) { background::white (array);
  return true;
};

//The next step is to define Keyboard rules. These are functions that are called when a Keyboard event 
//happens. Also illustrated within these functions are the call to playSound, which
//takes frequency, amplitude and no. of samples (duration) as arguments.
void
move_left (application * app)
{
  app->transformAnimatedSpritePosition (0, 0, -1, 0);
  app->playSound (440.0f, 1.0f, 1000);
}

void
move_down (application * app)
{
  app->transformAnimatedSpritePosition (0, 0, 0, 1);
  app->playSound (466.1f, 1.0f, 1000);
}

void
move_up (application * app)
{
  app->transformAnimatedSpritePosition (0, 0, 0, -1);
  app->playSound (392.0f, 1.0f, 1000);
}

void
move_right (application * app)
{
  app->transformAnimatedSpritePosition (0, 0, 1, 0);
  app->playSound (830.6f, 1.0f, 1000);
}

int
main ()
{
  application app;

  srand (43);
  //RULE is a function pointer type defined in application.h and representing
  //a rule lambda. Create a vector of RULE* and push your rules into it.
  vector < RULE * >rule_set;
  rule_set.push_back (noise_gen);
  app.setTickFactor (17);
  //set your RULE* vector to be the application rule set.
  app.setRules (rule_set);
  //Use layers and sprites to load, display and animate sprites.
  layer lay;

  app.addKeyboardRule (application::key ("left"), move_left);
  app.addKeyboardRule (application::key ("up"), move_up);
  app.addKeyboardRule (application::key ("down"), move_down);
  app.addKeyboardRule (application::key ("right"), move_right);
  lay.addAnimSprite ("animated.asprite", 8, 8, 0, 0, 2);
  //Add your layer to the application once you're done defining it.
  app.addLayer (lay);
  //Let the games begin!!
  app.begin ();
}
