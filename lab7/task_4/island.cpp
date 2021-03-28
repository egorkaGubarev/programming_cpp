#include <iostream>
#include <string>

struct villager
{
    std::string name;
    int kind;
    bool is_alive = true;
};

int main()
{
    int N, truth;
    std::cin >> N >> truth;
    villager* population = new villager[N + 1];
    for (int i = 1; i <= N; i ++){
        std::cin >> population[i].name;
        std::cin >> population[i].kind;
    }
    int M;
    std::cin >> M;
    int house_number, itter;
    int live_amount = N;
    for (int day = 1; day <= M; day ++){
        itter = day - 1;
        house_number = (itter % N) + 1;
        while (!population[house_number].is_alive){
            house_number ++;
            if (house_number > N){
                house_number = 1;
            }
        }
        if (population[house_number].kind == 0){
            if (truth == 0){
                truth = 1;
            }
            else{
                truth = 0;
            }
        }
        if (live_amount > 1){
            if (population[house_number].kind == 0 && truth == 1){
                population[house_number].kind = 1;
            }
            else{
                if (population[house_number].kind == 1 && truth == 0){
                    population[house_number].is_alive = false;
                    live_amount --;
                }
            }
        }
    }
    for (int i = 1; i <= N; i++){
        if (population[i].is_alive){
            std::cout << population[i].name << ' ' << population[i].kind << '\n';
        }
    }
    delete[] population;
    return 0;
}
