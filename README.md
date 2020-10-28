# pixel
An implementation on top of SFML for efficiently rendering pixel formats like BMP/PMM. And for making video games.

# Building
    chmod a+x give_me_exec.sh
    mkdir build
    cd build
    cmake ..
    cmake --build .
    
#  Incremental builds
```./give_me_exec.sh```
This script builds the app and performs code formatting. 

# The sprite format
Check out sprite.md

# Dependencies 
1. SFML
```apt install libsfml-dev```
2. GNU indent (For code formatting)
```apt install indent```
