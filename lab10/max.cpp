#include <iostream>

double F(int k)
{
    if (k == 1){
        return (double)0.7*100;
    }
    else{
        return (double)0.7*(100 + 2*(F(k - 1)));
    }
}

double M(int k)
{
    if (k == 1){
        return (double)0.3*100 + 10;
    }
    else{
        return (double)0.3*(100 + 2*(F(k - 1))) + 10;
    }
}

int main()
{
    int n;
    std::cin >> n;
    double result = M(n);
    std::cout « static_cast<int64_t>(result);
    return 0;
}
