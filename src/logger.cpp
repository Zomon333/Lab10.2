/**
 * @file logger.cpp
 * @brief Lab 10.2
 * Handles the definition of all logging functionality
 * @author Dagan Poulin
 * @assignment Lab 10.2
 * @date 11/12/2020
 * @credit "Bilbo Baggins" - AKA Devin Paden
 **/
#include "logger.h"

    const int STRINGCAP=250;

/**
*@brief Creates a discrete syslog message
*@date 11/12/2020
*@return returns a boolean indicating the message was written ok
*@param msg std:string containing syslog message
*@param logFile ofstream reference, validation of this file is expected
*@param strProgramname std::string containing hte pgoram name
*/
bool log(std::string msg, std::ofstream& logFile, std::string strProgramName)
{

    std::string strTime;

    //get the time
    time_t logTime = time(0);
    strTime = ctime(&logTime);

    //time off the newline
    int timeSize = strTime.size();
    if(timeSize)
    {
        strTime[timeSize-1] = ' ';
    }

    //get the pid
    pid_t pid = getpid();

    //get the hostname
    std::string strHostName;
    

    char hostName[STRINGCAP];
    gethostname(hostName, sizeof(hostName));
    strHostName = hostName;
    
    if(logFile)
    {
        //write the log
        logFile << strTime << strHostName << " " << strProgramName << "[" << pid << "]: " << msg << std::endl;
        return true;
    }
    else
    {
        return false;
    }
    
}