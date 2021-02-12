#include <iostream>

int main()
{
    int a;
    int n;
    int m;
    a = 1;
    n = -1;
    m = 0;
    while (n != 0){
        std::cin >> n;
        if (n > m){
            a = 1;
            m = n;
        }else{
            if (n == m){
                a++;
            }
        }
    }
    std::cout << a;
    return 0;
}
