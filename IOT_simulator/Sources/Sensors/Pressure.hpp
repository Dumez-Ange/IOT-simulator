/*
 * @author Dumez_Ange
 * @file Pressure.hpp
 * @date 04/10/2021
 * @brief Pressure sensor
 */

#ifndef PRESSURE_HPP_
#define PRESSURE_HPP_

#include "../Sensor/Sensor.hpp"


/**
 * @class Pressure
 * @brief Pressure sensor
 */
class Pressure : public Sensor {

private :

	int m_data; ///< stores the generated data

public :

	/**
	 * @brief constructor
	 */
	Pressure();

	/**
	 * @brief copy constructor
	 * @param another Pressure sensor
	 */
	Pressure(const Pressure &tmp);

	/**
	 * @brief destructor
	 */
	virtual ~Pressure();

	/**
	 * @brief assignment operator
	 * @param another Pressure sensor
	 */
	Pressure & operator=(const Pressure &tmp);

	/**
	 * @brief sensor getter
	 * @return returns the random generated data
	 */
	int getData();// override;


};



#endif /* PRESSURE_HPP_ */
