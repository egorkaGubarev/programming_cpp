#include <iostream>

int main()
{
    unsigned short int coord_amount, field_size, i, j, K, M, N, x, y;
    short int near_x, near_y;
    std::cin >> N >> M;
    std::cin >> K;
    coord_amount = 2 * K;
    field_size = N * M;
    unsigned short int* matrix1 = new unsigned short int[coord_amount];
    unsigned short int** field_input = new unsigned short int*[K];
    for (unsigned short int i = 0; i < K; i ++){
        field_input[i] = matrix1 + 2 * i;
    }
    short int* matrix2 = new short int[N * M];
    short int** field = new short int*[N];
    for (unsigned short int i = 0; i < N; i ++){
        field[i] = matrix2 + M * i;
    }
    for (unsigned short i = 0; i < N; i ++){
        for (unsigned short j = 0; j < M; j ++){
            field[i][j] = 0;
        }
    }
    for (unsigned short int i = 0; i < K; i ++){
        for (unsigned short int j = 0; j < 2; j ++){
            std::cin >> field_input[i][j];
        }
        x = field_input[i][0] - 1;
        y = field_input[i][1] - 1;
        field[x][y] = -1;
        for (short int itt_x = -1; itt_x < 2; itt_x ++){
            near_x = x + itt_x;
            if (near_x >= 0 and near_x < N){
                for (short int itt_y = -1; itt_y < 2; itt_y ++){
                    near_y = y + itt_y;
                    if (near_y >= 0 and near_y < M){
                        if (itt_x != 0 or itt_y != 0){
                            if (field[near_x][near_y] != -1){
                                field[near_x][near_y] ++;
                            }
                        }
                    }
                }
            }
        }

    }
    for (unsigned short int i = 0; i < N; i ++){
        for (unsigned short int j = 0; j < M; j ++){
            std::cout << field[i][j] << ' ';
        }
        std::cout << '\n';
    }
    delete[] field_input;
    delete[] field;
    delete[] matrix1;
    delete[] matrix2;
    return 0;
}
