#include <iostream>
#include <cmath>

int main()
{
    int c;
    int i;
    int n;
    c = 0;
    std::cin >> n;
    for (i = 2; i < std::sqrt(n); i++){
        if (n % i == 0){
            c++;
        }
    }
    if (c == 0){
        std::cout << 1;
    }else{
        std::cout << 0;
    }
    return 0;
}
