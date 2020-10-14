cd build
echo 'Running the build system..'
cmake --build .
cd ..
echo 'Formatting code..'
indent main.cpp include/pixel.h include/noise.h
rm main.cpp~ include/pixel.h~ include/noise.h~
