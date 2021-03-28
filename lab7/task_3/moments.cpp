#include <iostream>

int main()
{
    int i = 0, sum = 0, sum_square = 0;
    int number;
    do{
        std::cin >> number;
        sum = sum + number;
        sum_square = sum_square + number * number;
        i ++;
    } while(number != 0);
    int amount = i - 1;
    double average = sum / amount;
    int square_of_average = average * average;
    double average_square = sum_square / amount;
    int dispersion = average_square - square_of_average;
    std::cout << std::fixed;
    std::cout.precision(3);
    std::cout << average << ' ' << dispersion;
    return 0;
}
