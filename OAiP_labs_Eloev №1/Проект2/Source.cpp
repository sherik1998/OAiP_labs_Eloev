/*Елоев Георгий Александрович
КТБО 1-8
Лабораторная № 1
Вариант №2
Задание: Перевести узлы в км/ч и м/с*/
#include <stdio.h>
#define NODES_IN_KM_H 1.85 
#define KM_H_IN_M_S 1000/3600

int main()
{
	system("chcp 1251");
	system("cls");
	float node;
	printf("Введите количество узлов: ");
	int x;
	x = scanf_s("%f", &node);
	while (!x)
	{
		printf("Ошибка ввода!!!\nПовторите попытку ввода: ");
		while (getchar() != '\n');
		x = scanf_s("%f", &node);
	}
	float km_h = node * NODES_IN_KM_H;
	float m_s = km_h * KM_H_IN_M_S;
	printf("%.1f узлов = %.1f км/ч = %.1f м/с  \n", node, km_h, m_s);
	_getch();
	return 0;
}
