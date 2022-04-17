#include<bits/stdc++.h>
using namespace std;

class Secant
{
    private: double eps;
    private: double a, b, root, x0, x1;

    public: Secant()
    {
        srand((int)time(0));
        a = rand() % 100;
        b = rand() % 100;
        root = 0;
        x0 = 5;
        x1 = 10;       
    }

    public: double f(double x)
    {
        return x * x * x - 2 * x - 5;
    }

    public: double getRoot()
    {
        return root;
    }

    public: void findRoot(double eps)
    {
        do{
            double x2 = ((x0 * f(x1)) - (x1 * f(x0))) / (f(x1) - f(x0));
            x0 = x1;
            x1 = x2;
            root = x2;
        }while(abs(x1 - x0)>=eps);
    }
};

int main()
{
    Secant secant;
    secant.findRoot(0.00001);
    printf("The root of the given equation : %0.10lf\n", secant.getRoot()); 
}