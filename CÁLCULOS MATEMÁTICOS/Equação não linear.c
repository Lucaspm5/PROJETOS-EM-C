#include <stdio.h>
#include <math.h>

double f(double x) {
    return cos(x) - x;
}

double bisseccao(double a, double b, double tol) 
{
    double c;
    int n = 0;

    while((b-a)/2 > tol) {
        c = (a+b)/2;
        if(f(c) == 0) {
            return c;
        }else if(f(a)*f(c) < 0) {
            b = c;
        }else{
            a = c;
        }
        n++;
    }

    printf("Foram necessárias %d iterações.\n", n);
    return c;
}

int main(int argc, char const **argv) 
{
    double a = 0, b = 1, tol = 0.0001;
    double raiz = bisseccao(a, b, tol);
    
    printf("A raiz da função é: %lf\n", raiz);
    
    return 0;
}
