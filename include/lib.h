#include <bits/stdc++.h>
#include <chrono>
#include <openssl/sha.h>

std::string hash(const std::string &input);
std::string claudeHash(const std::string &input);
std::string readFromFile(std::string fileName);
bool exists(std::string fileName);
std::string readToCertainLine(std::string fileName, int maxLine);