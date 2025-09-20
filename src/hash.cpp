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
    std::vector<int> asciiCodes;
    for (int i = 0; i < hashLength; i++)                                      // convert string segments into char segments
    {
        std::vector<char> c(stringParts[i].begin(), stringParts[i].end());
        charVector.push_back(c);
    }
    for (int i = 0; i < hashLength; i++) // add up ASCII values of all the letters in each segment
    {
        int segmentSum = 0;
        for (auto &j : charVector[i])
        {
            //std::cout << j << " " << (int)j << std::endl;
            segmentSum += j;
        }
        asciiCodes.push_back(segmentSum);
       // std::cout << segmentSum << std::endl;
    }
    int currentSegment = 3, nextSegment = 0;
    while (true) // multiply all the segments in a circle to ensure avalanche effect
    {
        asciiCodes[nextSegment] *= asciiCodes[currentSegment];
        if (asciiCodes[nextSegment] > 126)
        {
            asciiCodes[nextSegment] -= 126 * std::floor(asciiCodes[nextSegment] / 126);
        }
        if(asciiCodes[nextSegment] > 32){
            std::cout << nextSegment << " " << asciiCodes[nextSegment] << " " << (char)asciiCodes[nextSegment] << std::endl;
            currentSegment = nextSegment;
            nextSegment++;
            if(nextSegment==4) break;
        }
    }
    return " ";
}