#include "../include/lib.h"

int hashLength = 64;

std::string hash(std::string input)
{
    int hash[64]{15};
    std::stringstream finalHash;
    for (char inputChar : input)
    {
        int utfVal = (int)inputChar;
        std::mt19937 change(utfVal);
        std::uniform_int_distribution<int> number(0, 15);
        for (int i = 0; i < 64; i++)
        {
            
        }
    }

    finalHash << std::hex << value;
    return finalHash.str();
}

/*
{
    int hash[64]{0};
    long long totalValue = 0;
    std::stringstream finalHash;
    for (int a = 0; a < input.length(); a++)
    {
        int utfVal = (int)input[a];
        totalValue += utfVal;

        std::bitset<8> binVal(input[a]);
        for (int i = 0; i < 8; i++)
        {
            if (binVal[i])
            {
                for (int j = i; j < 64; j += 8)
                {
                    hash[j]++;
                }
            }
        }
    }

    std::mt19937 change(totalValue);
    std::uniform_int_distribution<int> number(0, 15);
    for (int i = 0; i < 64; i++)
    {
        int value = number(change);
        for (int j = 0; j < hash[i]; j++)
        {
            value = number(change);
        }
        finalHash << std::hex << value;
    }
    return finalHash.str();
}*/