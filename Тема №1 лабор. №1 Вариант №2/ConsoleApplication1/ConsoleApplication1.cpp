#include "stdafx.h"
#include <stdio.h>


int main()
{
	float a;
	printf ( "Enter the number of nodes: ") ;
	int x = 0;
	while (x==0)
	{
		scanf_s("%f", &a);
		int r = scanf_s("%f", &a);
		if (!r)
		{
			printf("Error!");
			while (getchar() != "\n");
		}
		else
		{
			float c = a *1.85;
			float b = (c * 1000) / 3600;
			printf("%.1f km/h \n", c);
			printf("%.1f m/s \n", b);
			x = 1;
		}
	}
	getch();
	return 0;
}