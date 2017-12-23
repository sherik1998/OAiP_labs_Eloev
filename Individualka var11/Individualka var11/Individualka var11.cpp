#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <fstream>
#include <conio.h>
#include <locale>
#include <stdio.h>

#define LENGTH 512

char* iniFile = "param.ini";
char* clientsFile = "clients.txt";
char* serviceFile = "service.txt";
char* billFile = "bill.txt";
char* reportFile = "report.txt";


int clientsSize = 0;
int serviceSize = 0;
int billSize = 0;
int keysSize = 0;

struct clients
{
	char* FIO = (char*)(malloc(sizeof(char) * LENGTH));
	char* phonenumber = (char*)(malloc(sizeof(char) * LENGTH));
	char* contractdate = (char*)(malloc(sizeof(char) * LENGTH));
	char* endcontractdate = (char*)(malloc(sizeof(char) * LENGTH));
	float debt;
	float credit;
};

struct service
{
	char* p_servName = (char*)(malloc(sizeof(char) * LENGTH));
	int code;
	float cost;
	char* p_Mera = (char*)(malloc(sizeof(char) * LENGTH));
};

struct bill
{
	char* p_Number = (char*)(malloc(sizeof(char) * LENGTH));;
	int code;
	char* p_During = (char*)(malloc(sizeof(char) * LENGTH));;
	char* interval = (char*)(malloc(sizeof(char) * LENGTH));;
};

int getSize(char* loc);
clients* clientBase();
service* serviceBase();
bill* billBase();
char** confIni();
bool is_SecQuartal(char* date);
void searchFunc(clients* cBase, service* sBase, bill* bBase, char** key);
void entryFile(FILE* oFile, int a, int b, clients* cBase, service* sBase, bill* bBase, char** key);

int main()
{
	setlocale(0, "rus");
	clients* CBase = clientBase();
	service* SBase = serviceBase();
	bill* BBase = billBase();
	char** keys = confIni();
	searchFunc(CBase, SBase, BBase, keys);
	printf("Конфигурация информации!\n");
	system("pause");
	return 0;
}

int getSize(char* loc)
{
	int _size = 0;
	FILE* tmp = fopen(loc, "r");
	char* buff = (char*)(malloc(sizeof(char) * LENGTH));
	while (!feof(tmp))
	{
		fgets(buff, LENGTH, tmp);
		if (strcmp(buff, "\n"))
		{
			_size++;
		}
	}
	free(buff);
	return _size;
}

clients* clientBase()
{
	clientsSize = getSize(clientsFile);
	clients* CBase = (clients*)(malloc(sizeof(clients)*clientsSize));
	FILE* clntFile = fopen(clientsFile, "r");
	int inc = 0;
	while (!feof(clntFile))
	{
		char* buff = (char*)(malloc(sizeof(char) * LENGTH));
		fgets(buff, LENGTH, clntFile);
		if (strcmp(buff, "\n"))
		{
			char* tokken = NULL;
			CBase[inc].FIO = strtok_s(buff, ",", &tokken);
			CBase[inc].phonenumber = strtok_s(NULL, ", ", &tokken);
			CBase[inc].contractdate = strtok_s(NULL, ", ", &tokken);
			CBase[inc].endcontractdate = strtok_s(NULL, ",", &tokken);
			CBase[inc].debt = atof(strtok_s(NULL, ",", &tokken));
			CBase[inc].credit = atof(strtok_s(NULL, ",", &tokken));
			inc++;
		}
	}
	return CBase;
}

service* serviceBase()
{
	serviceSize = getSize(serviceFile);
	service* SBase = (service*)(malloc(sizeof(service)*serviceSize));
	FILE* SFile = fopen(serviceFile, "r");
	int inc = 0;
	while (!feof(SFile))
	{
		char* buff = (char*)(malloc(sizeof(char) * LENGTH));
		fgets(buff, LENGTH, SFile);
		if (strcmp(buff, "\n"))
		{
			char* tokken = NULL;
			SBase[inc].p_servName = strtok_s(buff, ",", &tokken);
			SBase[inc].code = atoi(strtok_s(NULL, ",", &tokken));
			SBase[inc].cost = atof(strtok_s(NULL, ",", &tokken));
			SBase[inc].p_Mera = strtok_s(NULL, ",", &tokken);
			inc++;
		}
	}
	return SBase;
}

bill* billBase()
{
	billSize = getSize(billFile);
	bill* BBase = (bill*)(malloc(sizeof(service)*billSize));
	FILE* BFile = fopen(billFile, "r");
	int inc = 0;
	while (!feof(BFile))
	{
		char* buff = (char*)(malloc(sizeof(char) * LENGTH));
		fgets(buff, LENGTH, BFile);
		char* tokken = NULL;
		BBase[inc].p_Number = strtok_s(buff, ", ", &tokken);
		BBase[inc].code = atoi(strtok_s(NULL, ",", &tokken));
		BBase[inc].p_During = strtok_s(NULL, ",", &tokken);
		BBase[inc].interval = strtok_s(NULL, ",", &tokken);
		inc++;
	}
	return BBase;
}

char** confIni()
{
	keysSize = getSize(iniFile);
	FILE* conf = fopen(iniFile, "r");
	char** key = (char**)(malloc(sizeof(char*)*keysSize));
	int inc = 0;
	while (!feof(conf))
	{
		char* tokken = NULL;
		char* buff = (char*)(malloc(sizeof(char) * LENGTH));
		fgets(buff, LENGTH, conf);
		key[inc] = strtok_s(buff, "\n", &tokken);
		inc++;
	}
	return key;
}

bool is_SecQuartal(char* date)
{
	if (date[9] == '7'&&date[8] == '1'&&date[7] == '0'&&date[6] == '2' && date[4]>'2' && date[4]<'6'&&date[3] == '0')
		return true;
	else return false;
}

void searchFunc(clients* cBase, service* sBase, bill* bBase, char** key)
{
	FILE* oFile = fopen(reportFile, "w+");
	fputs("Фамилия: ---   Номер телефона ---- Дата заключения договора ----  Услуги -----\n", oFile);
	for (int a = 0; a < keysSize; a++)
	{
		for (int b = 0; b < clientsSize; b++)
		{
			entryFile(oFile, a, b, cBase, sBase, bBase, key);
		}
	}
}

void entryFile(FILE* oFile, int a, int b, clients* cBase, service* sBase, bill* bBase, char** key)
{
	if (!strcmp(cBase[b].FIO, key[a]) && is_SecQuartal(cBase[b].contractdate))
	{
		fputs(key[a], oFile);
		fputs(" ", oFile);
		fputs(cBase[b].phonenumber, oFile);
		fputs(" ", oFile);
		fputs(cBase[b].contractdate, oFile);
		fputs(" :", oFile);
		for (int c = 0; c < billSize; c++)
		{
			if (!strcmp(cBase[b].phonenumber, bBase[c].p_Number))
			{
				for (int d = 0; d < serviceSize; d++)
				{
					if (bBase[c].code == sBase[d].code)
					{
						fputs(sBase[d].p_servName, oFile);
						fputs("; ", oFile);
					}
				}
			}
		}
		fputs("\n", oFile);
	}
}