#include "Harl.h"

#include <iostream>

void Harl::complain(std::string level)
{
    const char* m_levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*funcs[4])() = {
        &Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (int i = 0; i < 4; ++i)
    {
        if (!level.compare(m_levels[i]))
            (this->*funcs[i])();
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
    std::cout << "[ERRO] an unrecoverable error occured" << std::endl;
}

