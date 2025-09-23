#include "../include/lib.h"

std::string hash(std::string input)
{
    int hash[64]{0};
    std::stringstream finalHash;
    for (int i=0; i<input.length(); i++)
    {
        int utfVal = (int)inputChar;
        
        //trys setai verciu keitimo su skirtingais seedais
        std::mt19937 change1(utfVal);
        std::mt19937 change2(utfVal*i);
        std::mt19937 change3(input.length());
        std::uniform_int_distribution<int> number(0, 15);
        for (int i = 0; i < 64; i++)
        {
            hash[i] = abs(hash[i] - number(change1));
        }
        for (int i = 0; i < 64; i++)
        {
            hash[i] = abs(hash[i] - number(change2));
        }
        for (int i = 0; i < 64; i++)
        {
            hash[i] = abs(hash[i] - number(change3));
        }

        //verciu rotacija, kad simbolio pozicija inpute turetu reiksmes outpute
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