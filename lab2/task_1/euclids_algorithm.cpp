#include <iostream>

int main()
{
    int a;
    int b;
    std::cin >> a;
    std::cin >> b;
    while (std::min(a, b) != 0){
        if (a > b){
            a = a % b;
        }
        else{
            b = b % a;
        }
    }
    std::cout << a + b;
    return 0;
}
