#include <iostream>

int main()
{
    int distanceToMiddle;
    int i;
    int j;
    int middle;
    int N;
    int rowsAmount;
    std::cin >> N;
    middle = (N - 1) / 2;
    rowsAmount = (N + 1) / 2;
    for (i=0; i<rowsAmount; i++){
        for (j=0; j<N; j++){
            distanceToMiddle = abs(middle - j);
            if (distanceToMiddle < rowsAmount - i){
                std::cout << "*";
            }else{
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
    return 0;
}
