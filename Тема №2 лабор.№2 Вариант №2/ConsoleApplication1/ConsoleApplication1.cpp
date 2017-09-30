// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
using namespace std;


int main()
{
	int array[100];
	int x;
	int a;
	x = 0;
	printf("Enter the length of the array:");
	scanf_s ("%d", &a);
	while (x == 0);
	{
		scanf_s("%d", &a);
		if ((a <= 100) && (a > 0)) 
		{
			printf("Good!!");
			x = 1;
		}
		else
		{
			printf("Error. Length may not exceed 1000 and be less than 0 , and may contain letters!!");
			printf("Enter the length of the array:");
			x = 0;
		}
	}
	int c;
	for (int i = 0; i <= (a - 1); i = i + 1)
 {
           printf("Set the array:");
		   cin >> array[i];
	}
	for (int i = 0; i <= (a - 2); i = i + 1) 
	{
		if (array[i] > array[i + 1]) {
			c = array[i + 1];
			array[i + 1] = array[i];
			array[i] = c;
		}
	}
	for (int i = 0; i <= (a - 3); i = i + 1)
	{
		if (array[i] < array[i + 1]) {
			c = array[i + 1];
			array[i + 1] = array[i];
			array[i] = c;
		}
	}
	float b;
	b = 0;
	for (int i = 0; i <= (a - 3); i = i + 1)
		b = b + array[i];
	b = b / (a - 2);
	cout << "The arithmetic average of the array minimum and maximum values equal to :" << b << endl;
	system("pause");
	return 0;

}

