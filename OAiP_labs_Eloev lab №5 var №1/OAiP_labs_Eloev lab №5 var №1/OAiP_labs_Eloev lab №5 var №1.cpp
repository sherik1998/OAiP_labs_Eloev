/*
	Елоев Георгий Александрович
	Лабораторная работа №5
	Вариант №1
	Задание: Написать программу, которая записывает с клавиатуры в файл структуру
	согласно выданному варианту задания. В качестве разделителя полей структуры
	использовать символ табуляции. В программе реализовать:
	а) дополнение существующего массива структур новыми структурами;
	б) поиск структуры с заданным значением выбранного элемента;
	в) вывод на экран содержимого массива структур;
	г) упорядочение массива структур по заданному полю (элементу), например
	государство по численности.
	Варианты заданий:
	1. «Человек»: фамилия, имя, пол, рост, вес, дата
	рождения (число, месяц, год), номер телефона, домашний адрес (индекс, страна,
	область, город, улица, дом, квартира).
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <locale>

#define MAX_LENGTH 1024 
#define STRUCTURE_LENGTH 512

int initialization();
void input(int i);
void output(int i);
void seek(int i, int struc, char *Search, char *array);
void sort(int k, int j);
void print(int number);
void new_input(int number);

struct Struct
{
	char surname[MAX_LENGTH];
	char name[MAX_LENGTH];
	char sex[MAX_LENGTH];
	char growth[MAX_LENGTH];
	char weight[MAX_LENGTH];
	char date_number[MAX_LENGTH];
	char date_month[MAX_LENGTH];
	char date_year[MAX_LENGTH];
	char phone_number[MAX_LENGTH];
	char address_index[MAX_LENGTH];
	char address_country[MAX_LENGTH];
	char address_region[MAX_LENGTH];
	char address_city[MAX_LENGTH];
	char address_street[MAX_LENGTH];
	char address_house[MAX_LENGTH];
	char address_apartment[MAX_LENGTH];
	int price;
}People[STRUCTURE_LENGTH];

void main()
{
	system("chcp 1251");
	system("cls");
	char Search[MAX_LENGTH];
	int main_screen = 0;
	int number_of_structures = initialization();
	int sorting = 0;
	int search = 0;
	int i = 0;
	int struc = 0;
	int code;  
	Struct **q = new Struct*[STRUCTURE_LENGTH];
	do
	{
		printf("---Введите номер---\n");
		printf("1. Дополнить новой записью структуру.\n");
		printf("2. Поиск структуры по заданным значениям выбранного элемента.\n");
		printf("3. Вывод на экран содержимого структур.\n");
		printf("4. Упорядочение структур по заданному полю.\n");
		printf("5. Выход из программы.\n");
		printf("--> ");
		scanf_s("%d", &main_screen);
		system("cls");	//очищает экран

		switch (main_screen)
		{
		case 1:
			printf("--- Дополнить новой записью структуру ---\n");
			if (number_of_structures < STRUCTURE_LENGTH)	//проверка 
			{
				input(number_of_structures);
				number_of_structures++;
				system("pause");
				system("cls");
			}
			else
			{
				printf("--- Введенно максимально возможное количество структур ---");
			}
			break;
		case 2:
			if (number_of_structures != 0)
			{
				printf("---Введите номер---\n");
				printf("---Поиск структуры по заданным значениям выбранного элемента--- \n");
				printf("1. Поиск по Фамилии.\n");
				printf("2. Поиск по Имени.\n");
				printf("3. Поиск по Полу.\n");
				printf("4. Поиск по Росту.\n");
				printf("5. Поиск по Весу.\n");
				printf("6. Поиск по Числу рождения.\n");
				printf("7. Поиск по Месяцу рождения.\n");
				printf("8. Поиск по Году рождения.\n");
				printf("9. Поиск по Номер телефона.\n");
				printf("10. Поиск по Индексу.\n");
				printf("11. Поиск по Стране.\n");
				printf("12. Поиск по Региону.\n");
				printf("13. Поиск по Городу.\n");
				printf("14. Поиск по Улице.\n");
				printf("15. Поиск по Номеру дома.\n");
				printf("16. Поиск по Номеру квартиры.\n");
				printf("--> ");

				scanf_s("%d", &search);
				system("cls");

				switch (search)
				{
				case 1: printf(" --- Поиск по Фамилии --- \n");
					printf("Введите Фамилию\n -->");
					
					scanf("%s", &Search);
					for (i = 0; i < number_of_structures; i++)
					{
						seek(i, struc, Search, People[i].surname);
					}
					if (struc == 0)
					{
						printf("Структура не найденна\n");
					}
					struc = 0;
					system("pause");
					system("cls");
					break;
				case 2:printf(" --- Поиск по Имени --- \n");
					printf("Введите Имя\n -->");

					scanf("%s", &Search);
					for (i = 0; i < number_of_structures; i++)
					{
						seek(i, struc, Search, People[i].name);
					}
					if (struc == 0)
					{
						printf("Структура не найденна\n");
					}
					struc = 0;
					system("pause");
					system("cls");
					break;
				case 3:printf(" --- Поиск по Полу --- \n");
					printf("Введите Пол\n -->");

					scanf("%s", &Search);
					for (i = 0; i < number_of_structures; i++)
					{
						seek(i, struc, Search, People[i].sex);
					}
					if (struc == 0)
					{
						printf("Структура не найденна\n");
					}
					struc = 0;
					system("pause");
					system("cls");
					break;
				case 4:printf(" --- Поиск по Росту --- \n");
					printf("Введите Рост\n -->");

					scanf("%s", &Search);
					for (i = 0; i < number_of_structures; i++)
					{
						seek(i, struc, Search, People[i].growth);
					}
					if (struc == 0)
					{
						printf("Структура не найденна\n");
					}
					struc = 0;
					system("pause");
					system("cls");
					break;
				case 5:printf(" --- Поиск по Весу --- \n");
					printf("Введите Вес\n -->");

					scanf("%s", &Search);
					for (i = 0; i < number_of_structures; i++)
					{
						seek(i, struc, Search, People[i].weight);
					}
					if (struc == 0)
					{
						printf("Структура не найденна\n");
					}
					struc = 0;
					system("pause");
					system("cls");
					break;
				case 6:printf(" --- Поиск по Числу рождения --- \n");
					printf("Введите Число\n -->");

					scanf("%s", &Search);
					for (i = 0; i < number_of_structures; i++)
					{
						seek(i, struc, Search, People[i].date_number);
					}
					if (struc == 0)
					{
						printf("Структура не найденна\n");
					}
					struc = 0;
					system("pause");
					system("cls");
					break;
				case 7:printf(" --- Поиск по Месяцу рождения --- \n");
					printf("Введите Месяц\n -->");

					scanf("%s", &Search);
					for (i = 0; i < number_of_structures; i++)
					{
						seek(i, struc, Search, People[i].date_month);
					}
					if (struc == 0)
					{
						printf("Структура не найденна\n");
					}
					struc = 0;
					system("pause");
					system("cls");
					break;
				case 8:printf(" --- Поиск по Году рождения --- \n");
					printf("Введите Год\n -->");

					scanf("%s", &Search);
					for (i = 0; i < number_of_structures; i++)
					{
						seek(i, struc, Search, People[i].date_year);
					}
					if (struc == 0)
					{
						printf("Структура не найденна\n");
					}
					struc = 0;
					system("pause");
					system("cls");
					break;
				case 9:printf(" --- Поиск по Номеру телефона --- \n");
					printf("Введите Номер\n -->");

					scanf("%s", &Search);
					for (i = 0; i < number_of_structures; i++)
					{
						seek(i, struc, Search, People[i].phone_number);
					}
					if (struc == 0)
					{
						printf("Структура не найденна\n");
					}
					struc = 0;
					system("pause");
					system("cls");
					break;
				case 10:printf(" --- Поиск по Индексу --- \n");
					printf("Введите Индекс\n -->");

					scanf("%s", &Search);
					for (i = 0; i < number_of_structures; i++)
					{
						seek(i, struc, Search, People[i].address_index);
					}
					if (struc == 0)
					{
						printf("Структура не найденна\n");
					}
					struc = 0;
					system("pause");
					system("cls");
					break;
				case 11:printf(" --- Поиск по Стране --- \n");
					printf("Введите Страну\n -->");

					scanf("%s", &Search);
					for (i = 0; i < number_of_structures; i++)
					{
						seek(i, struc, Search, People[i].address_country);
					}
					if (struc == 0)
					{
						printf("Структура не найденна\n");
					}
					struc = 0;
					system("pause");
					system("cls");
					break;
				case 12:printf(" --- Поиск по Региону --- \n");
					printf("Введите Регион\n -->");

					scanf("%s", &Search);
					for (i = 0; i < number_of_structures; i++)
					{
						seek(i, struc, Search, People[i].address_region);
					}
					if (struc == 0)
					{
						printf("Структура не найденна\n");
					}
					struc = 0;
					system("pause");
					system("cls");
					break;
				case 13:printf(" --- Поиск по Городу --- \n");
					printf("Введите Город\n -->");

					scanf("%s", &Search);
					for (i = 0; i < number_of_structures; i++)
					{
						seek(i, struc, Search, People[i].address_city);
					}
					if (struc == 0)
					{
						printf("Структура не найденна\n");
					}
					struc = 0;
					system("pause");
					system("cls");
					break;
				case 14:printf(" --- Поиск по Улице --- \n");
					printf("Введите Улицу\n -->");

					scanf("%s", &Search);
					for (i = 0; i < number_of_structures; i++)
					{
						seek(i, struc, Search, People[i].address_street);
					}
					if (struc == 0)
					{
						printf("Структура не найденна\n");
					}
					struc = 0;
					system("pause");
					system("cls");
					break;
				case 15:printf(" --- Поиск по Номеру дома --- \n");
					printf("Введите Дом\n -->");

					scanf("%s", &Search);
					for (i = 0; i < number_of_structures; i++)
					{
						seek(i, struc, Search, People[i].address_house);
					}
					if (struc == 0)
					{
						printf("Структура не найденна\n");
					}
					struc = 0;
					system("pause");
					system("cls");
					break;
				case 16:printf(" --- Поиск по Номеру квартиры --- \n");
					printf("Введите Квартиру\n -->");

					scanf("%s", &Search);
					for (i = 0; i < number_of_structures; i++)
					{
						seek(i, struc, Search, People[i].address_apartment);
					}
					if (struc == 0)
					{
						printf("Структура не найденна\n");
					}
					struc = 0;
					system("pause");
					system("cls");
					break;
				}
			}
			else
			{
				printf("--- Заполненных структур нет ---\n");
				system("pause");
			}
			system("cls");
			break;
		case 3:
			printf("---Вывод на экран содержимого структур---\n");
			if (number_of_structures == 0)	//проверка на наличие заполненных структур
			{
				printf("Заполненных структур нет\n");
			}
			else
			{
				print(number_of_structures);
			}
			system("pause");
			system("cls");
			break;
		case 4:
			if (number_of_structures != 0)
			{
				printf(" ---Упорядочение структур по заданному полю--- \n");
				printf("(введите номер)\n");
				printf("--- Сортировка по заданному полю --- \n");
				printf("1. Сортировка по Фамилии.\n");
				printf("2. Сортировка по Имени.\n");
				printf("3. Сортировка по Полу.\n");
				printf("4. Сортировка по Росту.\n");
				printf("5. Сортировка по Весу.\n");
				printf("6. Сортировка по Числу рождения.\n");
				printf("7. Сортировка по Месяцу рождения.\n");
				printf("8. Сортировка по Году рождения.\n");
				printf("9. Сортировка по Номер телефона.\n");
				printf("10. Сортировка по Индексу.\n");
				printf("11. Сортировка по Стране.\n");
				printf("12. Сортировка по Региону.\n");
				printf("13. Сортировка по Городу.\n");
				printf("14. Сортировка по Улице.\n");
				printf("15. Сортировка по Номеру дома.\n");
				printf("16. Сортировка по Номеру квартиры.\n");
				printf("--> ");

				scanf_s("%d", &sorting);
				system("cls");

				switch (sorting) 
				{
				case 1:printf(" --- Сортировка по Фамилии --- \n");
					for ( i = 0; i < number_of_structures; i++)
					{
						for (int j = 0; j < number_of_structures - i - 1; j++)
						{
							code = strcmp(People[j].surname, People[j+1].surname); 
							sort(code, j);
						}
					}
					print(number_of_structures);
					new_input(number_of_structures);
					system("pause");
					system("cls");
					break;
				case 2:printf(" --- Сортировка по Имени --- \n");
					for (i = 0; i < number_of_structures; i++)
					{
						for (int j = 0; j < number_of_structures - i - 1; j++)
						{	
							code = strcmp(People[j].name, People[j + 1].name);
							sort(code, j);
						}
					}
					print(number_of_structures);
					new_input(number_of_structures);
					system("pause");
					system("cls");
					break;
				case 3:printf(" --- Сортировка по Полу --- \n");
					for (i = 0; i < number_of_structures; i++)
					{
						for (int j = 0; j < number_of_structures - i - 1; j++)
						{
							code = strcmp(People[j].sex, People[j + 1].sex); sort(code, j);
						}
					}
					print(number_of_structures);
					new_input(number_of_structures);
					system("pause");
					system("cls");
					break;
				case 4:printf(" --- Сортировка по Росту --- \n");
					for (i = 0; i < number_of_structures; i++)
					{
						for (int j = 0; j < number_of_structures - i - 1; j++)
						{
							code = strcmp(People[j].growth, People[j + 1].growth); sort(code, j);
						}
					}
					print(number_of_structures);
					new_input(number_of_structures);
					system("pause");
					system("cls");
					break;
				case 5:printf(" --- Сортировка по Весу --- \n");
					for (i = 0; i < number_of_structures; i++)
					{
						for (int j = 0; j < number_of_structures - i - 1; j++)
						{
							code = strcmp(People[j].weight, People[j + 1].weight); sort(code, j);
						}
					}
					print(number_of_structures);
					new_input(number_of_structures);
					system("pause");
					system("cls");
					break;
				case 6:printf(" --- Сортировка по Числу рождения --- \n");
					for (i = 0; i < number_of_structures; i++)
					{
						for (int j = 0; j < number_of_structures - i - 1; j++)
						{
							code = strcmp(People[j].date_number, People[j + 1].date_number); sort(code, j);
						}
					}
					print(number_of_structures);
					new_input(number_of_structures);
					system("pause");
					system("cls");
					break;
				case 7:printf(" --- Сортировка по Месяцу рождения --- \n");
					for (i = 0; i < number_of_structures; i++)
					{
						for (int j = 0; j < number_of_structures - i - 1; j++)
						{
							code = strcmp(People[j].date_month, People[j + 1].date_month); sort(code, j);
						}
					}
					print(number_of_structures);
					new_input(number_of_structures);
					system("pause");
					system("cls");
					break;
				case 8:printf(" --- Сортировка по Году рождения --- \n");
					for (i = 0; i < number_of_structures; i++)
					{
						for (int j = 0; j < number_of_structures - i - 1; j++)
						{
							code = strcmp(People[j].date_year, People[j + 1].date_year); sort(code, j);
						}
					}
					print(number_of_structures);
					new_input(number_of_structures);
					system("pause");
					system("cls");
					break;
				case 9:printf(" --- Сортировка по Номеру телефона --- \n");
					for (i = 0; i < number_of_structures; i++)
					{
						for (int j = 0; j < number_of_structures - i - 1; j++)
						{
							code = strcmp(People[j].phone_number, People[j + 1].phone_number); sort(code, j);
						}
					}
					print(number_of_structures);
					new_input(number_of_structures);
					system("pause");
					system("cls");
					break;
				case 10:printf(" --- Сортировка по Индексу --- \n");
					for (i = 0; i < number_of_structures; i++)
					{
						for (int j = 0; j < number_of_structures - i - 1; j++)
						{
							code = strcmp(People[j].address_index, People[j + 1].address_index); sort(code, j);
						}
					}
					print(number_of_structures);
					new_input(number_of_structures);
					system("pause");
					system("cls");
					break;
				case 11:printf(" --- Сортировка по Странам --- \n");
					for (i = 0; i < number_of_structures; i++)
					{
						for (int j = 0; j < number_of_structures - i - 1; j++)
						{
							code = strcmp(People[j].address_country, People[j + 1].address_country); sort(code, j);
						}
					}
					print(number_of_structures);
					new_input(number_of_structures);
					system("pause");
					system("cls");
					break;
				case 12:printf(" --- Сортировка по Регионам --- \n");
					for (i = 0; i < number_of_structures; i++)
					{
						for (int j = 0; j < number_of_structures - i - 1; j++)
						{
							code = strcmp(People[j].address_region, People[j + 1].address_region); sort(code, j);
						}
					}
					print(number_of_structures);
					new_input(number_of_structures);
					system("pause");
					system("cls");
					break;
				case 13:printf(" --- Сортировка по Городам --- \n");
					for (i = 0; i < number_of_structures; i++)
					{
						for (int j = 0; j < number_of_structures - i - 1; j++)
						{
							code = strcmp(People[j].address_city, People[j + 1].address_city); sort(code, j);
						}
					}
					print(number_of_structures);
					new_input(number_of_structures);
					system("pause");
					system("cls");
					break;
				case 14:printf(" --- Сортировка по Улицам --- \n");
					for (i = 0; i < number_of_structures; i++)
					{
						for (int j = 0; j < number_of_structures - i - 1; j++)
						{
							code = strcmp(People[j].address_street, People[j + 1].address_street); sort(code, j);
						}
					}
					print(number_of_structures);
					new_input(number_of_structures);
					system("pause");
					system("cls");
					break;
				case 15:printf(" --- Сортировка по Номерам домов --- \n");
					for (i = 0; i < number_of_structures; i++)
					{
						for (int j = 0; j < number_of_structures - i - 1; j++)
						{
							code = strcmp(People[j].address_house, People[j + 1].address_house); sort(code, j);
						}
					}
					print(number_of_structures);
					new_input(number_of_structures);
					system("pause");
					system("cls");
					break;
				case 16:printf(" --- Сортировка по Номерам квартир --- \n");
					for (i = 0; i < number_of_structures; i++)
					{
						for (int j = 0; j < number_of_structures - i - 1; j++)
						{
							code = strcmp(People[j].address_apartment, People[j + 1].address_apartment); sort(code, j);
						}
					}
					print(number_of_structures);
					new_input(number_of_structures);
					system("pause");
					system("cls");
					break;
				}
			}
			else
			{
				printf("--- Заполненных структур нет ---\n");
				system("pause");
			}
			system("cls");
			break;
		case 5:
			exit(0);	//выход и программы
			break;
		default: printf("Такого выбора нет.");
		}
	} while (true);
	system("pause");
}

int initialization() 
{
	FILE *File = fopen("Struct.txt", "r");
	FILE *File1 = fopen("Struct.txt", "r");
	int i = 0;
	if (File != NULL)
	{
		while (fscanf(File, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s", &People[i].surname, &People[i].name, &People[i].sex, &People[i].growth, &People[i].weight, &People[i].date_number, &People[i].date_month, &People[i].date_year, &People[i].phone_number, &People[i].address_index, &People[i].address_country, &People[i].address_region, &People[i].address_city, &People[i].address_street, &People[i].address_house, &People[i].address_apartment)!=EOF)
		{
			fscanf(File1, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s", &People[i].surname, &People[i].name, &People[i].sex, &People[i].growth, &People[i].weight, &People[i].date_number, &People[i].date_month, &People[i].date_year, &People[i].phone_number, &People[i].address_index, &People[i].address_country, &People[i].address_region, &People[i].address_city, &People[i].address_street, &People[i].address_house, &People[i].address_apartment);
			i++;
		}
		
	}
	else
	{
		printf("---Файла нет или не открылся---");
		system("pause");
		exit(0);
	}
	fclose(File);
	fclose(File1);
	return i;
}

void input(int i)
{
	printf("---Введите свои данный---\n");
	printf("Введите свою фамилию: ");
	scanf("%s", &People[i].surname);
	printf("Введите своё имя: ");
	scanf("%s", &People[i].name);
	printf("Укажите пол: ");
	scanf("%s", &People[i].sex);
	printf("Введите сой рост: ");
	scanf("%s", &People[i].growth);
	printf("Введите свой вес: ");
	scanf("%s", &People[i].weight);
	printf("Введите число рождения: ");
	scanf("%s", &People[i].date_number);
	printf("Введите месяц рождения(цифрами): ");
	scanf("%s", &People[i].date_month);
	printf("Введите год рождения: ");
	scanf("%s", &People[i].date_year);
	printf("Введите свой номер телефона: ");
	scanf("%s", &People[i].phone_number);
	printf("Введите ваш домашний индекс: ");
	scanf("%s", &People[i].address_index);
	printf("Введите вашу страну: ");
	scanf("%s", &People[i].address_country);
	printf("Введите свою область или регион: ");
	scanf("%s", &People[i].address_region);
	printf("Введите свой город: ");
	scanf("%s", &People[i].address_city);
	printf("Введите свою улицу: ");
	scanf("%s", &People[i].address_street);
	printf("Введите номер дома: ");
	scanf("%s", &People[i].address_house);
	printf("Введите номер квартиры(если дом не квартирный то поставь 0): ");
	scanf("%s", &People[i].address_apartment);
	printf("Введите цену квартиры: ");
	scanf("%d", &People[i].price);
	printf("Конец ввода.\n\n");

	FILE *File = fopen("Struct.txt", "a");
	fprintf(File, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", &People[i].surname, &People[i].name, &People[i].sex, &People[i].growth, &People[i].weight, &People[i].date_number, &People[i].date_month, &People[i].date_year, &People[i].phone_number, &People[i].address_index, &People[i].address_country, &People[i].address_region, &People[i].address_city, &People[i].address_street, &People[i].address_house, &People[i].address_apartment);
	fclose(File);
}

void output(int i) 
{
	printf("Фамилия: %s\t", &People[i].surname);
	printf("Имя: %s\t", &People[i].name);
	printf("Пол: %s\t", &People[i].sex);
	printf("Рост: %s\t", &People[i].growth);
	printf("Все: %s\t", &People[i].weight);
	printf("Дата рождения: %s.%s.%s\t", &People[i].date_number, &People[i].date_month, &People[i].date_year);
	printf("Номер телефона: %s\t", &People[i].phone_number);
	printf("Индекс: %s\t", &People[i].address_index);
	printf("Страна: %s\t", &People[i].address_country);
	printf("Регион: %s\t", &People[i].address_region);
	printf("Город: %s\t", &People[i].address_city);
	printf("Адрес:  ул.%s  дом №%s кв.№%s\n\n", &People[i].address_street, &People[i].address_house, &People[i].address_apartment);
}

void seek(int i, int struc, char *Search, char * array)
{
	if (strcmp(Search, array) == 0)
	{
		struc++;
		printf("Струра найденна\n Номер структуры -> %d\n", i + 1);
		output(i);
	}
}

void sort(int k, int j) 
{
	if (k > 0)
	{
		Struct Buff = People[j];
		People[j] = People[j + 1];
		People[j + 1] = Buff;
	}
}

void print(int number)
{
	for (int i = 0; i < number; i++)
	{
		output(i);
	}
}

void new_input(int number) 
{

	FILE *File = fopen("Sort.txt", "w");
	for (int i = 0; i < number; i++)
	{
	fprintf(File, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", &People[i].surname, &People[i].name, &People[i].sex, &People[i].growth, &People[i].weight, &People[i].date_number, &People[i].date_month, &People[i].date_year, &People[i].phone_number, &People[i].address_index, &People[i].address_country, &People[i].address_region, &People[i].address_city, &People[i].address_street, &People[i].address_house, &People[i].address_apartment);
	}
	fclose(File);
}