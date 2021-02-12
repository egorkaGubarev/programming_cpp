#include <iostream>
#include <cmath>

int main()
{
    int i;
    int n;
    std::cin >> n;
    for (i = 2; i <= n; i++){
        if (n % i == 0){
            std::cout << i;
            n = n / i;
            std::cout << '\n';
            i--;
        }
    }
    return 0;
}
