/*
 * @author Dumez_Ange
 * @file Temperature.hpp
 * @date 04/10/2021
 * @brief Temperature sensor
 */

#ifndef TEMPERATURE_HPP_
#define TEMPERATURE_HPP_

#include "../Sensor/Sensor.hpp"

/**
 * @class Temperature
 * @brief Temperature sensor
 */
class Temperature : public Sensor {

private :

	float m_data; ///< stores the random generated value

public :

	/**
	 * @brief default constructor
	 */
	Temperature();

	/**
	 * @brief copy constructor
	 * @param another Temperature sensor
	 */
	Temperature(const Temperature &tmp);

	/**
	 * @brief destructor
	 */
	virtual ~Temperature();

	/**
	 * @brief assignment operator
	 * @param another Temperature sensor
	 */
	Temperature & operator=(const Temperature &tmp);

	/**
	 * @brief sensor getter
	 * @return returns the random generated value
	 */
	float getData();// override;



};

#endif /* TEMPERATURE_HPP_ */
