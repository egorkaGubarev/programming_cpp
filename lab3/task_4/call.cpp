#include <iostream>

int do_some_awesome_work(int* a, int* b)
{
    int v_a, v_b, c;
    v_a = *a;
    v_b = *b;
    c = v_a + v_b;
    return c;
}

int main()
{
    int a, b, c;
    int* p_a;
    int* p_b;
    std::cin >> a >> b;
    p_a = &a;
    p_b = &b;
    c = do_some_awesome_work(p_a, p_b);
    std::cout << c;
    return 0;
}
