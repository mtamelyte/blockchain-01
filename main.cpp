#include "include/lib.h"

int main(int argc, char *argv[])
{
    std::string input;
    std::string output;

    if (argc == 1)
    {
        std::cout << "Kokį tekstą norite hashinti?" << std::endl;
        std::getline(std::cin, input);
        output = claudeHash(input);
        std::cout << output << std::endl;
    }
    else
    {
        for (int i = 1; i < argc; i++)
        {
            if (exists(argv[i]))
            {
                output = claudeHash(readFromFile(argv[i]));
                std::cout << output << std::endl;
            }
            else
            {
                output = claudeHash(argv[i]);
                std::cout << output << std::endl;
            }
        }
    }
}