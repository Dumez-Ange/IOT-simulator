/*
 * @author Dumez_Ange
 * @file Pressure.cpp
 * @date 04/10/2021
 * @brief Pressure sensor
 */



#include "Pressure.hpp"


Pressure::Pressure(){m_data = aleaGenVal<int>(1, 40);}; // initialize the attribute

Pressure::Pressure(const Pressure &tmp){m_data = tmp.m_data;}; // initialize the attribute with another one

Pressure::~Pressure(){};

Pressure& Pressure::operator=(const Pressure &tmp){return *this;};

int Pressure::getData()
{

	m_data = aleaGenVal<int>(m_data - 5, m_data + 5); // generates a random value in the interval [previous data - 5; previous data + 5]

	if (m_data < 1) // setting up limits for the generated data
	{
		m_data = 1; //
	}
	else if (m_data > 40) //
	{
		m_data = 40; //
	}

	return m_data;
}


