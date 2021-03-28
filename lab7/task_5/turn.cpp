#include <iostream>

int main()
{
    int N;
    std::cin >> N;
    int* p_matrix = new int[N * N];
    int** matrix = new int*[N];
    for (int i = 0; i < N; i ++){
        matrix[i] = p_matrix + N * i;
    }
    for (int i = 0; i < N; i ++){
        for (int j = 0; j < N; j ++){
            std::cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < N; i ++){
        for (int j = 0; j < N; j ++){
            std::cout << matrix[N - 1 - j][i] << ' ';
        }
        std::cout << '\n';
    }
    delete[] matrix;
    delete[] p_matrix;
    return 0;
}
