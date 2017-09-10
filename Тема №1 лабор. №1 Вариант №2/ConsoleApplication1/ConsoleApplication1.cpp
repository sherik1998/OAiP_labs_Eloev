// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
using namespace std;


int main()
{
	setlocale(0, "Russian"); 
	float a;
	printf ( "Enter the number of nodes: ") ; 
	cin >> a;  
	float c = a *1.85;
	float b = (c * 1000) / 3600;
	cout << c << "km/h" << endl;
	cout << b << "m/s" << endl;
	system("pause");
	return 0;
}