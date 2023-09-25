//Name:¼B®a¦¨
//Date:2023/4/19
//Last Update:2023/4/20
//Problem statement:Matrix Multiplication

#include <iostream>
using namespace std;

int main()
{
	int** matrixA; //create a double array of matrix A
	int** matrixB; //create a double array of matrix B
	int rowA = 0; //row of matrix A
	int colA = 0; //column of matrix A
	int rowB = 0; //row of matrix B
	int colB = 0; //column of matrix B
	while (cin >> colA >> rowA >> colB >> rowB) //input the row and column of matrix A and B
	{
		matrixA = new int* [colA]; //create a double array of matrix A
		matrixB = new int* [colB]; //create a double array of matrix B
		for (int i = 0; i < colA; i++)
		{
			matrixA[i] = new int[rowA]; //create a double array of matrix A
		}
		for (int i = 0; i < colB; i++)
		{
			matrixB[i] = new int[rowB]; //create a double array of matrix B
		}
		for (int i = 0; i < colA; i++)
		{
			for (int j = 0; j < rowA; j++)
			{
				cin >> matrixA[i][j]; //input the value of matrix A
			}
		}
		for (int i = 0; i < colB; i++)
		{
			for (int j = 0; j < rowB; j++)
			{
				cin >> matrixB[i][j]; //input the value of matrix B
			}
		}
		if (rowA != colB) //if the row of matrix A is not equal to the column of matrix B, the multiplication is not possible
		{
			cout << "Matrix multiplication failed." << endl; //output the error message
		}
		else //if the row of matrix A is equal to the column of matrix B, the multiplication is possible
		{
			int** matrixC; //create a double array of matrix C
			matrixC = new int* [colA]; //the column of matrix C is equal to the column of matrix A
			for (int i = 0; i < colA; i++)
			{
				matrixC[i] = new int[rowB]; //the row of matrix C is equal to the row of matrix B
			}
			for (int i = 0; i < colA; i++)
			{
				for (int j = 0; j < rowB; j++) 
				{
					matrixC[i][j] = 0; //initialize the value of matrix C
					for (int k = 0; k < rowA; k++)
					{
						matrixC[i][j] += matrixA[i][k] * matrixB[k][j]; //calculate the value of matrix C
					}
				}
			}
			for (int i = 0; i < colA; i++)
			{
				for (int j = 0; j < rowB; j++) 
				{
					if (j != rowB - 1) //if the value is not the last one in the row, output a space
						cout << matrixC[i][j] << " ";
					else //if the value is the last one in the row, output a new line
						cout << matrixC[i][j];
				}
				cout << endl; //output a new line
			}
		}
	}
}