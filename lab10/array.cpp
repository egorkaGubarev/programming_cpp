#include <iostream>

int main()
{
    int N;
    std::cin >> N;
    int* array = new int[N];
    for (int i = 0; i < N; i ++){
        std::cin >> array[i];
    }
    for (int i = N - 1; i >= 0; i --){
        std::cout << array[i] << ' ';
    }
    delete[] array;
    return 0;
}
