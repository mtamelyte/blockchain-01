#include "include/lib.h"

int main(){
    std::string input;
    std::cout << "Kokį tekstą norite hashinti?" << std::endl;
    std::getline(std::cin, input);
    std::string output = hash(input);
    std::cout << output << std::endl;
/*
    std::mt19937 mt(97);
    std::uniform_int_distribution<int> numeris(0, 15);
    for(int i=0; i<15; i++){
        std::cout << numeris(mt) << std::endl;
    }*/
}