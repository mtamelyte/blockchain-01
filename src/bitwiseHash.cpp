#include "../include/lib.h"

int hashLength = 64;

std::string hash(std::string input)
{
    int hash[64]{15};
    int totalValue=0;
    std::stringstream finalHash;
    for (char inputChar : input)
    {
        int utfVal = (int) inputChar;
        int utfValMod = utfVal%16;
        std::bitset<8> binVal(inputChar);
        totalValue += utfVal;
        for(int i=0; i<8; i++){
            if(binVal[i]){
                hash[i] = abs(hash[i]-utfValMod);
                hash[i+8] = hash[i];
                hash[i+16] = hash[i];
                hash[i+24] = hash[i];
                hash[i+32] = hash[i];
                hash[i+40] = hash[i];
                hash[i+48] = hash[i];
                hash[i+56] = hash[i];
            }
        }
    }

    std::mt19937 mt(totalValue);
    std::uniform_int_distribution<int> numeris(0, 15);
    for (int i = 0; i < 64; i++) 
    {
        hash[i]=abs(hash[i]-numeris(mt));
        finalHash << std::hex << hash[i];
    }
    return finalHash.str();
}