#include <iostream>
#include <cmath>

void write_digit(int current_digit)
{
    int digit_value = 60, next_digit, ones_amount, sign, signs_amount, tens_amount;
    tens_amount = current_digit / 10;
    ones_amount = current_digit % 10;
    signs_amount = tens_amount + ones_amount;
    for (sign = 1; sign <= signs_amount; sign++){
        if (sign <= tens_amount){
            std::cout << '<';
        }
        else{
            std::cout << 'v';
        }
    }
}

int main()
{
    int digits_amount = 1, digits_done = 0, digit_size = 60, number, number_copy;
    std::cin >> number;
    number_copy = number;
    if (number_copy > digit_size - 1){
        number_copy = number_copy / digit_size;
        digits_amount++;
    }
    while (number_copy > digit_size - 1){
            number_copy = number_copy / digit_size;
            digits_amount++;
    }
    while (digits_done < digits_amount){
        write_digit(number_copy);
        digits_done++;
        if (digits_done < digits_amount){
            std::cout << '.';
        }
        number = number - number_copy * std::pow(60, (digits_amount - digits_done));
        if (digits_done < digits_amount){
            number_copy = number / int(std::pow(60, digits_amount - digits_done - 1));
        }
    }
    return 0;
}
