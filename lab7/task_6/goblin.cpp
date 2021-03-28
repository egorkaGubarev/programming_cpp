#include <iostream>

int* insert(int* p_array, size_t size, int position, int value)
{
    for (int i = size - 1; i >= position; i --){
        p_array[i + 1] = p_array[i];
    }
    p_array[position] = value;
    return p_array;
}

int* make_array(size_t size)
{
    int* p_array = new int[size];
    return p_array;
}

int pop(int* p_array, size_t size)
{
    int value = p_array[0];
    for (int i = 0; i < size - 1; i ++){
        p_array[i] = p_array[i + 1];
    }
    return value;
}

void print_array(int* p_array, size_t size)
{
    for (int i = 0; i < size; i++){
        std::cout << p_array[i] << ' ';
    }
}

int* zero_array(int* p_array, size_t size)
{
    for (int i = 0; i < size; i++){
        p_array[i] = 0;
    }
    return p_array;
}

int main()
{
    char call;
    int calls_amount, center, delete_number, number, length_round;
    int length = 0, length_max = 1000;
    int* queue = make_array(length_max);
    queue = zero_array(queue, length_max);
    std::cin >> calls_amount;
    for (int i = 0; i < calls_amount; i++){
        std::cin >> call;
        if(call == '+' || call == '*'){
            std::cin >> number;
            if (call == '+'){
                queue[length] = number;
                length ++;
            }
            else{
                if (length % 2 != 0){
                    length_round = length + 1;
                    center = length_round / 2;
                }
                else{
                    center = length / 2;
                }
                queue = insert(queue, length, center, number);
                length ++;
            }
        }
        else{
            delete_number = pop(queue, length);
            length --;
            std::cout << delete_number << '\n';
        }
    }
    delete[] queue;
    return 0;
}
