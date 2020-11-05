
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
	indent -bad -bap -as -ce -linux main.cpp include/A0/pixel.h include/utilities/standard_background_generators.h include/A1/application.h include/A1/sprite.h
	rm main.cpp~ include/A0/pixel.h~ include/utilities/standard_background_generators.h~ include/A1/application.h~ include/A1/sprite.h~
	echo 'Running executable..'
	./build/app
else
	cd ..
	echo "${red}Build failed!"
fi
