# pixel
An implementation on top of SFML for efficiently rendering pixel formats and for making video games. Really easily. But not a lot of vide games. It's pretty sparse right now.

![pixelatedlady](https://user-images.githubusercontent.com/56124831/98348711-1b6ba500-203f-11eb-933d-a4db1585a850.png)


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
