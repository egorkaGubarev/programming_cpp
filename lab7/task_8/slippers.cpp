#include <iostream>

int* create_array (size_t size)
{
    int* array = new int[size];
    for (int i = 0; i < size; i ++){
        array[i] = 0;
    }
    return array;
}

int main()
{
    int j, N;
    std::cin >> N;
    int* array = create_array(N);
    int max_size = 0;
    for (int i = 0; i < N; i ++){
        std::cin >> array[i];
        if (array[i] > max_size){
            max_size = array[i];
        }
    }
    int distance = N + 1;
    for (int size = 0; size <= max_size; size ++){
        for (int i = 0; i < N; i ++){
            if (array[i] == -size){
                j = i;
                while (array[j] != size && j < N){
                    j ++;
                }
                if (j < N){
                    if (j - i < distance){
                        distance = j - i;
                    }
                }
                i = j;
            }
        }
    }
    delete[] array;
    if (distance < N + 1){
        std::cout << distance;
    }
    else{
        std::cout << 0;
    }
    return 0;
}
