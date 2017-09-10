// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
using namespace std;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int a;
	printf ( "Enter the number of nodes: ") ; 
	cin >> a;  
	float c = a *1.85;
	float b = (c * 1000) / 3600;
	cout << c << " km/h" << endl;
	cout << b << " m/s" << endl;
	system("pause");
	return 0;
}