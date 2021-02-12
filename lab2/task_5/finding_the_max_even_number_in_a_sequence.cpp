#include <iostream>

int main()
{
    int n;
    int m;
    int r;
    n = -1;
    m = 0;
    while (n != 0){
        std::cin >> n;
        r = n % 2;
        if (r == 0){
            if (n > m){
                m = n;
            }
        }
    }
    std::cout << m;
    return 0;
}
