#include <iostream>

int main()
{
    size_t N;
    std::cin >> N;
    size_t K;
    std::cin >> K;
    int d = -1;
    int* array = new int[N];
    for (int i = 0; i < N; i ++){
        std::cin >> array[i];
        if (array[i] == K){
            d = i + 1;
        }
    }
    std::cout << d;
    delete[] array;
    return 0;
}
