#include<fstream>
#include<cstdlib>
#include<iostream>

int main(int argc, char* argv[]){
	
	//Check for seed argument
	if(argc != 3){
		std::cout<<"You've entered "<<argc - 1<<" argument(s). Enter a number for random seeding, and the output file name! => ./noise 123 output.picc\n";
		return -1;
	}

	//Generate seed
	std::ofstream file(argv[2], std::ios::binary | std::ios::out);
	int seed = std::strtol(argv[1],nullptr,10);
	
	//seed random engine
	std::srand(seed);

	//generate and write noise
	for(int i = 0;i<256;i++){
		if((std::rand()%256)%2 == 0)
			file<<(uint8_t)255;
		else
			file<<(uint8_t)0;
	}
}
