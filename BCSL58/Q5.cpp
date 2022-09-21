// Question Statement
/*
    Q5.
    Write a program in C/C++ to calculate the value of “cos x” by using the series
    expansion given below:
    
    cos x = 1 - (x^2/ 2!) + (x^4/4!) + ...

    Note: Evaluate cos x only upto first three terms.
    Also find the value of cos x by using the inbuilt function.
    Compare the results i.e., the result produced by your program and that produced by
    inbuilt function. Based on comparison, determine error.
*/

#include <cmath>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

double cosTaylor(double x, double n) // n : numbers of terms
{
    vector<long> factorial(2*(n));

    factorial[0] = 1;
    for (long i = 1; i < factorial.size(); i++)
    {
        factorial[i] = factorial[i-1] * i;
    }
    

    double result = 1;
    for (long i = 2; i <= n; i++)
    {
        double term = pow(x, (i-1)*2) / (double)factorial[(i-1)*2];
        
        if (i%2 == 0)
        {
            result -= term;
        }
        else
        {
            result += term;
        }
    }

    return result;
    
}

int main()
{
    double x ;

    cout << "Enter x for cos(x) : ";
    cin >> x;

    double cosxMY = cosTaylor(x, 3); // For better accuracy use number of terms = 10
    double cosxSTL = cosf(x);
    double diff = abs(cosxMY-cosxSTL);

    cout << "Cos("<<x<<") :(By 3 terms of taylor series) : " <<setprecision(4) <<cosxMY << endl;
    cout << "Cos("<<x<<") :(By stl inbuilt cos funciton) : " <<setprecision(4) <<cosxSTL <<endl<< endl;

    cout << "Difference between both the values :"<< diff << endl;

    cout << "Relative error = " << setprecision(4)<<abs(diff/cosxMY)*100 << "% \n";

}
