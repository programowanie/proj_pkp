#pragma once

#include <string>
#include <vector>

using namespace std;

class Delay
{
    vector <string> reasons;

	int _lengthRoute; 
	int _time;
	int _terribleWeather;
	int _lackOfLuck;

    void init();

public:
    Delay();

	int lengthRoute() { return _lengthRoute; }
	int time() { return _time; }
	int terribleWeather() {return _terribleWeather;}
	int lackOfLuck() {return _lackOfLuck;}

	int numberCauses();
	string refund();
	string mood();
	int rating();

	string description();
};
