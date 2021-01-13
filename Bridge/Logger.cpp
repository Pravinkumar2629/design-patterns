/*
 * Logger.cpp
 *
 *  Created on: Jan 13, 2021
 *      Author: pravinkumar
 */

#include "Logger.hpp"

class LoggerImpl {
	Logger *logger { };
public:
	LoggerImpl() = default;
	LoggerImpl(Logger *logger_) :
			logger(logger_) {

	}

	void log(char *str) {

	}
};

class Logger::RegistryHandler {
	Logger *logger { };
public:
	RegistryHandler() = default;
	~RegistryHandler() {
	}
	RegistryHandler(Logger *logger_);//:logger(logger_) {}
	void open_registry() {

	}
};

Logger::RegistryHandler::RegistryHandler(Logger *logger_) : logger(logger_)  {

}
//Logger::RegistryHandler::~RegistryHandler() {
//}
//
//void Logger::RegistryHandler::open_registry() {
//	// do what ever;
//}

Logger::Logger() :
		impl(new LoggerImpl(this)), reg_handler(new RegistryHandler(this)) {

}

Logger::~Logger() {
	delete impl;
}

void Logger::Log(char *str) {
	impl->log(str);
}
