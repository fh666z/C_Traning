/*
 * main.cpp
 *
 *  Created on: 1.06.2015 �.
 *      Author: Momchil
 */

#include <iostream>

#include <stdio.h>
#include "Ex7.hpp"

using namespace std;



int main(void)
{
	// Patch for Eclipse CDT console
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

    Ex7_test();

    cout << flush;
	return 0;
}


