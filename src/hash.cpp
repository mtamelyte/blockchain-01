#include "../include/lib.h"

int hashLength = 4;

std::vector<std::string> splitString(std::string input)
{
    int n = input.length();
    std::vector<std::string> splitString;
    int at, pre = 0;
    for (int i = 0; i < hashLength; ++i)
    {
        at = (n + n * i) / hashLength;
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
    std::vector<std::vector<int>> asciiCodes;
    for (int i = 0; i < hashLength; i++)
    {
        std::vector<char> c(stringParts[i].begin(), stringParts[i].end());
        charVector.push_back(c);
    }
    for (int i = 0; i < hashLength; i++)
    {
        std::vector<int> segment;
        for (auto &j : charVector[i])
        {
            segment.push_back((int)j);
        }
        asciiCodes.push_back(segment);
    }
    return " ";
}