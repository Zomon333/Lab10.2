/**
*@file logger.h
*@brief Lab 10.2
*@note : This code is almost an exact copy of what was shown in the File Output Part 2 video; Only reason I write myself as the author is because
*        I'll likely end up writing the actual function definition, and I manually copied this. If not, I'll credit you there too. 
*@author Dagan Poulin
*@assignment Lab 10.2
*@date 11/12/2020
*
*@credit "Bilbo Baggins" - AKA Devin Paden
*/
#ifndef LOGGER_H
#define LOGGER_H
#include <string>
#include <fstream>
#include <iostream>
#include <pwd.h>
#include <unistd.h>
#include <libgen.h>

/**
*@brief Creates a discrete syslog message
*@date 11/12/2020
*@return returns a boolean indicating the message was written ok
*@param msg std:string containing syslog message
*@param logFile ofstream reference, validation of this file is expected
*@param strProgramname std::string containing the program name
*/
bool log(std::string msg, std::ofstream& logFile, std::string strProgramName);
#endif