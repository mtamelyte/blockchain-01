#include "include/lib.h"

int main(int argc, char *argv[])
{
    std::string input;
    std::string output;

    if (argc == 1)
    {
        std::cout << "Kokį tekstą norite hashinti?" << std::endl;
        std::getline(std::cin, input);
        output = hash(input);
        std::cout << output << std::endl;
    }
    else
    {
        for (int i = 1; i < argc; i++)
        {
            if (exists(argv[i]))
            {
                output = hash(readFromFile(argv[i]));
                std::cout << output << std::endl;
            }
            else
            {
                output = hash(argv[i]);
                std::cout << output << std::endl;
            }
        }
    }
}