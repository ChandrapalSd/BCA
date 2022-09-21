// Question Statement
/*
    Write a program in C/C++ to find the solution of system of linear equations (given
    below), by using Gauss- Elimination method:
    x +  y +  z =  2
    x - 2y + 3z =  14
    x + 3y - 6z = -23
*/



#include<iostream>
#include<iomanip>
#include<cmath>
#define N 3

using namespace std;

void printMatrix(float Matrix[][N+1], int precesion=4)
{
    
	cout<<"\nUpper Triangular Matrix is:\n";
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N+1; j++)
		    cout<<setw(8)<<setprecision(precesion)<<Matrix[i][j];
		cout<<endl;
	}
}

//make matrix upper triangular Matrix
void makeMatrixUpTriangular(float Matrix[][N+1])
{
    float temp;
	for(int i=0; i<N-1; i++)
	{
		for(int j=i+1; j<N; j++)
		{
			temp=Matrix[j][i]/Matrix[i][i];

			for(int k=i; k<N+1; k++)
				Matrix[j][k]-=Matrix[i][k]*temp;
		}

	}
}	

int main()
{
	float Matrix[N][N+1], // Augmented matrix
          x[N];           // Solution matrix
	

	cout<<"Enter Elements of "<<N<<" Rows & "<<N+1<<" Columns of augmented matrix \n";

	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N+1; j++)
		    cin>>Matrix[i][j];
	}

	//make above matrix upper triangular Matrix
    makeMatrixUpTriangular(Matrix);
	
	//print the Upper Triangular matrix
    printMatrix(Matrix);
	
	
	//find values of x,y,z using back substitution
	for(int i=N-1; i>=0; i--)
	{
		float s = 0;

		for(int j=i+1; j<N; j++)
		    s += Matrix[i][j]*x[j];

		x[i]=(Matrix[i][N]-s)/Matrix[i][i];
	}

	//print values of x,y,z
	cout<<"\n\nThe Solution is: \n";

	for(int i=0; i<N; i++)
	 cout<<"x["<<i+1<<"] = "<<setprecision(4)<<x[i]<<endl;


    return 0;
}

