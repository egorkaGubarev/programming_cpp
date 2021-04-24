#include <iostream>

int main()
{
    int digit, n;
    int sum = 0;
    std::cin >> n;
    while (n > 0){
        digit = n % 10;
        n = n / 10;
        sum = sum + digit;
    }
    std::cout << sum;
    return 0;
}
