#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cerr << "usage:\n"
            << "./replace filename string_to_replace new_string" << std::endl;
        return 1;
    }

    std::string strOld = argv[2];
    std::string strNew = argv[3];
    if (strOld.length() < 1)
    {
        std::cerr << "The string to replace can't be empty" << std::endl;
        return 1;
    }

    std::ifstream infile(argv[1]);
    if (infile.good() == false)
    {
        std::cout << "Unable to open " << argv[1] << std::endl;
        return 1;
    }

    std::string outfile_name = std::string(argv[1]) + std::string(".replace");
    std::ofstream outfile(outfile_name.c_str());

    while (infile)
    {
        std::string line;
        std::getline(infile, line);
        size_t pos = line.find(strOld, 0);
        while (pos != line.npos)
        {
            line.erase(pos, strOld.length());
            for (size_t i = 0; i < strNew.length(); ++i)
                line.insert(pos + i, 1, strNew[i]);
            pos = line.find(strOld, pos + strNew.length());
        }
        outfile << line;
        if (infile.peek() == std::ifstream::traits_type::eof())
            break;
        else
            outfile << std::endl;
    }

    return 0;

}
