/**
 * @author Dumez_Ange
 * @file Scheduler.hpp
 * @date 28/09/2021
 * @brief organize sensors and server
 */

#ifndef SCHEDULER_HPP_
#define SCHEDULER_HPP_

#include <thread>
#include <mutex>
#include <string>

#include "../Server/Server.hpp"
#include "../Sensor/Sensor.hpp"
#include "../Sensors/Temperature.hpp"
#include "../Sensors/Pressure.hpp"
#include "../Sensors/Humidity.hpp"
#include "../Sensors/Light.hpp"

#ifdef _WIN64
#include <windows.h>
#else
#include <unistd.h>
#endif

/**
 * @enum DEFAULT_LIFE
 * @brief set a default lifetime to the scheduler
 */
enum {DEFAULT_LIFE = 10};

/**
 * @enum DEFAULT_FREQUENCY
 * @brief set a default frequency to get the data
 */
enum {DEFAULT_FREQUENCY = 5000};


/**
 * @class Scheduler
 * @brief the Scheduler get the data from the sensors and send them to the server
 */
class Scheduler
{

private :


	int m_Life;
	int m_TmpFrequency;
	int m_HmyFrequency;
	int m_PrsFrequency;
	int m_LightFrequency;

	bool m_writeFile;
	bool m_writeConsole;

	float m_Humidity; ///< Humidity percentage
	bool m_Light; ///< Light value 1/0 (On/Off)
	int m_Pressure; ///< Pressure outside the submarine
	float m_Temperature; ///< Temperature inside the submarine

	Temperature objTemperature; ///< Temperature sensor
	Light objLight; ///< Light sensor
	Pressure objPressure; ///< Pressure sensor
	Humidity objHumidity; ///< Humidity sensor

	Server serv; ///< Scheduler server

	std::mutex mu;

	time_t m_now;
	tm *m_time;

	enum {DEFAULT_TMP_FREQUENCY = 3000};
	enum {DEFAULT_HMY_FREQUENCY = 3000};
	enum {DEFAULT_PRS_FREQUENCY = 3000};
	enum {DEFAULT_LIGHT_FREQUENCY = 3000};
	enum {DEFAULT_LIFE = 20000};

public:

	/**
	 * @brief default constructor
	 */
	 Scheduler();

	 /*
	  * @brief copy constructor
	  */
	 Scheduler(const Scheduler &sch);

	 /*
	  * @brief destructor
	  */
	 virtual ~Scheduler();

	 /*
	  * @breif assignment operator
	  */
	 Scheduler & operator=(const Scheduler &sch);

	 /**
	  * @brief
	  */
	 template<class T, class S>
		 void function(T& p_data,S& obj, const std::string p_file, char p_type, int p_frequency)
		 {
			 for (int i = 0; i < (m_Life / p_frequency); i++)
			 	 	{

				 	 	 auto now = std::chrono::system_clock::now();

				 	 	 std::this_thread::sleep_until(now + std::chrono::seconds(p_frequency/1000));

				 	 	 p_data = obj.getData();


				 	 	 if (m_writeFile)
				 	 	 {
				 	 		 serv.fileWrite<T>(p_data, p_file, p_type);
				 	 	 }

				 	 	 if (m_writeConsole)
				 	 	 {
				 	 		 Scheduler::shared_print();
				 	 	 }

			 		}

		 }

	 /**
	  * @brief
	  */
	 void shared_print();


};

#endif /* SCHEDULER_HPP_ */
