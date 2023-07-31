#pragma once

#include <iostream>
#include <string>

namespace Logger {
    class __declspec(dllexport) Logger {
    public:
        Logger() = default;
        ~Logger() = default;

        void Info(std::string message) {
            std::cout << "[Info] : "<< message << std::endl;
        }
        void Trace(std::string message) {
            std::cout << "[Trace] : " << message << std::endl;
        }
    };
}

Logger::Logger Log() {
    static Logger::Logger logger;
    return logger;
}