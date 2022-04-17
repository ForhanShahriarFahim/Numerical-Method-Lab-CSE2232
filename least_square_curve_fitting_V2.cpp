#include <bits/stdc++.h>
using namespace std;
class LeastSquare
{
private:
    /* data */
public:
    double sumX = 0.0, sumY = 0.0, sumX2 = 0.0, sumXY = 0.0;
    void calculation(double x[], double y[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            sumX += x[i];
            sumY += y[i];
            sumXY += x[i] * y[i];
            sumX2 += x[i] * x[i];
        }
        

        double a, b;
        b = (n * sumXY - sumX * sumY) / ((n * sumX2) - (sumX * sumX));
        a = (sumY - b * sumX) / n;
        cout << "The equation is : "
             << "Y = " << b << "X + " << a;
    }
};

int main()
{
    int n;
    cin >> n;
    double x[n], y[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    LeastSquare ls;
    ls.calculation(x, y, n);
}


/* 5
95 90
85 80 
80 70 
70 65 
60 60 */