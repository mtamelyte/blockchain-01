#include "../include/lib.h"

bool isEmpty(std::ifstream& file)
{
    return file.tellg() == 0 && file.peek() == std::ifstream::traits_type::eof();
}

bool exists(std::string fileName)
{
    std::ifstream fin;
    fin.open(fileName);
    if(fin.fail()) return 0;
    else if(isEmpty(fin)) 
    {
        return 0;
    }
    else{
        fin.close();
        return 1;
    }
}

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