/*
 * Logger.cpp
 *
 *  Created on: 14 sty 2016
 *      Author: dpilarsk
 */

#include "Logger.h"

using namespace std;

Logger::Flush Logger::flush;

Logger::Logger() : m_outputFile(){
    m_outputFile.open("Log.txt", std::ios::out);
}

Logger& Logger::operator ()(enum LogType type){
    switch(type){
    case INFO:
        m_outputStream << std::string("\t\t INFO \t\t ");
        break;
    case WARN:
        m_outputStream << std::string("\t\t WARNING \t\t ");
        break;
    case ERROR:
        m_outputStream << std::string("\t\t ERROR \t\t ");
        break;
    default:
        m_outputStream << std::string("\t\t UNKNOWN \t\t");
    }

    return *this;
}

Logger& Logger::operator<< (const Logger::Flush&){
#ifndef NDEBUG
    m_outputFile << m_outputStream.str() << std::endl;
    m_outputStream.str("");
#endif
    return Logger::instance();
}

Logger::~Logger(){
    if(m_outputFile.is_open())
        m_outputFile.close();
}
