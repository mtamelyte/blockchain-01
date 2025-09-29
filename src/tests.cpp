#include "../include/lib.h"

void outputSizeTest()
{
    std::vector<std::string> output;
    output.push_back(hash(readFromFile("C:/Users/tamel/Documents/uni/blockchain/blockchain-01/files/empty.txt")));
    output.push_back(hash(readFromFile("C:/Users/tamel/Documents/uni/blockchain/blockchain-01/files/oneSymbol1.txt")));
    output.push_back(hash(readFromFile("C:/Users/tamel/Documents/uni/blockchain/blockchain-01/files/oneSymbol2.txt")));
    output.push_back(hash(readFromFile("C:/Users/tamel/Documents/uni/blockchain/blockchain-01/files/oneSymbol2.txt")));
    output.push_back(hash(readFromFile("C:/Users/tamel/Documents/uni/blockchain/blockchain-01/files/random1.txt")));
    output.push_back(hash(readFromFile("C:/Users/tamel/Documents/uni/blockchain/blockchain-01/files/random2.txt")));
    output.push_back(hash(readFromFile("C:/Users/tamel/Documents/uni/blockchain/blockchain-01/files/random3.txt")));
    output.push_back(hash(readFromFile("C:/Users/tamel/Documents/uni/blockchain/blockchain-01/files/random4.txt")));
    output.push_back(hash("I love blockchains!!!"));

    int errorCounter = 0;
    for (auto s : output)
    {
        if (s.size() != 64)
            errorCounter++;
    }
    if (errorCounter == 0)
        std::cout << "Output size test passed." << std::endl;
    else
        std::cout << "Output test failed with " << errorCounter << " error(s)." << std::endl;
}

void determinismTest()
{
    std::string output1 = (hash(readFromFile("C:/Users/tamel/Documents/uni/blockchain/blockchain-01/files/testing.txt")));
    std::string output2 = (hash("I love blockchains yay!"));
    std::string output3 = hash(readFromFile("C:/Users/tamel/Documents/uni/blockchain/blockchain-01/files/testing.txt"));
    if (output1 == output2 && output1 == output3)
        std::cout << "Determinism test passed." << std::endl;
    else
    {
        std::cout << "Determinism test failed." << std::endl;
        std::cout << output1 << std::endl;
        std::cout << output2 << std::endl;
        std::cout << output3 << std::endl;
    }
}

void speedTest()
{
    std::string inputFile = "C:/Users/tamel/Documents/uni/blockchain/blockchain-01/files/konstitucija.txt";
    std::string input = readToCertainLine(inputFile, 1);
    auto t1 = std::chrono::high_resolution_clock::now();
    std::string output = hash(input);
    auto t2 = std::chrono::high_resolution_clock::now();
    double result = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() / 1000.0;
    std::cout << "1 line: " << result << "s" << std::endl;
    input = readToCertainLine(inputFile, 2);
    t1 = std::chrono::high_resolution_clock::now();
    output = hash(input);
    t2 = std::chrono::high_resolution_clock::now();
    result = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() / 1000.0;
    std::cout << "2 lines: " << result << "s" << std::endl;
    input = readToCertainLine(inputFile, 4);
    t1 = std::chrono::high_resolution_clock::now();
    output = hash(input);
    t2 = std::chrono::high_resolution_clock::now();
    result = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() / 1000.0;
    std::cout << "4 lines: " << result << "s" << std::endl;
    input = readToCertainLine(inputFile, 8);
    t1 = std::chrono::high_resolution_clock::now();
    output = hash(input);
    t2 = std::chrono::high_resolution_clock::now();
    result = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() / 1000.0;
    std::cout << "8 lines: " << result << "s" << std::endl;
    input = readToCertainLine(inputFile, 16);
    t1 = std::chrono::high_resolution_clock::now();
    output = hash(input);
    t2 = std::chrono::high_resolution_clock::now();
    result = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() / 1000.0;
    std::cout << "16 lines: " << result << "s" << std::endl;
    input = readToCertainLine(inputFile, 32);
    t1 = std::chrono::high_resolution_clock::now();
    output = hash(input);
    t2 = std::chrono::high_resolution_clock::now();
    result = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() / 1000.0;
    std::cout << "32 lines: " << result << "s" << std::endl;
    input = readToCertainLine(inputFile, 64);
    t1 = std::chrono::high_resolution_clock::now();
    output = hash(input);
    t2 = std::chrono::high_resolution_clock::now();
    result = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() / 1000.0;
    std::cout << "64 lines: " << result << "s" << std::endl;
    input = readToCertainLine(inputFile, 128);
    t1 = std::chrono::high_resolution_clock::now();
    output = hash(input);
    t2 = std::chrono::high_resolution_clock::now();
    result = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() / 1000.0;
    std::cout << "128 lines: " << result << "s" << std::endl;
    input = readToCertainLine(inputFile, 256);
    t1 = std::chrono::high_resolution_clock::now();
    output = hash(input);
    t2 = std::chrono::high_resolution_clock::now();
    result = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() / 1000.0;
    std::cout << "256 lines: " << result << "s" << std::endl;
    input = readToCertainLine(inputFile, 512);
    t1 = std::chrono::high_resolution_clock::now();
    output = hash(input);
    t2 = std::chrono::high_resolution_clock::now();
    result = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() / 1000.0;
    std::cout << "512 lines: " << result << "s" << std::endl;
    input = readFromFile(inputFile);
    t1 = std::chrono::high_resolution_clock::now();
    output = hash(input);
    t2 = std::chrono::high_resolution_clock::now();
    result = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() / 1000.0;
    std::cout << "Full file: " << result << "s" << std::endl;
}

std::string generateRandomString(int length)
{
    std::string randomString = "";
    std::mt19937 seed(static_cast<long unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
    std::uniform_int_distribution<int> symbols(33, 126);
    for (int j = 0; j < length; j++)
    {
        randomString += (char)symbols(seed);
    }
    return randomString;
}

void collisionTest(int length)
{
    std::mt19937 seed(static_cast<long unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
    std::uniform_int_distribution<int> symbols(33, 126);
    int collisionCount = 0;
    for (int i = 0; i < 100000; i++)
    {
        std::string firstString = generateRandomString(length);
        std::string secondString = generateRandomString(length);
        ;
        if (hash(firstString) == hash(secondString) && firstString!= secondString)
            collisionCount++;
    }
    std::cout << length << " symbol strings: " << collisionCount << " collisions" << std::endl;
}

double hexSimilarity(std::string hash1, std::string hash2)
{
    int identicalChars = 0;
    int length = hash1.length();
    for (int i = 0; i < length; i++)
    {
        if (hash1[i] == hash2[i])
        {
            identicalChars++;
        }
    }
    return static_cast<double>(identicalChars) / length * 100;
}

double bitSimilarity(std::string hash1, std::string hash2)
{
    int identicalBits = 0;
    int length = hash1.length() * 8;
    for (int i = 0; i < hash1.length(); i++)
    {
        std::bitset<8> char1 = hash1[i];
        std::bitset<8> char2 = hash2[i];
        for (int j = 0; j < 8; j++)
        {
            if (char1[j] == char2[j])
            {
                identicalBits++;
            }
        }
    }
    return static_cast<double>(identicalBits) / length * 100;
}

void avalancheTest()
{
    std::mt19937 seed(static_cast<long unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
    std::uniform_int_distribution<int> symbols(33, 126);
    std::uniform_int_distribution<int> position(0, 9);
    double maxHexSimilarity = 0;
    double minHexSimilarity = 100;
    double averageHexSimilarity = 0;
    double maxBitSimilarity = 0;
    double minBitSimilarity = 100;
    double averageBitSimilarity = 0;
    int collisionCount = 0;
    for (int i = 0; i < 100000; i++)
    {
        std::string firstString = generateRandomString(10);
        std::string secondString;
        secondString = firstString;
        int pos = position(seed);
        int symbolToChange = symbols(seed);
        if (symbolToChange == (int)firstString[pos])
            symbolToChange--;
        secondString[pos] = (char)symbolToChange;
        std::string hash1 = hash(firstString);
        std::string hash2 = hash(secondString);
        double hexSim = hexSimilarity(hash1, hash2);
        double bitSim = bitSimilarity(hash1, hash2);
        if (hexSim > maxHexSimilarity)
            maxHexSimilarity = hexSim;
        if (hexSim < minHexSimilarity)
            minHexSimilarity = hexSim;
        if (bitSim > maxBitSimilarity)
            maxBitSimilarity = bitSim;
        if (bitSim < minBitSimilarity)
            minBitSimilarity = bitSim;
        averageHexSimilarity += hexSim;
        averageBitSimilarity += bitSim;
    }
    std::cout << "Max hex similarity: " << maxHexSimilarity << "% " << std::endl;
    std::cout << "Min hex similarity: " << minHexSimilarity << "% " << std::endl;
    std::cout << "Average hex similarity: " << averageHexSimilarity / 100000 << "% " << std::endl;
    std::cout << "Max bit similarity: " << maxBitSimilarity << "% " << std::endl;
    std::cout << "Min bit similarity: " << minBitSimilarity << "% " << std::endl;
    std::cout << "Average bit similarity: " << averageBitSimilarity / 100000 << "% " << std::endl;
}

void saltTest()
{
    std::string input = "I love blockchains!";
    std::string salt = generateRandomString(10);
    std::string stringToHash = input + salt;
    std::cout << "Initial string: " << input << std::endl;
    std::cout << "Salt: " << salt << std::endl;
    std::cout << "String with salt: " << stringToHash << std::endl;
    std::cout << "Hash without salt:" << hash(input) << std::endl;
    std::cout << "Hash with salt: " << hash(stringToHash) << std::endl;
}

int main()
{
    outputSizeTest();
    determinismTest();
    std::cout << "Speed test: " << std::endl;
    speedTest();
    std::cout << "Collision test: " << std::endl;
    collisionTest(10);
    collisionTest(100);
    collisionTest(500);
    collisionTest(1000);
    std::cout << "Avalanche test: " << std::endl;
    avalancheTest();
    std::cout << "Salt test: " << std::endl;
    saltTest();
}