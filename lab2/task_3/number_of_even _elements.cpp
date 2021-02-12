#include <iostream>

int main(){
    int n;
    int s;
    int r;
    n = -1;
    s = -1;
    while (n != 0){
        std::cin >> n;
        r = n % 2;
        if (r ==0){
            s++;
        }
    }
    std::cout << s;
    return 0;
}
