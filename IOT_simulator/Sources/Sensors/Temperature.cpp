/*
 * @author Dumez_Ange
 * @file Temperature.cpp
 * @date 04/10/2021
 * @brief Temperature sensor
 */


#include "Temperature.hpp"


Temperature::Temperature(){m_data = aleaGenVal<float>(15, 30);}; // initialize the attribute

Temperature::Temperature(const Temperature &tmp){m_data = tmp.m_data;}; // initialize the attribute with another one

Temperature::~Temperature(){};

Temperature& Temperature::operator=(const Temperature &tmp){return *this;};

float Temperature::getData()
{

	m_data = aleaGenVal<float>(m_data - 3, m_data + 3); // generates random value in the interval [previous data - 1; previous data + 1]

	if (m_data < 15) //setting up limits to the random value
	{
		m_data = 15; //
	}
	else if (m_data > 30) //
	{
		m_data = 30; //
	}

	return m_data;
}

