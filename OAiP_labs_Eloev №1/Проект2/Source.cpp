/*Елоев Георгий Александрович
КТБО 1-8
Лабораторная № 1
Вариант №2
Задание: Перевести узлы в км/ч и м/с*/
#include <stdio.h>
#define N 1.85 
#define C 1000/3600

int main()
{
	system("chcp 1251");
	system("cls");
	float a;
	printf("Введите количество узлов: ");
	int x;
	do
	{
		x = scanf_s("%f", &a);
		if (!x)
		{
			printf("Ошибка ввода!!!!!!\nПовторите попытку ввода: ");
			while (getchar() != '\n');
		}
		else
		{
			float c = a *N;
			float b = c * C;
			printf("%.1f узлов = %.1f км/ч = %.1f м/с  \n",a,c,b); 
		}
	} while (x != 1);
	_getch();
	return 0;
}