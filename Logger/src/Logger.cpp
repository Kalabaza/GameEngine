#include "Logger.h"

namespace Logger {
    static std::map<Logger::LogType, std::string> logType {{Logger::LogType::TypeTrace,   "[Trace] - "}, 
                                                           {Logger::LogType::TypeDebug,   "[Debug] - "},
                                                           {Logger::LogType::TypeError,   "[Error] - "},
                                                           {Logger::LogType::TypeWarning, " [Warn] - "},
                                                           {Logger::LogType::TypeInfo,    " [Info] - "}};

    void Logger::Trace(const std::string& message) {
        LogMessage(LogType::TypeTrace, message);
    }
    void Logger::Debug(const std::string& message) {
        LogMessage(LogType::TypeDebug, message);
    }
    void Logger::Error(const std::string& message) {
        LogMessage(LogType::TypeError, message);
    }
    void Logger::Warning(const std::string& message) {
        LogMessage(LogType::TypeWarning, message);
    }
    void Logger::Info(const std::string& message) {
        LogMessage(LogType::TypeInfo, message);
    }

    void Logger::LogMessage(LogType type, const std::string& message) {
        std::cout << logType[type] << message << std::endl;
    }
}
