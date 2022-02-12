/**
 * @author Dumez_Ange
 * @file Sensor.hpp
 * @date 28/09/2021
 * @brief generates data
 */


#include  <random>
#include  <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "Sensor.hpp"

Sensor::Sensor(){};

Sensor::Sensor(const Sensor &sen){};

Sensor::~Sensor(){};

Sensor& Sensor::operator=(const Sensor &sen){return *this;};
/*
int Sensor::getData()
{
	return 0;
}
*/


int Sensor::aleaGenVal(const int &MAX)
{
	return rand()% MAX; // generates a random value between 0 and MAX - 1
}
