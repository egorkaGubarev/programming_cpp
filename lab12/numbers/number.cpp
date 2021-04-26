#include<iostream>
#include<vector>

int main()
{
    int K, N;
    std::cin >> N >> K;
    std::vector<long long> amount_no_nills(N + 1);
    std::vector<long long> amount_one_nill(N + 1);
    amount_no_nills[1] = (K - 1);
    amount_one_nill[0] = 1;
    for (int digits_amount = 1; digits_amount <= N; digits_amount ++){
        amount_no_nills[digits_amount] = (amount_no_nills[digits_amount - 1] + amount_one_nill[digits_amount - 1]) * (K - 1);
        amount_one_nill[digits_amount] = amount_no_nills[digits_amount - 1];
    }
    long long amount = amount_no_nills[N] + amount_one_nill[N];
    std::cout << amount;
    return 0;
}
