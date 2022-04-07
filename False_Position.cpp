#include <bits/stdc++.h>
using namespace std;

class FalsePosition
{
private:
    double eps;

private:
    double a, b, root;

public:
    FalsePosition()
    {
        a = 0, b = 0, root = -1, eps = 0.0000000001;
    }

public:
    double f(double x)
    {
        return x * x * x - x * x + 2;
    }

public:
    double getNext(double x0, double x1)
    {
        return (x0*f(x1) - x1*f(x0)) / (f(x1) - f(x0));
    }

public:
    void findInterval()
    {
        do
        {
            a--, b++;
        } while (f(a) * f(b) > 0);

        if (f(b) < 0)
            swap(a, b);

        return;
    }

public:
    double getRoot()
    {
        return root;
    }

public:
    void findRoot()
    {
        findInterval();
        double mid = getNext(a, b);
        // Driver program to test above function 
        while (abs(f(b) - f(a)) > eps)
        {            
            if(f(mid) == 0) break;
            else if (f(mid)*f(a)<0) b = mid;
            else a = mid;
            mid = getNext(a, b);
        }

        root = mid;
    }
};

int main()
{
    FalsePosition falsePosition;
    falsePosition.findRoot();
    printf("The root of the given equation : %0.10lf\n", falsePosition.getRoot());
}