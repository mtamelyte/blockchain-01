#include "../include/lib.h"

std::string readFromFile(std::string fileName){
    std::stringstream buffer; 
    std::ifstream fin;
    fin.open(fileName);
    buffer<< fin.rdbuf();
    fin.close();
    std::string input ="";
    std::string line;
    while (buffer)
    {
        if (!buffer.eof())
        {
            getline(buffer, line);
            input += line;
        }
        else
            break;
    }
    return input;
}