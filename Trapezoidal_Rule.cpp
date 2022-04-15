#include <bits/stdc++.h>

using namespace std;

class Trapezoidal
{
private:
    double a, b, sum,h;
    int n;    

private:
    double function(double x)
    {

        return 1 / (1 + x * x);
    }

public:
    Trapezoidal()
    {
        a = 0, b = 0, sum = 0, h = 0;
    }    
public: 
    double solve(double b, double a, int n)
    {
        this->a = a;
        this->b = b;
        this->n = n;
          
        h = (b - a) / n;
        //cout<<"h="<<h<<endl;
        // Computing sum of first and last terms
        sum = function(a) + function(b);

        // Adding middle terms
        for (int i = 1; i < n; i++)
        {
            sum += 2 * function(a + i * h);
        }

        return (h / 2) * sum;
    }
};

int main()
{

    Trapezoidal trapezoidal;
    printf("Value of integral is %6.4f\n",trapezoidal.solve(1,0,100));
    return 0;
}