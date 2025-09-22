#include "include/lib.h"

int main(){
    /*char raide;
    std::cin >> raide;
    int verte = int(raide);
    std::cout << verte << std::endl;
 //   int verte;
   // std::cin >> verte;
    char pakeistaRaide = (char)verte;
    std::cout << pakeistaRaide;*/
    
    std::string input;
    std::cout << "Kokį tekstą norite hashinti?" << std::endl;
    std::getline(std::cin, input);
    std::string output = hash(input);
    std::cout << output << std::endl;
}