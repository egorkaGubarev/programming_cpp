#include <iostream>
#include <vector>

int main()
{
    size_t N;
    std::cin >> N;
    std::vector<int> ladder(N + 1, 0);
    for (size_t i = 1; i <= N; i ++){
        std::cin >> ladder[i];
    }
    std::vector<int> sum(N + 1);
    sum[1] = ladder[1];
    std::vector<int> route_reversed(N + 1, 0);
    for (size_t i = 2; i <= N; i ++){
        if (sum[i - 2] < sum[i - 1]){
            sum[i] = sum[i - 1] + ladder[i];
            route_reversed[i] = i - 1;
        }
        else{
            sum[i] = sum[i - 2] + ladder[i];
            route_reversed[i] = i - 2;
        }
    }
    std::cout << sum[N] << '\n';
    int stage = N;
    std::vector<int> route(N + 1, 0);
    while (stage > 0){
        route[stage] = route_reversed[stage];
        stage = route_reversed[stage];
    }
    for (size_t i = 0; i <= N; i ++){
        if (route[i] > 0){
            std::cout << route[i] << ' ';
        }
    }
    std::cout << N;
    return 0;
}
