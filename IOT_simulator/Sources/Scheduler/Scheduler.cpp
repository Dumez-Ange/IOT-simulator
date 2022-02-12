/**
 * @author Dumez_Ange
 * @file Scheduler.hpp
 * @date 28/09/2021
 * @brief organize sensors and server
 */

#include <iostream>

#include "Scheduler.hpp"

#ifdef _WIN64
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

Scheduler::Scheduler()
{

	m_Life = DEFAULT_LIFE;

	m_TmpFrequency = DEFAULT_TMP_FREQUENCY;
	m_HmyFrequency = DEFAULT_HMY_FREQUENCY;
	m_PrsFrequency = DEFAULT_PRS_FREQUENCY;
	m_LightFrequency = DEFAULT_LIGHT_FREQUENCY;

	m_writeFile = true;
	m_writeConsole = true;

	time(&m_now);
	m_time = localtime(&m_now);


	m_Temperature = objTemperature.getData();
	m_Humidity = objHumidity.getData();
	m_Light = objLight.getData();
	m_Pressure = objPressure.getData();

	thread t1(&Scheduler::function<float,Temperature>, this, ref(m_Temperature), ref(objTemperature), "Logs/Temperature.log", 'T', m_TmpFrequency);
	thread t2(&Scheduler::function<float, Humidity>, this, ref(m_Humidity), ref(objHumidity), "Logs/Humidity.log", 'H', m_HmyFrequency);
	thread t3(&Scheduler::function<bool, Light>, this, ref(m_Light), ref(objLight), "Logs/Light.log", 'H', m_LightFrequency);
	thread t4(&Scheduler::function<int, Pressure>, this, ref(m_Pressure), ref(objPressure), "Logs/Pressure.log", 'H', m_PrsFrequency);

	try
	{
		cout << "We are collecting data from sensors" << endl << endl << endl;
	}
	catch (...)
	{
		t1.join();
		t2.join();
		t3.join();
		t4.join();
		throw;
	}

	t1.join();
	t2.join();
	t3.join();
	t4.join();
}

Scheduler::~Scheduler(){};

void Scheduler::shared_print()
{
	std::lock_guard<std::mutex> guard(mu);

	time(&m_now);
	m_time = localtime(&m_now);

	cout << "Time : " << m_time->tm_hour << ":" << m_time->tm_min << ":" << m_time->tm_sec << endl << endl << endl;

	serv.consoleWrite<float>(m_Temperature, 'T');
	serv.consoleWrite<int>(m_Pressure, 'P');
	serv.consoleWrite<float>(m_Humidity, 'H');
	serv.consoleWrite<bool>(m_Light, 'L');

	cout << endl << endl << endl << "--------------------" << endl << endl << endl;
}
