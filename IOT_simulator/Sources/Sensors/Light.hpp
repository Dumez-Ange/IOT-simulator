/*
 * @author Dumez_Ange
 * @file Light.cpp
 * @date 04/10/2021
 * @brief Light sensor
 */


#ifndef LIGHT_HPP_
#define LIGHT_HPP_

#include "../Sensor/Sensor.hpp"

/**
 * @class Light
 * @brief Ligth sensor
 */
class Light : public Sensor {

private :

	bool m_data; ///< stores the random generated value

public :

	/**
	 * @brief constructor
	 */
	Light();

	/*
	 * @brief copy constructor
	 * @param another Light sensor
	 */
	Light(const Light &tmp);

	/**
	 * @brief destructor
	 */
	virtual ~Light();

	/**
	 * @brief assignment operator
	 * @param another Light sensor
	 */
	Light & operator=(const Light &tmp);

	/**
	 * @brief sensor getter
	 * @return returns the random generated value
	 */
	bool getData();// override;



};



#endif /* LIGHT_HPP_ */
