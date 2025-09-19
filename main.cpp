#include "include/lib.h"

int main(){
    std::string input;
    std::cout << "Kokį tekstą norite hashuoti?" << std::endl;
    std::getline(std::cin, input);
    std::string output = hash(input);
}