
/**
 * @author Dumez_Ange
 * @file Server.hpp
 * @date 28/09/2021
 * @brief receives data form captors & stores/display them
 */

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include <string>
#include <ctime>
#include <fstream>
#include <iostream>

/**
 * @class Server
 * @brief receives data form captors & stores/display them
 */

class Server
{

private:

	time_t now; ///< actual computer time
	char *m_date; ///< date and time stored in this attribute

public:

	/**
	 * @brief default constructor
	 */
	Server();

	/**
	 * @brief destructor
	 */
	virtual ~Server();

	/**
	 * @brief display data in console
	 * @param data, type of the data ('T'/'H'/'P'/'L')
	 */
	template <class T>
	void consoleWrite(const T p_data, const char p_type)
	{
		switch(p_type) // determines what to display depending the receiving type
			{
			case 'T': // Temperature
			{
				std::cout << "Temperature : ";
				std::cout << p_data << " °C" << std::endl;
			}
			break;

			case 'H': // Humidity
			{
				std::cout << "Humidity : ";
				std::cout << p_data << " %" << std::endl;
			}
			break;

			case 'P': // Presure
			{
				std::cout << "Pressure : ";
				std::cout << p_data << " bars" << std::endl;
			}
			break;

			case 'L': // Light
			{
				std::cout << "Light : ";

				if(p_data)	// display On/Off depending of the received value
				{
					std::cout << "ON" << std::endl; //
				}
				else if(p_data == false) //
				{
					std::cout << "OFF" << std::endl; //
				}
			}
			break;

			default:
			{
				std::cout << "WARNING !! UNKOWN TYPE : ";
			}
			break;

			}

	}

	/**
	 * @brief write data in log file
	 * @param data, file directory,  type of the data ('T'/'H'/'P'/'L')
	 */
	template <class T>
	void fileWrite(const T p_data, const std::string p_file, char p_type)
	{
		std::ofstream stream(p_file.c_str(), std::ios::app); // open a stream to the given file, write at the end

			if(stream) // checking if the file open correctly
			{
				time(&now); //initialize date and time
				m_date = ctime(&now); //

				stream << m_date << " : "; // write the date in the file

				switch(p_type) // determines what to write depending the receiving type
				{
					case 'T': // Temperature
					{
						stream << p_data << "°C";
					}
					break;

					case 'H': // Humidity
					{
						stream <<p_data << "%";
					}
					break;

					case 'P': // Pressure
					{
						stream << p_data << " bars";
					}
					break;

					case 'L': // Light
					{
						if(p_data) // write On/Off depending off the valeu(1/0) received
						{
							stream << "ON"; //
						}
						else if(p_data == false) //
						{
							stream << "OFF"; //
						}
					}
					break;

					default:
					{
						stream << "WARNING !! UNKOWN TYPE";
					}
					break;

					}

				stream << std::endl;
				stream << "-----------------" << std::endl;

			}
			else
			{
				std::cout << "ERROR unable to open file." << std::endl;
			}
	}


};


#endif /* SERVER_HPP_ */
