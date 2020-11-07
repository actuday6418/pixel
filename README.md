# pixel

![pixelatedlady](https://user-images.githubusercontent.com/56124831/98348711-1b6ba500-203f-11eb-933d-a4db1585a850.png)

Pixel is the lady mascot depicted above, and an implementation on top of SFML for efficiently rendering pixel formats and for making video games. Really easily. But not a lot of video games, cause it's pretty sparse right now. The code base is designed to be modular and easily hackable. Look at main.cpp for a detailed explanation on using the engine.

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
