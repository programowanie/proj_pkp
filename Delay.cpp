#include "Delay.h"
#include <stdlib.h>
#include <fstream>
#include <string.h>

void Delay::init()
{
    ifstream file("cause.csv");
    string tmpStorage = "";
    while (getline(file, tmpStorage)) {
        reasons.push_back(tmpStorage);
    }
	file.close();
}

int random (int min, int range) 
{
    return rand() % range + min;
}

Delay::Delay()
{
	_lengthRoute = { random(15, 435) };
	_terribleWeather = {random(1, 5)};
	_lackOfLuck = {random(1, 5)};

    init();
}

string Delay::description()
{	
    string reasonsString = "";
    for (int i = 0; i < numberCauses(); i++) 
    {
        int timeForReason = random(5, 70);
        reasonsString += "\n\t" + reasons[random(0, reasons.size())]  + " " + to_string(timeForReason) + " minut";
        _time += timeForReason;
    }

		return "Dlugosc trasy: " + to_string(_lengthRoute) + " km"
    	+ "\nZdarzenia losowe: " + reasonsString
    	+ "\nCzas opoznienia: " + to_string(_time) + " minut"
		+ "\nZwrot kosztow " + refund()
		+ "\nNastroj pasazerow jest " + mood()
		+ "\nOcena przejazdu: " + to_string(rating()) + "/5\n";
}

int Delay::numberCauses()
{
	return ((_lengthRoute / 100) + _terribleWeather + _lackOfLuck) / 3;
}

string Delay::refund()
{
	if (_lengthRoute >= 800 && _time >= 60 && _time <= 119)
		return "25% ceny biletu.";
	else if (_lengthRoute >= 241 && _time >= 120)
		return "50% ceny biletu.";
	else
		return "nie jest możliwy.";
}

string Delay::mood()
{
	if (_time <= 15)
		return "bardzo dobry";
	else if (_time > 15 && _time <= 45)
		return "dobry";
	else if (_time > 45 && _time <=90)
		return "umiarkowany";
	else if (_time > 90 && _time <= 150)
		return "zły";
	else 
		return "bardzo zły";
}

int Delay::rating()
{
	if (mood() == "bardzo dobry")
		return 5;
	else if (mood() == "dobry")
		return 4;
	else if (mood() == "umiarkowany")
		return 3;
	else if (mood() == "zły")
		return 2;
	else 
		return 1;
}
