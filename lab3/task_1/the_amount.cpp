#include <iostream>

int main()
{
    int i, number, sum, sum_big;
    size_t n;
    std::cin >> n;
    int* p_numbers = new int[n];
    double average;
    sum = 0;
    sum_big = 0;
    for (i = 0; i < n; i++){
        std::cin >> number;
        p_numbers[i] = number;
        sum = sum + number;
    }
    average = sum / n;
    for (i = 0; i < n; i++){
        number = p_numbers[i];
        if (number > average){
            sum_big = sum_big + number;
        }
    }
    delete [] p_numbers;
    p_numbers = NULL;
    std::cout << sum_big;
    return 0;
}
