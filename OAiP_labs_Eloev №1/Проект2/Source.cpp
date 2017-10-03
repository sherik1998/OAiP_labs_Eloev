/*Елоев Георгий Александрович
КТБО 1-8
Лабораторная № 1
Вариант №2
Задание: Перевести узлы в км/ч и м/с*/
#include <stdio.h>
#define nodes_in_km_h 1.85 
#define km_h_in_m_s 1000/3600

int main()
{
	system("chcp 1251");
	system("cls");
	float node;
	printf("Введите количество узлов: ");
	int x;
	do
	{
		x = scanf_s("%f", &node);
		if (!x)
		{
			printf("Ошибка ввода!!!!!!\nПовторите попытку ввода: ");
			while (getchar() != '\n');
		}
		else
		{
			float km_h = node * nodes_in_km_h;
			float m_s = km_h * km_h_in_m_s;
			printf("%.1f узлов = %.1f км/ч = %.1f м/с  \n", node , km_h,m_s);
		}
	} while (x != 1);
	_getch();
	return 0;
}