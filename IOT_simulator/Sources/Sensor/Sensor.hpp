/**
 * @author Dumez_Ange
 * @file Sensor.hpp
 * @date 28/09/2021
 * @brief a global description of a sensor
 */

#ifndef SENSOR_HPP_
#define SENSOR_HPP_

#include  <random>
#include  <stdlib.h>

/**
 * @class Sensor
 * @brief a global description of a sensor
 */

class Sensor
{


public :

	/**
	 * @brief default constructor
	 */
	Sensor();

	/*
	 * @brief destructor
	 */
	virtual ~Sensor();

	/*
	 * @brief copy constructor
	 * @param another sensor
	 */
	Sensor(const Sensor &sen);

	/*
	 * @brief assignment operator
	 * @param another sensor
	 */
	Sensor & operator=(const Sensor &sen);

	/*
	 * @brief getter
	 */
	//virtual int getData();

protected :
	/**
	 * @brief generates a random value within the given interval
	 * @param minimum, maximum
	 */
	template <class T>
	T aleaGenVal(const T &min,const T &max)
	{
		return min + static_cast <T>(rand()) /(static_cast <T>(RAND_MAX/(max-min)));
	}

	/**
	 * @brief generates a random value in the interval [0,given maximum]
	 * @param maximum
	 */
	int aleaGenVal(const int &max);

};

#endif /* SENSOR_HPP_ */
