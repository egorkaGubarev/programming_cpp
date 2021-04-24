#include <iostream>

int main(){
    int N;
    std::cin >> N;
    int* array1 = new int[N];
    int* array2 = new int[N];
    for (int i = 0; i < N; i ++){
        std::cin >> array1[i];
    }
    for (int i = 0; i < N; i ++){
        std::cin >> array2[i];
    }
    for (int i = 0; i < N; i ++){
        for (int j = i; j < N; j ++){
            if (array1[j] > array1[i]){
                std::swap(array1[i], array1[j]);
                std::swap(array2[i], array2[j]);
            }
            else{
                if (array1[j] == array1[i] && array2[j] > array2[i]){
                    std::swap(array2[i], array2[j]);
                }
            }
        }
    }
    for(int i = N - 1; i >= 0; i--){
        std::cout << array1[i] << ' ';
    }
    std::cout << '\n';
    for (int i = N - 1; i >= 0; i--){
            std::cout << array2[i] << ' ';
    }
    delete[] array1;
    delete[] array2;
    return 0;
}
