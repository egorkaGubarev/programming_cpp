#include <iostream>

int main()
{
    int n, c;
    std::cin >> n;
    int count = 2, t_0 = 0, t_1 = 0, t_2 = 1;
    while (t_2 <= n)
    {
        c = t_2;
        t_2 = t_2 + t_1 + t_0;
        t_0 = t_1;
        t_1 = c;
        count ++;
    }
    std::cout << count;
    return 0;
}
