/*
 * @author Dumez_Ange
 * @file Humidity.hpp
 * @date 04/10/2021
 * @brief Humidity sensor
 */

#ifndef HUMIDITY_HPP_
#define HUMIDITY_HPP_



#include "../Sensor/Sensor.hpp"
/**
 * @class Humidity
 * @brief Humidity sensor
 */
class Humidity : public Sensor {

private :

	float m_data; ///< generated data

public :

	/**
	 * @brief default constructor
	 */
	Humidity();

	/**
	 * @brief copy constructor
	 * @param another Humidity sensor
	 */
	Humidity(const Humidity &tmp);

	/**
	 * @brief destructor
	 */
	virtual ~Humidity();

	/**
	 * @brief assignement operator
	 */
	Humidity & operator=(const Humidity &tmp);

	/**
	 * @brief sensor getter
	 * @return a random value within the given interval
	 */
	float getData();// override;



};

#endif /* HUMIDITY_HPP_ */
