#include "../include/lib.h"

std::string sha256(const std::string &str)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

void outputSizeTest(std::string (*hash)(const std::string &input))
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

void determinismTest(std::string (*hash)(const std::string &input))
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

void speedTest(std::string (*hash)(const std::string &input))
{
    std::string inputFile = "C:/Users/tamel/Documents/uni/blockchain/blockchain-01/files/konstitucija.txt";
    for (int i = 1; i < 789; i *= 2)
    {
        double result = 0;
        for (int j = 0; j < 3; j++)
        {
            std::string input = readToCertainLine(inputFile, i);
            auto t1 = std::chrono::high_resolution_clock::now();
            std::string output = hash(input);
            auto t2 = std::chrono::high_resolution_clock::now();
            result += std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() / 1000000000.0;
        }
        std::cout << i << " line(s): " << result / 3 << "s" << std::endl;
    }
    double result = 0;
    for (int j = 0; j < 3; j++)
    {
        std::string input = readFromFile(inputFile);
        auto t1 = std::chrono::high_resolution_clock::now();
        std::string output = hash(input);
        auto t2 = std::chrono::high_resolution_clock::now();
        result += std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() / 1000000000.0;
    }
    std::cout << "Full file: " << result/3 << "s" << std::endl;
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

void collisionTest(int length, std::string (*hash)(const std::string &input))
{
    std::mt19937 seed(static_cast<long unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
    std::uniform_int_distribution<int> symbols(33, 126);
    int collisionCount = 0;
    for (int i = 0; i < 100000; i++)
    {
        std::string firstString = generateRandomString(length);
        std::string secondString = generateRandomString(length);
        ;
        if (hash(firstString) == hash(secondString))
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

void avalancheTest(std::string (*hash)(const std::string &input))
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

void saltTest(std::string (*hash)(const std::string &input))
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
    std::cout << "My hash: ";
    outputSizeTest(&hash);
    std::cout << "SHA256s: ";
    outputSizeTest(&sha256);
    std::cout << std::endl;
    std::cout << "My hash: ";
    determinismTest(&hash);
    std::cout << "SHA256s: ";
    determinismTest(&sha256);
    std::cout << std::endl;
    std::cout << "Speed test (my hash): " << std::endl;
    speedTest(&hash);
    std::cout << std::endl;
    std::cout << "Speed test (SHA256): " << std::endl;
    speedTest(&sha256);
    std::cout << std::endl;
    std::cout << "Collision test (my hash): " << std::endl;
    collisionTest(10, &hash);
    collisionTest(100, &hash);
    collisionTest(500, &hash);
    collisionTest(1000, &hash);
    std::cout << std::endl;
    std::cout << "Collision test (SHA256): " << std::endl;
    collisionTest(10, &sha256);
    collisionTest(100, &sha256);
    collisionTest(500, &sha256);
    collisionTest(1000, &sha256);
    std::cout << std::endl;
    std::cout << "Avalanche test (my hash): " << std::endl;
    avalancheTest(&hash);
    std::cout << std::endl;
    std::cout << "Avalanche test (SHA256): " << std::endl;
    avalancheTest(&sha256);
    std::cout << std::endl;
    std::cout << "Salt test (my hash): " << std::endl;
    saltTest(&hash);
    std::cout << std::endl;
    std::cout << "Salt test (SHA256): " << std::endl;
    saltTest(&sha256);
}