double find_root(double (*f)(double), double a, double b, double tol)
{
    const double eps = 1.0 / 1000000.0;
    double x = (a + b) / 2;
    double y = f(x);
    if (std::abs(y) < eps || b - a < tol){
        return x;
    }
    else{
        if (a < b){
            if (y < 0){
                find_root(f, x, b, tol);
            }
            else{
                find_root(f, a, x, tol);
            }
        }
        else{
            if (y < 0){
                find_root(f, a, x, tol);
            }
            else{
                find_root(f, x, b, tol);
            }
        }
    }
}
