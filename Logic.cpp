#include <iostream>
#include <math.h>
using namespace std;
float * input(int h,int w)
{
	int size;
	size = h * w;
	float* A = new float[size];
	
	for (int i = 0; i < size; i++)
	{
		if (i % w == 0)
		{
			cout << endl;
			cout << "Enter the " << i/w << " row:" << "\n";
		}
		while (cout << "Enter the "<<(i%w)+1<<" Element" && !(cin >> A[i])) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
			cout << "Invalid input; please re-enter the \n" << (i % w) + 1 << "Element";
		}
	}
	return A;
}

void output(float* A, int h,int w)
{
	int size = h * w;
	for (int i = 0; i < size; i++)
	{
		if (i % w == 0)
			cout << endl;
		cout << A[i] << " ";
	}
}

float* addition(float *A,float *B,int size)
{
	float* C = new float[size];
	for (int i = 0 ; i < size; i++)
	{
		C[i] = 0;
		C[i] = B[i] + A[i];
	}
	return C;
}

float* substruction(float A[], float B[], int size)
{
	bool a = 0;
	char n;
	cout << "Substraction A from B?(y/n)";
	cin >> n;
	float* C = new float[size];
	for (int i = 0; i < size; i++)
	{
		while (true)
		{
			if (n == 'n') { C[i] = B[i] - A[i]; break; }	
			else if (n == 'y') { C[i] = A[i] - B[i]; break; }
			else { cout << "Invalid Input, please try again"; }
		}
	}
	return C;
}

float* multiplication(float A[], float B[], int h, int w)
{
	char a;
	int size = h * w;
	float* C = new float[size];
	for (int i = 0; i < size; i++)
	{
		C[i] = 0;
	}
	while (true)
	{
		cout<<"How do you want to multiply matricies? 1:(A*B) or 2:(B*A)";
		cin >> a;
		if (a == '1' || a == '2')
			break;
		else
			cout << "Please, enter a valid number" << endl;
	}
	if (h == w)
	{
		for (int i = 0; i < size; i++)
		{
			for (int k = 0; k < w; k++)
			{
				if (a=='1')	C[i] = C[i] + A[k + ((i - (i % w)))] * B[k*w+i%w];// not wrong, has to have a pattern of 2x2 matrix 0 1; 2 3; 0 1; 2 3;
				if (a=='2')	C[i] = C[i] + B[k + ((i - (i % w)))] * A[k * w + i % w];
			}
		}
		return C;
	}
	
}

int main()
{
	int h, w,size;
	char oper;
	
	while(true)
	{
		cout << "Enter sizes of matricies(h=>w)";
		cin >> h >> w;
		cout << "Enter operand:";
		cin >> oper;
		if (((h > 0 && h<=10) &&( w > 0 && w<=10)) && (oper == '+' || oper == '-' || oper == '*'))
		{
			break;
		}
	}
	size = h * w;
	cout << size;
	float* a = new float[size];
	float* b = new float[size];
	cout << "Enter the 1 matrix:";
	a = input(h,w);
	cout << "Enter the 2 matrix:";
	b = input(h,w);
	if (oper == '-')
		output(substruction(a, b, size), h, w);
	if (oper == '+')
		output(addition(a, b, size), h, w);
	if (oper == '*')
		output(multiplication(a, b, h, w),h, w);
}