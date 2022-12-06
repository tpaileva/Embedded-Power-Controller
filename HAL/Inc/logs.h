/*
 * logs.h
 *
 *  Created on: May 20, 2020
 *      Author: t. pailevanian
 */

#ifndef LOGS_H_
#define LOGS_H_

#include "uart.h"

#include <string>
#include <stdio.h>
#include <stdint.h>

namespace Logs {

#ifdef LOG_UART

#define  LOG_OUTPUT(...)			Serial.WriteString(__VA_ARGS__)

#else // Log via Console

#define  LOG_OUTPUT(...)			printf(__VA_ARGS__)

#endif

#define INFO_ENABLED		true
#define INFO_DISABLED		false
#define WARNING_ENABLED		true
#define WARNING_DISABLED	false
#define ERROR_ENABLED		true
#define ERROR_DISABLED		false
#define EXCEPTION_ENABLED	true
#define EXCEPTION_DISABLED	false
#define DEBUG_ENABLED		true
#define DEBUG_DISABLED		false
#define VERBOSE_ENABLED		true
#define VERBOSE_DISABLED	false


class Log {
public:
	Log(bool info_en, bool warning_en, bool error_en, bool exception_en,
			bool debug_en, bool verbose_en);

	static void Info(const char *log);
	static void Warning(const char *log);
	static void Error(const char *log);
	static void Exception(const char *log);
	static void Debug(const char *log);
	static void Verbose(const char *log);

	template <typename T>
	static void Info(const char *log, T var);
	static void Warning(const char *log, auto var);
	static void Error(const char *log, auto var);
	static void Exception(const char *log, auto var);
	static void Debug(const char *log, auto var);
	static void Verbose(const char *log, auto var);

	static void SetInfoEnabled(bool status);
	static void SetWarningEnabled(bool status);
	static void SetErrorEnabled(bool status);
	static void SetExceptionEnabled(bool status);
	static void SetDebugEnabled(bool status);
	static void SetVerboseEnabled(bool status);

private:

	static void PrintToLog(const char * log_type, const char *log);
	static void PrintToLog(const char * log_type, const char *log, float var);
	static void PrintToLog(const char * log_type, const char *log, int var);
	static void PrintToLog(const char * log_type, const char *log, unsigned int var);
	static void PrintToLog(const char * log_type, const char *log, uint8_t var);
	static void PrintToLog(const char * log_type, const char *log, int8_t var);
	static void PrintToLog(const char * log_type, const char *log, uint16_t var);
	static void PrintToLog(const char * log_type, const char *log, int16_t var);
	static void PrintToLog(const char * log_type, const char *log, int32_t var);
	static void PrintToLog(const char * log_type, const char *log, uint32_t var);
	static void PrintToLog(const char * log_type, const char *log, bool var);

	static bool info_enabled_;
	static bool warning_enabled_;
	static bool error_enabled_;
	static bool exception_enabled_;
	static bool debug_enabled_;
	static bool verbose_enabled_;

	static std::string error_;
    static std::string debug_;
    static std::string info_;
    static std::string exception_;
    static std::string verbose_;
    static std::string warning_;

};

} /* namespace Logs */


#endif /* LOGS_H_ */
