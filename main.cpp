#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Delay.h"

int main(int argc, char *argv[])
{
	srand(time(NULL));
    Delay train;

	cout << train.description();
}