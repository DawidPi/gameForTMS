/*
 * Logger.h
 *
 *  Created on: 14 sty 2016
 *      Author: dpilarsk
 */

#ifndef SRC_LOGGER_LOGGER_H_
#define SRC_LOGGER_LOGGER_H_

#include "singleton.hpp"
#include <string>
#include <fstream>
#include <sstream>
#define NDEBUG
//#define DETAILED

class Logger : public Singleton<Logger> {
public:
    enum LogType{INFO, WARN, ERROR};
    struct Flush{};
    static Flush flush;
    Logger();
    ~Logger();
    Logger& operator()(LogType type);
    template <typename T>
    Logger& operator << (const T& message);
    Logger& operator << (const Flush&);
private:
    std::ofstream m_outputFile;
    std::stringstream m_outputStream;
};

template <typename T>
Logger& Logger::operator <<(const T& message){
#ifndef NDEBUG
    m_outputStream << message;
#endif
    return Logger::instance();
}

#define LOG_INFO(message) (Logger::instance()(Logger::INFO) << "\n[" <<  __FILE__ <<"][" << __LINE__ <<"][" << __PRETTY_FUNCTION__ << "]\t\t\t"<<message<<"\n"<<Logger::flush)
#define LOG_WARN(message) (Logger::instance()(Logger::WARN) << "\n[" <<  __FILE__ <<"][" << __LINE__ <<"][" << __PRETTY_FUNCTION__ << "]\t\t\t" <<message<<"\n"<<Logger::flush)
#define LOG_ERROR(message) (Logger::instance()(Logger::ERROR) << "\n[" <<  __FILE__ <<"][" << __LINE__ <<"]["<< __PRETTY_FUNCTION__ << "]\t\t\t"<<message<<"\n"<<Logger::flush)

#ifdef DETAILED
#define LOG_DETAILED(message) (Logger::instance()(Logger::INFO) << "\n[" <<  __FILE__ <<"][" << __LINE__ <<"][" << __PRETTY_FUNCTION__ << "]\t\t\t"<<message<<"\n"<<Logger::flush)
#else
#define LOG_DETAILED(message) ;
#endif

#endif /* SRC_LOGGER_LOGGER_H_ */
