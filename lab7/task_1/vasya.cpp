#include <iostream>

int main()
{
    int a, b, c, d, x;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    std::cin >> d;
    std::cin >> x;
    int grade;
    if (x == b - a && x == d / c){
        grade = 5;
    }
    else{
        if (x == b - a || x == d / c){
            grade = 4;
        }
        else{
            if (x == 1024){
                grade = 3;
            }
            else{
                grade = 2;
            }
        }
    }
    std::cout << grade;
    return 0;
}
