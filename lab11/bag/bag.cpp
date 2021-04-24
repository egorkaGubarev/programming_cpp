#include <iostream>
#include <vector>

int main()
{
    int N, W;
    std::cin >> W >> N;
    std::vector<int> prize(N + 1);
    for (int i = 1; i <= N; i ++){
        std::cin >> prize[i];
    }
    std::vector<int> weight(N + 1);
    for (int i = 1; i <= N; i ++){
        std::cin >> weight[i];
    }
    std::vector<std::vector<int>> table(W + 1, std::vector<int> (N + 1, 0));
    for (int i = 1; i <= W; i ++){
        for (int j = 1; j <= N; j ++){
            if (i < weight[j]){
                table[i][j] = table[i][j - 1];
            }
            else{
                table[i][j] = std::max(table[i][j - 1], table[i - weight[j]][j - 1] + prize[j]);
            }
        }
    }
    std::cout << table[W][N];
    return 0;
}
