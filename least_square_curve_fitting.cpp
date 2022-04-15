#include<bits/stdc++.h>
using namespace std;
//least square curve fitting

class Point
{

public:
    double x;
    double y;

    Point(double x, double y)
    {
        
        this->x = x;
        this->y = y;
        cout<<"x="<<x<<"y="<<y<<endl;
    }
};
class curve_fitting_least_square
{
    private: double ans[2];//ans[0] is the slope, ans[1] is the intercept    
    private: double sum_y, sum_x, sum_xy, sum_xx;//sum_y is the sum of y, sum_x is the sum of x, sum_xy is the sum of x*y, sum_xx is the sum of x*x
    private: int m;
    private:
        vector<Point> points;

    public :
        curve_fitting_least_square(vector<Point> points)
        {  
            this->points = points;
            sum_x = 0, sum_y = 0, sum_xy = 0, sum_xx = 0;          
            m = points.size();                 
    }

    public: void least_square()
    {
        for (auto point : points)
        {
            sum_x += point.x;
            sum_y += point.y;
            sum_xy += point.x * point.y;
            sum_xx += point.x * point.x;
        }
        double b = (sum_x * sum_y - m * sum_xy) / (sum_x * sum_x - m * sum_xx);
        double a = (sum_y * sum_xx - sum_x * sum_xy) /( m * sum_xx - sum_x * sum_x);
    
        //cout<<"a="<<a<<" b="<<b<<endl;
        ans[0] = a;
        ans[1] = b;
        //return ans;
    }
    public: void get_ans()
    {
        cout << ("Regression line:") << endl;
        cout << ("Y = ");
        printf("%.3lf + ", ans[0]);
        printf("%.3lf *X", ans[1]);
    }    
};

int main()
{
    vector<Point> p;
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        double x, y;
        //printf("Enter the x and y values: ");
        scanf("%lf %lf", &x, &y);
        p.push_back(Point(x, y));       
    
    }
    curve_fitting_least_square *ls = new curve_fitting_least_square(p);
    

    ls->least_square();
    ls->get_ans();

    return 0;
}

/* Test Case:
5
x: y:
95 90
85 80
80 70
70 65
60 60
 */