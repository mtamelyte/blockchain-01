#include "../include/lib.h"

std::string hash(std::string input)
{
    int hash[64]{0};
    std::stringstream finalHash;
    for (char inputChar : input)
    {
        int utfVal = (int)inputChar;
        std::mt19937 change(utfVal);
        std::uniform_int_distribution<int> number(0, 15);
        for (int i = 0; i < 64; i++)
        {
            hash[i] = abs(hash[i] - number(change));
        }
        int temp = hash[0];
        for (int i = 0; i < 64; i++)
        {
            hash[i] = hash[i + 1];
        }
        hash[63] = temp;
    }
    for (int i = 0; i < 64; i++)
    {
        finalHash << std::hex << hash[i];
    }
    return finalHash.str();
}