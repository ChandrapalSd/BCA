// Question Statement
/*
Q4.
Write a program in C/C++ to find the value of Sin( 𝜋 /6) by using Lagrange's
Interpolation, the related data is given below
x           : 0     𝜋/4         𝜋/2
y= Sin(x)   : 0     0.70711     1.0
*/

#include <iostream>
#include <cmath>

double interpolate(double x[], double y[], int n, double xp)
// n : number  of data points, xp : interpolating point
{

    double yp = 0;

    for (int i = 0; i < n; i++)
    {
        double term = 1;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            term *= ( (xp - x[j]) / (x[i] - x[j]) );
        }
        
        yp += ( term * y[i] );
    }
    
    return yp;
}

int main()
{
    int n = 3;
    double xp = M_PI/6;
    double x[n] = {0, M_PI_4, M_PI_2};
    double y[n] = {0, 0.70711, 1.0};

    std::cout<<"Value of Sin("<<xp<<") = "<<interpolate(x, y, n, xp) << std::endl;

    return 0;
}
