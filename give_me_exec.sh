
red=`tput setaf 1`
green=`tput setaf 2`
white=`tput setaf 7`

cd build
echo 'Running the build system..'
if cmake --build .
then 
	echo "${green}Build successful.."
	echo "${white}Formatting code.."
	cd ..
	indent main.cpp include/pixel.h include/noise.h
	rm main.cpp~ include/pixel.h~ include/noise.h~
	echo 'Running executable..'
	./build/app
else
	cd ..
	echo "${red}Build failed!"
fi
