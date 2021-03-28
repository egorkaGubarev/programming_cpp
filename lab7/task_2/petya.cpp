#include <iostream>

int main()
{
    int N;
    std::cin >> N;
    int* numbers = new int[N];
    int digit, mod4, mod7, mod9, number;
    int position = 0;
    bool written;
    for (int i = 0; i < N; i ++){
        written = false;
        std::cin >> number;
        digit = number / 1000;
        mod4 = number % 4;
        if (mod4 == 0){
            if (digit != 4){
                if (digit != 5){
                    numbers[position] = number;
                    position ++;
                    written = true;
                }
            }
        }
        if (! written){
            mod7 = number % 7;
            if (mod7 == 0){
                if (digit != 1){
                    if (digit != 7){
                        numbers[position] = number;
                        position ++;
                        written = true;
                    }
                }
            }
        }
        if (! written){
            mod9 = number % 9;
            if (mod9 == 0){
                if (digit != 8){
                    if (digit != 9){
                        numbers[position] = number;
                        position ++;
                    }
                }
            }
        }
    }
    if (position != 0){
        for (int i = 0; i < position; i ++){
            std::cout << numbers[i] << '\n';
        }
    }
    else{
        std::cout << 0;
    }
    delete[] numbers;
    return 0;
}
