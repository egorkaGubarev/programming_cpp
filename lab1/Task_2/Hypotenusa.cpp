#include <iostream>
#include <cmath>

int main()
{
    double leg1;
    double leg2;
    double hypotenusa;
    std::cin >> leg1;
    std::cin >> leg2;
    hypotenusa = sqrt(pow(leg1, 2) + pow(leg2, 2));
    std::cout << hypotenusa;
    return 0;
}
