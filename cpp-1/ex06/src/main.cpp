#include "Harl.h"
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "usage:\n"
            << "./harlFilter log_level" << std::endl;
        return 1;
    }

    try
    {
        Harl logger(argv[1]);
        logger.complain();
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;

}
