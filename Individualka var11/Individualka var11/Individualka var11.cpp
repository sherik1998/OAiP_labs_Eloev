#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <fstream>
#include <conio.h>
#include <locale>
#include <stdio.h>

char* p_iniFile = "param.ini";
char* p_clientsFile = "clients.txt";
char* p_serviceFile = "service.txt";
char* p_billFile = "bill.txt";
char* p_oFile = "report.txt";


int cSize = 0;
int sSize = 0;
int bSize = 0;
int kSize = 0;

struct clients
{
	char* p_FIO = (char*)(malloc(sizeof(char) * 254));
	char* p_Number = (char*)(malloc(sizeof(char) * 254));
	char* p_fDate = (char*)(malloc(sizeof(char) * 254));
	char* p_lDate = (char*)(malloc(sizeof(char) * 254));
	float debt;
	float credit;
};

struct service
{
	char* p_servName = (char*)(malloc(sizeof(char) * 254));
	int code;
	float cost;
	char* p_Mera = (char*)(malloc(sizeof(char) * 254));
};

struct bill
{
	char* p_Number = (char*)(malloc(sizeof(char) * 254));;
	int code;
	char* p_During = (char*)(malloc(sizeof(char) * 254));;
	char* interval = (char*)(malloc(sizeof(char) * 254));;
};

int getSize(char* loc)
{
	int _size = 0;
	FILE* tmp = fopen(loc, "r");
	char* buff = (char*)(malloc(sizeof(char) * 1024));
	while (!feof(tmp))
	{
		fgets(buff, 1024, tmp);
		if (strcmp(buff, "\n"))
		{
			_size++;
		}
	}
	free(buff);
	return _size;
}



clients* ClientBase()
{
	cSize = getSize(p_clientsFile);
	clients* CBase = (clients*)(malloc(sizeof(clients)*cSize));
	FILE* clntFile = fopen(p_clientsFile, "r");
	if (!feof(clntFile))
	{
		int inc = 0;
		while (!feof(clntFile))
		{

			char* buff = (char*)(malloc(sizeof(char) * 1024));
			fgets(buff, 1024, clntFile);
			if (strcmp(buff, "\n"))
			{
				char* p_tokken = NULL;
				CBase[inc].p_FIO = strtok_s(buff, ",", &p_tokken);
				CBase[inc].p_Number = strtok_s(NULL, ", ", &p_tokken);
				CBase[inc].p_fDate = strtok_s(NULL, ", ", &p_tokken);
				CBase[inc].p_lDate = strtok_s(NULL, ",", &p_tokken);
				CBase[inc].debt = atof(strtok_s(NULL, ",", &p_tokken));
				CBase[inc].credit = atof(strtok_s(NULL, ",", &p_tokken));
				inc++;
			}
		}
		return CBase;
	}
	else
		return NULL;
}

service* ServiceBase()
{
	sSize = getSize(p_serviceFile);
	service* SBase = (service*)(malloc(sizeof(service)*sSize));
	FILE* SFile = fopen(p_serviceFile, "r");
	if (!feof(SFile))
	{
		int inc = 0;
		while (!feof(SFile))
		{
			char* buff = (char*)(malloc(sizeof(char) * 1024));
			fgets(buff, 1024, SFile);
			if (strcmp(buff, "\n"))
			{
				char* p_tokken = NULL;
				SBase[inc].p_servName = strtok_s(buff, ",", &p_tokken);
				SBase[inc].code = atoi(strtok_s(NULL, ",", &p_tokken));
				SBase[inc].cost = atof(strtok_s(NULL, ",", &p_tokken));
				SBase[inc].p_Mera = strtok_s(NULL, ",", &p_tokken);
				inc++;
			}
		}
		return SBase;
	}
	else
		return NULL;
}

bill* billBase()
{
	bSize = getSize(p_billFile);
	bill* BBase = (bill*)(malloc(sizeof(service)*bSize));
	FILE* BFile = fopen(p_billFile, "r");
	if (!feof(BFile))
	{
		int inc = 0;
		while (!feof(BFile))
		{
			char* buff = (char*)(malloc(sizeof(char) * 1024));
			fgets(buff, 1024, BFile);
			char* p_tokken = NULL;
			BBase[inc].p_Number = strtok_s(buff, ", ", &p_tokken);
			BBase[inc].code = atoi(strtok_s(NULL, ",", &p_tokken));
			BBase[inc].p_During = strtok_s(NULL, ",", &p_tokken);
			BBase[inc].interval = strtok_s(NULL, ",", &p_tokken);
			inc++;
		}
		return BBase;
	}
	else
		return NULL;
}

char** confIni()
{
	kSize = getSize(p_iniFile);
	FILE* conf = fopen(p_iniFile, "r");
	char** key = (char**)(malloc(sizeof(char*)*kSize));
	if (!feof(conf))
	{
		int inc = 0;
		while (!feof(conf))
		{
			char* p_nullPtr = NULL;
			char* buff = (char*)(malloc(sizeof(char) * 256));
			fgets(buff, 256, conf);
			key[inc] = strtok_s(buff, "\n", &p_nullPtr);
			inc++;
		}
		return key;
	}
	else
		return NULL;
}

bool is_SecQuartal(char* date)
{
	if (date[9] == '7'&&date[8] == '1'&&date[7] == '0'&&date[6] == '2' && date[4]>'2' && date[4]<'6'&&date[3] == '0')
		return true;
	else return false;
}

void searchFunc(clients* cBase, service* sBase, bill* bBase, char** key)
{
	FILE* oFile = fopen(p_oFile, "w+");
	fputs("Фамилия: ---   Номер телефона ---- Дата заключения договора ----  Услуги -----\n", oFile);
	for (int a = 0; a < kSize; a++)
	{
		for (int b = 0; b < cSize; b++)
		{
			if (!strcmp(cBase[b].p_FIO, key[a]) && is_SecQuartal(cBase[b].p_fDate))
			{
				fputs(key[a], oFile);
				fputs(" ", oFile);
				fputs(cBase[b].p_Number, oFile);
				fputs(" ", oFile);
				fputs(cBase[b].p_fDate, oFile);
				fputs(" :", oFile);
				for (int c = 0; c < bSize; c++)
				{
					if (!strcmp(cBase[b].p_Number, bBase[c].p_Number))
					{
						for (int d = 0; d < sSize; d++)
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
	}
}

int main()
{
	setlocale(0, "rus");
	clients* CBase = ClientBase();
	service* SBase = ServiceBase();
	bill* BBase = billBase();
	char** keys = confIni();
	searchFunc(CBase, SBase, BBase, keys);
	printf("Infomation Configurate! \n");
	system("pause");
	return 0;
}