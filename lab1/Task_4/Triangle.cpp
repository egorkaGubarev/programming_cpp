#include <iostream>

int main()
{
    int i;
    int j;
    int N;
    std::cin >> N;
    for (i=0; i<N; i++){
        for (j=0; j<N; j++){
            if (i >= j){
                std::cout << "*";
            }else{
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
    return 0;
}
