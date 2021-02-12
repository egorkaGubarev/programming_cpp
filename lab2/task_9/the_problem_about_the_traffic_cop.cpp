#include <iostream>

int comparison(std::string n)
{
    char n1;
    char n2;
    char n3;
    int s;
    n1 = n[1];
    n2 = n[2];
    n3 = n[3];
    s = 0;
    if (n1 == n2){
        s = s + 2;
        if (n2 == n3){
            s++;
        }
    }else{
        if (n2 == n3){
            s = s + 2;
        }
        if (n1 == n3){
            s = s + 2;
        }
    }
    if (n == "A999AA"){
        s = 1;
    }
    return s;
}

int main()
{
    int c;
    std::string n;
    int m;
    int s;
    n = '0';
    m = 0;
    while (n != "A999AA"){
        std::cin >> s;
        std::cin >> n;
        if (s > 60){
            c = comparison(n);
            if (c == 0){
                m = m + 100;
            }
            if (c == 2){
                m = m + 500;
            }
            if (c == 3){
                m = m + 1000;
            }
        }
    }
    std::cout << m;
    return 0;
}
