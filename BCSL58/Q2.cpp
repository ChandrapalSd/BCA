// Question Statement
/*
Q2. Write a program in C/C++ to determine the approximate value of the definite integral
(I) (given below), by using Simpson's (1/3)rd rule:

I = ∫ x^(1/3) dx,
lower limit=0.2 , upper limit = 1.0
Using step size (h) = 0.2 
*/

#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

float f(float x)
{
    float result = pow(x, 0.3333333333F);
    // cout<< endl << "f(" << x << ") = "<<setprecision(54) << result << endl;
    return result;
}

float integrate(float ll, float ul, float h)
{
    int n = (ul - ll)/h;
    float result = f(ll) + f(ul);

    for(int i=1; i< n; i++)
    {
        float k = ll + float(i)*h;

        if(i%2==0)
        {
            result +=  2 * (f(k));
        }
        else
        {
            result += 4 * (f(k));
        }

    }

    result = result * h/3;

    return result;
}

int main()
{

    float ll, ul, h;

    cout<<"Enter lower limit : ";
    cin>>ll;
    cout<<"Enter upper limit : ";
    cin>>ul;
    cout<<"Enter step size (h) : ";
    cin>>h;

    cout<<"Result : "<<setprecision(4)<<integrate(ll, ul, h)<<endl;

    return 0;
}
