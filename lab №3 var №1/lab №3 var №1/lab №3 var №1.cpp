/*
	����� ������� �������������
	������������ ������ �3
	������� �1
	�������: �������� ���������, ������� �� �������� � ���������� ������
	������� ��� ��������� ���� ���� �� ���� � ������� ��������� �� �����.
*/

  

#include <stdio.h>
#include <conio.h>
#include <locale>

#define MAX_LENGTH 1024
#define SYMBOL '!',' ',';','.',',','?',':','-',')','}',']','"'

int editText(char *text);

int main()
{
	system("chcp 1251");
	system("cls");
	char text[MAX_LENGTH];
	printf("\t������� ��� �����:\n");
	fgets(text, MAX_LENGTH, stdin);
	editText(text);
	printf("\t���������� �����:\n");
	puts(text);
	_getch();
	return 0;
}

int editText(char *text)
{
	for (int i = 2; text[i] != '\0'; i++)
	{
		if ((text[i] == SYMBOL || text[i] == '\n') && text[i - 1] == '�' && text[i - 2] == '�')
		{
			text[i - 1] = '�';
			text[i - 2] = '�';
		}
	}
	return 0;
} 