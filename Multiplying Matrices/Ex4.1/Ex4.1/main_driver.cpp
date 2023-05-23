#include <iostream>
using namespace std;
typedef int* IntArrayPtr;
int main()
{
	int rowA, columnA, rowB, columnB; //for rows and columns
	cout << "Please enter the number of rows for Matrix A:" << endl;
	cin >> rowA;
	cout << "Please enter the number of columns for Matrix A:" << endl;
	cin >> columnA;
	cout << "Please enter the number of rows for Matrix B:" << endl;
	cin >> rowB;
	cout << "Please enter the number of columns for Matrix B:" << endl;
	cin >> columnB;
	while (columnA != rowB)//if columns of A aren't equal to rows of B, it cannot be multiplied.
	{
		cout << "The columns of Matrix A are not equal to the rows of Matrix B, so they cannot be multiplied, please try again:" << endl;
		cout << "Please enter the number of rows for Matrix A:" << endl;
		cin >> rowA;
		cout << "Please enter the number of columns for Matrix A:" << endl;
		cin >> columnA;
		cout << "Please enter the number of rows for Matrix B:" << endl;
		cin >> rowB;
		cout << "Please enter the number of columns for Matrix B:" << endl;
		cin >> columnB;
	}
	IntArrayPtr* A = new IntArrayPtr[rowA];//new pointer matrixes, setting the amount of rows
	IntArrayPtr* B = new IntArrayPtr[rowB];
	int i, j;
	for (i = 0; i < rowA; i++)
	{
		A[i] = new int[columnA]; //setting the amount of columns
	}
	for (i = 0; i < rowB; i++)
	{
		B[i] = new int[columnB];
	}
	cout << "Matrix A: Enter " << rowA << "'s rows of " << columnA << " integers each, hitting enter after each one:" << endl;
	for (i = 0; i < rowA; i++)
	{
		for (j = 0; j < columnA; j++)
		{
			cin >> A[i][j]; //inputting values 
		}
	}
	cout << "Inputted values for Matrix A are:" << endl;
	for (i = 0; i < rowA; i++)
	{
		for (j = 0; j < columnA; j++)
		{
			cout << A[i][j] << " "; //displaying values
		}
		cout << endl;
	}
	cout << "Matrix B: Enter " << rowB << "'s rows of " << columnB << " integers each, hitting enter after each one:" << endl;
	for (i = 0; i < rowB; i++)
	{
		for (j = 0; j < columnB; j++)
		{
			cin >> B[i][j];
		}
	}
	cout << "Inputted values for Matrix B are:" << endl;
	for (i = 0; i < rowB; i++)
	{
		for (j = 0; j < columnB; j++)
		{
			cout << B[i][j] << " ";
		}
		cout << endl;
	}
	IntArrayPtr* C = new IntArrayPtr[rowA];
	for (i = 0; i < rowA; i++)
	{
		C[i] = new int[columnB];
	}
	int valueA, valueB, total;
	for (i = 0; i < rowA; i++)
	{
		for (j = 0; j < columnB; j++)
		{
			C[i][j] = 0;
			for (int k = 0; k < rowB; k++)
			{
				C[i][j] += A[i][k] * B[k][j]; //multiplying the matrices together.
			}
		}
	}
	cout << "Finished values for Matrix C are:" << endl;
	for (i = 0; i < rowA; i++)
	{
		for (j = 0; j < columnB; j++)
		{
			cout << C[i][j] << " ";
		}
		cout << endl;
	}
	for (i = 0; i < rowA; i++)
	{
			delete[] A[i];
	}
	for (i = 0; i < rowB; i++)
	{
		delete[] B[i];
	}
	for (i = 0; i < rowA; i++)
	{
		delete[] C[i];
	}
	delete A, B, C;
	 //deleting to ensure no  memory leakage.
	return 0;
}