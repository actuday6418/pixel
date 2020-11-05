#include<iostream>
#include "include/A1/application.h"
#include "include/utilities/noise.h"

using namespace std;

auto noise_gen =
    [](vector < uint8_t > &array) { noise::whiteNoise(array, rand());
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
	rule_set.push_back(noise_gen);
	app.logger();
	app.setRules(rule_set);
	app.begin();
}
