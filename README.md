# pixel
An framework for creating pixelated UIs / games. 

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
