# pixel

Pixel is a set of utilities on top of SFML for efficiently making video games. But not a lot of video games, cause it's pretty sparse right now. The code base is designed to be modular and easily hackable. Look at main.cpp for a detailed explanation on using the engine.

Here's a demo of main.cpp running. There's a white noise background on top of which a sprite has been loaded and controlled with the keyboard, with sounds.

![demo](https://user-images.githubusercontent.com/56124831/98981888-8f78e200-2544-11eb-8dfc-2d7bfa936dda.gif)


# Building
    chmod a+x give_me_exec.sh
    mkdir build
    cd build
    cmake ..
    cmake --build .
    
#  Incremental builds
```./give_me_exec.sh```
This script builds the app and performs code formatting. 

# Using the framework
The backest backend basically takes a vector of numbers representing the value of saturation for each pixel, and renders it. You may use this lower level interface by extending the pixelMap class. The application class wraps around pixelMap, provides functionality for sprites and keyboard events (TODO). Look at main.cpp for an example that uses this layer of abstraction.

# The sprite format
Check out sprite.md. Sprite files contain metatadata and color values for a sprite a user would like to use in an app.

# Dependencies 
1. SFML
```apt install libsfml-dev```
2. GNU indent (For code formatting)
```apt install indent```
