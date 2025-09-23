#include "include/lib.h"

int main(int argc, char *argv[])
{
    std::string input;

    if (argc == 1)
    {
        std::cout << "Kokį tekstą norite hashinti?" << std::endl;
        std::getline(std::cin, input);
        std::string output = hash(input);
        std::cout << output << std::endl;
    }
    else
    {
        for (int i = 1; i < argc; i++)
        {
            std::string fileName = argv[i];
            std::string output = hash(readFromFile(fileName));
            std::cout << output << std::endl;
        }
    }
}