#include <iostream>

int* create_array (size_t size)
{
    int* array = new int[size];
    return array;
}

void sort(int* array, size_t size)
{
    for (int j = 1; j < size; j ++){
        int key = array[j];
        int i = j - 1;
        while (i >= 0 && array[i] > key){
            array[i + 1] = array[i];
            i --;
        }
        array[i + 1] = key;
    }
}

int main()
{
    const size_t size = 10000;
    int number, key;
    size_t size_even = 0, size_odd = 0;
    int* array_odd = create_array(size);
    int* array_even = create_array(size);
    while (std::cin >> number){
        if (number % 2 == 0){
            array_even[size_even] = number;
            size_even ++;
        }
        else{
            array_odd[size_odd] = number;
            size_odd ++;
        }
    }
    sort(array_even, size_even);
    sort(array_odd, size_odd);
    for (int i = 0; i < size_even; i ++){
        std::cout << array_even[i] << ' ';
    }
    for (int i = 0; i < size_odd; i ++){
        std::cout << array_odd[i] << ' ';
    }
    delete[] array_even;
    delete[] array_odd;
    return 0;
}
