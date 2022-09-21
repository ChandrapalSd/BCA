// Question Statement
/*
    Q3.
    Write a program in C or C++ to demonstrate the following operations, for the
    function f(x) = x^2 + x + 7 :

    (a) Forward Difference Operator
    (B) Central Difference Operator
*/

#include <iostream>
#include <vector>

using namespace std;

float f(float x)
{
    return (x * x + x + 7);
}

int main()
{

    int i, j, n;

    /* Input Section */
    cout << "Enter number of data? " << endl;
    cin >> n;

    vector<vector<float>> y(n, vector<float>(n,0));

    for (i = 0; i < n; i++)
    {
        y[i][0] = f(i);
    }

    /* Generating Forward Difference Table */
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
    }

    /* Displaying Forward Difference Table */
    cout << endl
         << "FORWARD DIFFERENCE TABLE" << endl;
    for (i = 0; i < n; i++)
    {
        cout << i;
        for (j = 0; j < n - i; j++)
        {
            cout << "\t" << y[i][j];
        }
        cout << endl;
    }

    return 0;
}
