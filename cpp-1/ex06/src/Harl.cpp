#include "Harl.h"

#include <iostream>

Harl::Option Harl::resolveOption(const std::string& input)
{
    if (!input.compare("DEBUG"))
        return DEBUG;
    else if (!input.compare("INFO"))
        return INFO;
    else if (!input.compare("WARNING"))
        return WARNING;
    else if (!input.compare("ERROR"))
        return ERROR;
    else
        return NONE;
}

Harl::Harl(const std::string& filter)
{
    m_filter = resolveOption(filter);
    if (m_filter == NONE)
        throw std::invalid_argument("Invalid option. Available log levels: DEBUG INFO WARNING ERROR");
}

void Harl::complain()
{
    switch (m_filter)
    {
        case NONE:
            break;
        case DEBUG:
            if (m_filter <= DEBUG)
            {
                debug();
                info();
                warning();
                error();
            }
            break;
        case INFO:
            if (m_filter <= INFO)
            {
                info();
                warning();
                error();
            }
            break;
        case WARNING:
            if (m_filter <= WARNING)
            {
                warning();
                error();
            }
            break;
        case ERROR:
            if (m_filter <= ERROR)
                error();
            break;
    }
}

void Harl::debug(void)
{
    std::cout << "[DEBG] some debug message" << std::endl;
}

void Harl::info(void)
{
    std::cout << "[INFO] some info message" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[WARN] an error occured, but i can recover" << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ERRO] an error occured" << std::endl;
}
