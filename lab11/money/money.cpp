#include <iostream>
#include <vector>
#include <windows.h>

int main()
{
    int min, N, S;
    std::cin >> S >> N;
    std::vector<int> values(N);
    for (int i = 1; i <= N; i ++){
        std::cin >> values[i];
    }
    std::vector<std::vector<int>> table(S + 1, std::vector<int>(N + 1, 0));
    for (int i = 0; i <= S; i ++){
        table[i][0] = S + 1;
    }
    for (int i = 1; i <= S; i ++){
        for (int j = 1; j <= N; j ++){
            if (i - values[j] < 0){
                table[i][j] = table[i][j - 1];
            }
            else{
                table[i][j] = std::min(table[i][j - 1], table[i - values[j]][j] + 1);
            }
        }
    }
    if (table[S][N] == S + 1){
        std::cout << "--- Impossible ---" << '\n';
    }
    else{
        std::cout << table[S][N];
    }
    return 0;
}
