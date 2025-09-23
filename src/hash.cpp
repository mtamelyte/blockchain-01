#include "../include/lib.h"

std::string hash(std::string input)
{
    //initializing the hash
    int hash[64]{0};
    std::stringstream finalHash;
    for (int i=0; i<input.length(); i++)
    {
        int utfVal = (int)input[i];
        
        //randomly adjusting the values in the hex using seeds derived from the UTF value that go through several rounds of randomization
        std::mt19937 change1(utfVal);
        std::uniform_int_distribution<int> seed(1, 500);
        std::mt19937 change2(seed(change1));
        std::mt19937 change3(seed(change1)*seed(change2));
        std::uniform_int_distribution<int> number(0, 15);
        for (int j = 0; j < 64; j++)
        {
            hash[j] = abs(hash[j] - number(change3));
        }

        //rotating the characters in the hash before inputing a new one to ensure avalanche
        int temp = hash[0];
        for (int i = 0; i < 64; i++)
        {
            hash[i] = hash[i + 1];
        }
        hash[63] = temp;
    }
    //casting everything to hex
    for (int i = 0; i < 64; i++)
    {
        finalHash << std::hex << hash[i];
    }
    return finalHash.str();
}