/*
 * @author Dumez_Ange
 * @file Humidity.hpp
 * @date 04/10/2021
 * @brief Humidity sensor
 */


#include "Humidity.hpp"


Humidity::Humidity(){m_data = aleaGenVal<float>(40, 70);}; // initialize the attribute

Humidity::Humidity(const Humidity &tmp){m_data = tmp.m_data;}; // initialize the attribute with another one

Humidity::~Humidity(){};

Humidity& Humidity::operator=(const Humidity &tmp){return *this;};

float Humidity::getData()
{

	m_data = aleaGenVal<float>(m_data - 2, m_data + 2); // generates data in the interval [previous data - 2; previous data + 2]

	if (m_data < 40) // setting up limits to the random generation
	{
		m_data = 40; //
	}
	else if (m_data > 70) //
	{
		m_data = 70; //
	}

	return m_data;
}


