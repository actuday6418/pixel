#include<iostream>
#include "include/A1/application.h"
#include "include/utilities/standard_background_generators.h"

using namespace std;

auto black_gen =[](vector < uint8_t > &array) { background::black(array);
	return true;
};

auto noise_gen =
    [](vector < uint8_t > &array) { background::whiteNoise(array, rand());
	return true;
};

class my:public application {
	void tickTok() override {
}};

int main()
{
	my app;

	srand(43);
	vector < RULE * >rule_set;
	rule_set.push_back(black_gen);
	rule_set.push_back(noise_gen);
	app.setRules(rule_set);
	layer lay;

	lay.addSprite("white.sprite", 3, 3, 0, 0);
	//app.addLayer(lay);
	app.begin();
}
