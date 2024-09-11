#pragma once

#include <string>

class Harl
{

public:
    enum Option
    {
        NONE = 0,
        DEBUG,
        INFO,
        WARNING,
        ERROR
    };

    Harl(const std::string& filter);
    void complain();

private:
    Option m_filter;
    Option resolveOption(const std::string& input);
    void debug();
    void info();
    void warning();
    void error();

}; // class Harl
