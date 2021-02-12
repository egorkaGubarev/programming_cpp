#include <iostream>

int main(){
    int N;
    std::cin >> N;
    while (N % 2 == 0){
        N = N / 2;
    }
    if (N == 1){
        std::cout << "YES";
    }else{
        std::cout << "NO";
    }
    return 0;
}
