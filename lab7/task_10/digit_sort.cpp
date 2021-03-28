#include <iostream>

int* create_array (size_t size)
{
    int* array = new int[size];
    return array;
}

int get_digit (int number, int digit)
{
    for (int i = 0; i < digit - 1; i ++){
        number = number / 10;
    }
    int result = number % 10;
    return result;
}

int get_digits_amount (int number)
{
    int amount = 0;
    while (number > 0){
        number = number / 10;
        amount ++;
    }
    return amount;
}

void print (int* array, size_t size)
{
    for (int i = 0; i < size; i ++){
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';
}

void sort (int* array, size_t size, int max_digits_amount)
{
    for (int digit = 1; digit <= max_digits_amount; digit ++){
        for (int j = 1; j < size; j ++){
            int key_digit = get_digit(array[j], digit);
            int key = array[j];
            int i = j - 1;
            while (i >= 0 && get_digit(array[i], digit) > key_digit){
                array[i + 1] = array[i];
                i --;
            }
            array[i + 1] = key;
        }
        print(array, size);
    }
}

int main()
{
    const size_t size = 10000;
    int number, key;
    int max = 0;
    size_t real_size = 0;
    int* array = create_array(size);
    while (std::cin >> number){
        array[real_size] = number;
        real_size ++;
        if (number > max){
            max = number;
        }
    }
    int max_digits_amount = get_digits_amount(max);
    sort(array, real_size, max_digits_amount);
    delete[] array;
    return 0;
}
