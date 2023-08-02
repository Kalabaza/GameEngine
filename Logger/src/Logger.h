#pragma once

#include <iostream>
#include <map>
#include <string>

namespace Logger {
    class __declspec(dllexport) Logger {
    public:
        Logger() = default;
        ~Logger() = default;

        enum LogType {
            TypeTrace = 0,
            TypeDebug,
            TypeError,
            TypeWarning,
            TypeInfo
        };

        void Trace(const std::string& message);
        void Debug(const std::string& message);
        void Error(const std::string& message);
        void Warning(const std::string& message);
        void Info(const std::string& message);
    private:
        void LogMessage(LogType type, const std::string& message);
    };
}

Logger::Logger Log() {
    static Logger::Logger logger;
    return logger;
}
