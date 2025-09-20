#include "../include/lib.h"

std::vector<std::string> splitString(std::string input)
{
    int n = input.length();
    std::vector<std::string> splitString;
    int at, pre = 0;
    for (int i = 0; i < 4; ++i)
    {
        at = (n + n * i) / 4;
        splitString.push_back(input.substr(pre, at - pre));
        pre = at;
    }
    return splitString;
}

std::string hash(std::string input)
{
    std::string hash;
    std::vector<std::string> stringParts = splitString(input);
    std::vector<std::vector<char>> charVector; 
    std::vector<int> asciiCodes;
    for(int i=0; i<4; i++){
        std::vector<char> c(stringParts[i].begin(), stringParts[i].end());
        charVector.push_back(c);
    }
}