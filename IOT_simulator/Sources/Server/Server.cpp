/**
 * @author Dumez_Ange
 * @file Server.hpp
 * @date 28/09/2021
 * @brief receives data form captors & stores/display them
 */

#include "Server.hpp"

#include <iostream>
#include <fstream>
#include <stdlib.h>


using namespace std;

Server::Server(){time(&now);m_date = ctime(&now);}; // initialize time and date

Server::~Server(){};

