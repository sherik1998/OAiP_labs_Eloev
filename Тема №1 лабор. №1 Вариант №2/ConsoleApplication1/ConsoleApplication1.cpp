#include "stdafx.h"
#include "iostream"
#include <stdio.h>
using namespace std;


int main()
{
	float a;
	printf ( "Enter the number of nodes: ") ; 
	scanf_s("%f", &a);
	float c = a *1.85;
	float b = (c * 1000) / 3600;
	printf("%.1f km/h \n", c);
	printf("%.1f m/s \n", b);
	system("pause");
	return 0;
}