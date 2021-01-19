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

//Rule that makes gravity
void
gravity (application * app)
{
  if (app->getLayer (0)->asprite_vec[0].getPosition ().y != 56)
    {
      app->getLayer (0)->asprite_vec[0].transformPosition (0, 1);
    }
}

//The next step is to define Keyboard rules. These are functions that are called when a Keyboard event 
//happens. Also illustrated within these functions are the call to playSound, which
//takes frequency, amplitude and no. of samples (duration) as arguments.
void
move_left (application * app)
{
  app->getLayer (0)->asprite_vec[0].transformPosition (-1, 0);
  app->playSound (440.0f, 1.0f, 1000);
}

void
jump (application * app)
{
  app->getLayer (0)->asprite_vec[0].transformPosition (0, -3);
  app->playSound (392.0f, 1.0f, 1000);
}

void
move_right (application * app)
{
  app->getLayer (0)->asprite_vec[0].transformPosition (1, 0);
  app->playSound (830.6f, 1.0f, 1000);
}

int
main ()
{
  application app;

  srand (43);
  //RULE is a function pointer type defined in application.h and representing
  //a lambda that taked the entire map and applies some transformation to it.
  //add the canvas rule to the rule book
  app.addRule (noise_gen);
  app.addApplicationRule (gravity);
  //Use layers and sprites to load, display and animate sprites.
  layer lay;
  app.setFPS (30);

  app.addKeyboardRule (application::key ("left"), move_left);
  app.addKeyboardRule (application::key ("space"), jump);
  app.addKeyboardRule (application::key ("right"), move_right);
  lay.addAnimSprite ("animated.asprite", 8, 8, 0, 56, 2, 2);
  //Add your layer to the application once you're done defining it.
  app.addLayer (lay);
  //Let the games begin!!
  app.begin ();
}
