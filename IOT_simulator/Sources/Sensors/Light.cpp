/*
 * @author Dumez_Ange
 * @file Light.cpp
 * @date 04/10/2021
 * @brief Light sensor
 */


#include "Light.hpp"


Light::Light(){m_data = aleaGenVal(2);}; // intialize the attribute corresponding to the light (1/0)

Light::Light(const Light &tmp){m_data = tmp.m_data;}; // initialize with another attribute

Light::~Light(){};

Light& Light::operator=(const Light &tmp){return *this;};

bool Light::getData()
{

	if (m_data == true) // setting up some probability for the light to be On/Off
	{

		if (aleaGenVal(100) <= 90) //
		{
			m_data = true; //	if the light is On there are 90% chances that it will remains On
		}
		else //
		{
			m_data = false; // 10% chances that it turns Off
		}

	}
	else if(m_data == false) // setting up some probability for the light to be On/Off
	{

		if (aleaGenVal(100) <= 90) //
		{
			m_data = false; // if the light is Off there are 90% chances that it will remains Off
		}
		else
		{
			m_data = true; // 10% chances that it turns On
		}

	}

	return m_data; // return the generated value (1/0) -> On/Off
}


