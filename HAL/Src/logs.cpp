/*
 * logs.cpp
 *
 *  Created on: May 20, 2020
 *      Author: t. pailevanian
 */

#include "logs.h"

namespace Logs {

std::string Log::error_ 	= "$ERRROR : ";
std::string Log::debug_ 	= "$DEBUG : ";
std::string Log::info_ 		= "$INFO : ";
std::string Log::exception_ = "$EXCEPTION : ";
std::string Log::verbose_ 	= "$VERBOSE : ";
std::string Log::warning_ 	= "$WARNING : ";

bool Log::info_enabled_;
bool Log::warning_enabled_;
bool Log::error_enabled_;
bool Log::Log::exception_enabled_;
bool Log::debug_enabled_;
bool Log::verbose_enabled_;

Log::Log(bool info_en, bool warning_en, bool error_en, bool exception_en,
		bool debug_en, bool verbose_en) {

	info_enabled_ = info_en;
	warning_enabled_ = warning_en;
	error_enabled_ = error_en;
	exception_enabled_ = exception_en;
	debug_enabled_ = debug_en;
	verbose_enabled_ = verbose_en;
}

void Log::Info(const char *log) {
	if (info_enabled_) {
		PrintToLog(info_.c_str(), log);
	}
}

void Log::Warning(const char *log) {
	if (warning_enabled_) {
		PrintToLog(warning_.c_str(), log);
	}
}

void Log::Error(const char *log) {
	if (error_enabled_) {
		PrintToLog(error_.c_str(), log);
	}
}

void Log::Exception(const char *log) {
	if (exception_enabled_) {
		PrintToLog(exception_.c_str(), log);
	}
}

void Log::Debug(const char *log) {
	if (debug_enabled_) {
		PrintToLog(debug_.c_str(), log);
	}
}

void Log::Verbose(const char *log) {
	if (verbose_enabled_) {
		PrintToLog(verbose_.c_str(), log);
	}
}

template <class T>
void Log::Info(const char *log, T var) {
	if (info_enabled_) {
		PrintToLog(info_.c_str(), log, var);
	}
}

template void Log::Info<float>(const char*, float);
template void Log::Info<int>(const char*, int);
template void Log::Info<unsigned int>(const char*, unsigned int);
template void Log::Info<int8_t>(const char*, int8_t);
template void Log::Info<uint8_t>(const char*, uint8_t);
template void Log::Info<int16_t>(const char*, int16_t);
template void Log::Info<uint16_t>(const char*, uint16_t);
template void Log::Info<int32_t>(const char*, int32_t);
template void Log::Info<uint32_t>(const char*, uint32_t);
template void Log::Info<bool>(const char*, bool);

void Log::Warning(const char *log, auto var) {
	if (warning_enabled_) {
		PrintToLog(warning_.c_str(), log, var);
	}
}

template void Log::Warning<float>(const char*, float);
template void Log::Warning<int>(const char*, int);
template void Log::Warning<unsigned int>(const char*, unsigned int);
template void Log::Warning<int8_t>(const char*, int8_t);
template void Log::Warning<uint8_t>(const char*, uint8_t);
template void Log::Warning<int16_t>(const char*, int16_t);
template void Log::Warning<uint16_t>(const char*, uint16_t);
template void Log::Warning<int32_t>(const char*, int32_t);
template void Log::Warning<uint32_t>(const char*, uint32_t);
template void Log::Warning<bool>(const char*, bool);

void Log::Error(const char *log, auto var) {
	if (error_enabled_) {
		PrintToLog(error_.c_str(), log);
	}
}

template void Log::Error<float>(const char*, float);
template void Log::Error<int>(const char*, int);
template void Log::Error<unsigned int>(const char*, unsigned int);
template void Log::Error<int8_t>(const char*, int8_t);
template void Log::Error<uint8_t>(const char*, uint8_t);
template void Log::Error<int16_t>(const char*, int16_t);
template void Log::Error<uint16_t>(const char*, uint16_t);
template void Log::Error<int32_t>(const char*, int32_t);
template void Log::Error<uint32_t>(const char*, uint32_t);
template void Log::Error<bool>(const char*, bool);

void Log::Exception(const char *log, auto var) {
	if (exception_enabled_) {
		PrintToLog(exception_.c_str(), log, var);
	}
}

template void Log::Exception<float>(const char*, float);
template void Log::Exception<int>(const char*, int);
template void Log::Exception<unsigned int>(const char*, unsigned int);
template void Log::Exception<int8_t>(const char*, int8_t);
template void Log::Exception<uint8_t>(const char*, uint8_t);
template void Log::Exception<int16_t>(const char*, int16_t);
template void Log::Exception<uint16_t>(const char*, uint16_t);
template void Log::Exception<int32_t>(const char*, int32_t);
template void Log::Exception<uint32_t>(const char*, uint32_t);
template void Log::Exception<bool>(const char*, bool);

void Log::Debug(const char *log, auto var) {
	if (debug_enabled_) {
		PrintToLog(debug_.c_str(), log, var);
	}
}

template void Log::Debug<float>(const char*, float);
template void Log::Debug<int>(const char*, int);
template void Log::Debug<unsigned int>(const char*, unsigned int);
template void Log::Debug<int8_t>(const char*, int8_t);
template void Log::Debug<uint8_t>(const char*, uint8_t);
template void Log::Debug<int16_t>(const char*, int16_t);
template void Log::Debug<uint16_t>(const char*, uint16_t);
template void Log::Debug<int32_t>(const char*, int32_t);
template void Log::Debug<uint32_t>(const char*, uint32_t);
template void Log::Debug<bool>(const char*, bool);

void Log::Verbose(const char *log, auto var) {
	if (verbose_enabled_) {
		PrintToLog(verbose_.c_str(), log, var);
	}
}

template void Log::Verbose<float>(const char*, float);
template void Log::Verbose<int>(const char*, int);
template void Log::Verbose<unsigned int>(const char*, unsigned int);
template void Log::Verbose<int8_t>(const char*, int8_t);
template void Log::Verbose<uint8_t>(const char*, uint8_t);
template void Log::Verbose<int16_t>(const char*, int16_t);
template void Log::Verbose<uint16_t>(const char*, uint16_t);
template void Log::Verbose<int32_t>(const char*, int32_t);
template void Log::Verbose<uint32_t>(const char*, uint32_t);
template void Log::Verbose<bool>(const char*, bool);

void Log::SetInfoEnabled(bool status) {

	info_enabled_ = status;

}
void Log::SetWarningEnabled(bool status) {

	warning_enabled_ = status;

}
void Log::SetErrorEnabled(bool status) {

	error_enabled_ = status;

}
void Log::SetExceptionEnabled(bool status) {

	exception_enabled_ = status;

}
void Log::SetDebugEnabled(bool status) {

	debug_enabled_ = status;

}
void Log::SetVerboseEnabled(bool status) {

	verbose_enabled_ = status;

}

// Private Functions
//===========================================

void Log::PrintToLog(const char * log_type, const char *log) {
	LOG_OUTPUT("%s%s\r\n", log_type, log);
}

void Log::PrintToLog(const char * log_type, const char *log, int var) {
	LOG_OUTPUT("%s%s %d\r\n", log_type, log, var);
}

void Log::PrintToLog(const char * log_type, const char *log, unsigned int var) {
	LOG_OUTPUT("%s%s %u\r\n", log_type, log, var);
}

void Log::PrintToLog(const char * log_type, const char *log, float var) {
	LOG_OUTPUT("%s%s %f\r\n", log_type, log, var);
}

void Log::PrintToLog(const char * log_type, const char *log, int8_t var) {
	LOG_OUTPUT("%s%s %hd\r\n", log_type, log, var);
}

void Log::PrintToLog(const char * log_type, const char *log, uint8_t var) {
	LOG_OUTPUT("%s%s %hu\r\n", log_type, log, var);
}

void Log::PrintToLog(const char * log_type, const char *log, int16_t var) {
	LOG_OUTPUT("%s%s %d\r\n", log_type, log, var);
}

void Log::PrintToLog(const char * log_type, const char *log, uint16_t var) {
	LOG_OUTPUT("%s%s %u\r\n", log_type, log, var);
}

void Log::PrintToLog(const char * log_type, const char *log, int32_t var) {
	LOG_OUTPUT("%s%s %ld\r\n", log_type, log, var);
}

void Log::PrintToLog(const char * log_type, const char *log, uint32_t var) {
	LOG_OUTPUT("%s%s %lu\r\n", log_type, log, var);
}

void Log::PrintToLog(const char * log_type, const char *log, bool var) {

	if (var) {
		LOG_OUTPUT("%s%s True\r\n", log_type, log);
	} else {
		LOG_OUTPUT("%s%s False\r\n", log_type, log);
	}

}

} /* namespace Logs */

