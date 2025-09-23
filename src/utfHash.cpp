#include "../include/lib.h"

int hashLength = 4;
int UTFCap = 126; 

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

void segmentHandling(int & segmentValue){
    if(segmentValue > UTFCap){
        segmentValue -= UTFCap * std::floor(segmentValue / UTFCap);
        if(segmentValue==0) segmentValue += UTFCap-1;
    }
}

std::string hash(std::string input)
{
    std::string hash = "";
    std::vector<std::string> stringParts = splitString(input);
    std::vector<std::vector<char>> charVector;
    std::vector<int> UTFCodes;
    for (int i = 0; i < hashLength; i++) // convert string segments into char segments
    {
        std::vector<char> c(stringParts[i].begin(), stringParts[i].end());
        charVector.push_back(c);
    }
    for (int i = 0; i < hashLength; i++) // add up ASCII values of all the letters in each segment
    {
        int segmentSum = 1;
        for (auto &j : charVector[i])
        {
            std::cout << j << " " << (int)j << std::endl;
            segmentSum *= j;
         //   segmentHandling(segmentSum);
        }
        UTFCodes.push_back(segmentSum);
        std::cout << segmentSum << std::endl;
    }
    int currentSegment = hashLength-1, nextSegment = 0;
    while (true) 
    {
        UTFCodes[nextSegment] *= UTFCodes[currentSegment];
        segmentHandling(UTFCodes[nextSegment]);
        if (UTFCodes[nextSegment] > 32)
        {
            std::cout << nextSegment << " " << UTFCodes[nextSegment] << " " << (char)UTFCodes[nextSegment] << std::endl;
            hash += (char)UTFCodes[nextSegment];
            currentSegment = nextSegment;
            nextSegment++;
            if (nextSegment == hashLength)
                break;
        }
    }
    return hash;
}