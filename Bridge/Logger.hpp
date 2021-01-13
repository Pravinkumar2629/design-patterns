/*
 * Logger.hpp
 *
 *  Created on: Jan 13, 2021
 *      Author: pravinkumar
 */

#ifndef LOGGER_HPP_
#define LOGGER_HPP_

class LoggerImpl;
class Logger{
	LoggerImpl *impl;
public:
	class RegistryHandler;
	RegistryHandler *reg_handler;

	Logger();
	~Logger();

	void Log(char *str);
};



#endif /* LOGGER_HPP_ */
