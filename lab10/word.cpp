#include <iostream>
#include <cmath>
#include <string>

int main() {
    int count = 0;
    std::string line, subline;
    int i = 0;
    std::cin >> line;
    while (std::cin.get() != '\n'){
        i++;
        std::cin >> subline;
    }
    std::cout << i + 1;
    return 0;
}
