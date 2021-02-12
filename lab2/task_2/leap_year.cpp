#include <iostream>

int main()
{
    int N;
    int r4;
    int r100;
    int r400;
    std::cin >> N;
    r4 = N % 4;
    r100 = N % 100;
    r400 = N % 400;
    if (r4 == 0 and r100 != 0){
        std::cout << "YES";
    }else{
        if (r400 == 0){
            std::cout << "YES";
        }else{
            std::cout << "NO";
        }
    }
    return 0;
}
