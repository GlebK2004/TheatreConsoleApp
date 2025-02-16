#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<locale.h>
#include <windows.h>
#include <conio.h>   
#include "header.h"

FILE* f_registration;

struct profile
{
	char login[10];
	int password;
	int role;
	int hash;
} profile[50];

int count_profiles;

int log_in_to_the_system()
{
	int role = -1;
	char login[10];
	int password;
	if (!(f_registration = fopen("f.txt", "a+b")))
	{
		printf("������ �������� �����(0.0)\n");
	}
	else
	{
		if (getc(f_registration) == EOF)
		{
			count_profiles = 0;
			printf("��� ������ ���������� ������� ������� ������ ��������������\n");
			printf("����� <(0.0)- ");
			rewind(stdin);
			gets_s(profile[count_profiles].login);
			printf("������ <(0.0)- ");
			profile[count_profiles].password = check_int();
			profile[count_profiles].role = 1;
			count_profiles++;
			//printf("____________________________������ �������� � ����(^.^)_________________________________________________________________");
			printf("\n\n");
		}
		else
		{
			int count, indicator = 0;
			while (indicator != 1)
			{
				count = 0;
				printf("�������� ����� <(0.0)- ");
				rewind(stdin);
				gets_s(login);
				printf("�������� ������ <(0.0)- ");   
				password = check_int();
				while (count < count_profiles)
				{
					if ((password == profile[count].password) && (strcmp(profile[count].login, login) == 0))
					{
						indicator = 1;
						if (profile[count].role == 1) role = 1; // 1 - �����, 0 - ������������
						else role = 0;
						break;
					}
					count++;
				}
				if (indicator == 0) printf("__________________�� ����� �������� ����� ��� ������. ���������� ���.(0.0)___________________________________________\n");
			}
		}
	}
	return role;
}



void profile_mode()
{
	int choise = 0;
	while (choise != 5)
	{
		printf("<(0.0)- 1.���������� ��� ������� ������.\n");
		printf("<(0.0)- 2.�������� ����� ������� ������.\n");
		printf("<(0.0)- 3.������� �������.\n");
		printf("<(0.0)- 4.������������� ������ ������� ������.\n");
		printf("<(0.0)- 5.��������� �����.\n");
		printf("������� ���� �����: ");
		choise = check_int();
		switch (choise)
		{
		case 1:
		{
			print_profiles();
			break;
		}
		case 2:
		{
			enter_profile();
			break;
		}
		case 3:
		{
			delete_profile();
			break;
		}
		case 4:
		{
			edit_profiles();
			break;
		}
		case 5:
		{
			choise = 5;
			break;
		}
		}
	}
}

void open_profiles()
{
	if (!(f_registration = fopen("f.txt", "a+b")))
	{
		printf("������ �������� �����(0.0)\n");
	}
	else
	{
		do
		{
			fscanf(f_registration, "%s %d %d", &profile[count_profiles].login, &profile[count_profiles].hash, &profile[count_profiles].role);
			profile[count_profiles].password = DeHash();
			count_profiles++;
		} while (!feof(f_registration));
		fclose(f_registration);
		count_profiles--;
	}
}

void write_profiles()
{
	if (!(f_registration = fopen("f.txt", "w+b")))
	{
		printf("������ �������� �����(0.0)\n");
	}
	else
	{
		int counter = 0;
		while (counter < count_profiles)
		{
			profile[counter].hash = Hash(counter);
			fputs(profile[counter].login, f_registration);
			fprintf(f_registration, " %d %d ", profile[counter].hash, profile[counter].role);
			counter++;
		}
		fclose(f_registration);
	}
}

void print_profiles()
{
	int counter = 0;
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	printf("�����\t\t ������\t\t   ����\n");
	printf("----------------------------------------------\n");
	while (counter < count_profiles)
	{
		printf(" %s \t\t%d\t\t ", profile[counter].login, profile[counter].password);
		if (profile[counter].role == 1) printf("�������������\n");
		else printf(" ������������\n");
		printf("----------------------------------------------\n");
		counter++;
	}
	printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
}

void enter_profile()
{
	printf("�������� ����� <(0.0)- ");
	rewind(stdin);
	unique_login();
	printf("�������� ������ <(0.0)- ");
	scanf_s("%d", &profile[count_profiles].password);
	printf("������� ����(1 - �������������, 0 - ������������)<(0.0)-");
	int indicator = 0, temporary;
	while (indicator == 0)
	{
		scanf_s("%d", &temporary);
		if (temporary != 0 && temporary != 1) printf("�� ����� �������� �������� (1 - �������������, 0 - ������������)\n");
		else
		{
			profile[count_profiles].role = temporary;
			indicator = 1;
		}
	}
	profile[count_profiles].hash = Hash(count_profiles);
	count_profiles++;
}

void delete_profile()
{
	int counter2 = 0, counter1 = 0, indicator = 0;
	char temporary[20];
	printf("������� ����� ������� ������, ������� ���� �������: ");
	rewind(stdin);
	gets_s(temporary);
	while (counter1 <= count_profiles)
	{
		if (strcmp(profile[counter1].login, temporary) == 0)
		{
			if (profile[counter1].role == 1) printf("�� �� ������ ������� ������� �������������� (0.0)\n");
			else
			{
				counter2 = counter1;
				while (counter2 < count_profiles - 1)
				{
					profile[counter2] = profile[counter2 + 1];
					counter2++;
				}
				count_profiles--;
			}
			indicator = 1;
		}
		counter1++;
	}
	if (indicator == 0) printf("������� � ����� ������� �� ���������� (0.0)\n");
}

void edit_profiles()
{
	int temporary_password, counter2 = 0, counter = 0, indicator = 0, number = -1;
	char temporary_login[20];
	printf("������� ����� ������� ������, ������� ���� ���������������: ");
	rewind(stdin);
	gets_s(temporary_login);
	while (counter <= count_profiles)
	{
		if (strcmp(profile[counter].login, temporary_login) == 0) number = counter;
		counter++;
	}
	if (number != -1)
	{
		int choise = 0;
		while (choise != 4)
		{
			printf("<(0.0)- 1.�������� �����.\n");
			printf("<(0.0)- 2.�������� ������.\n");
			printf("<(0.0)- 3.�������� ����.\n");
			printf("<(0.0)- 4.��������� �������� ���������.\n");
			printf("<(0.0)-");
			scanf_s("%d", &choise);
			switch (choise)
			{
			case 1:
			{
				printf("������� ����� �����: ");
				rewind(stdin);
				gets_s(temporary_login);
				strcpy(profile[number].login, temporary_login);
				break;
			}
			case 2:
			{
				printf("������� ����� ������: ");
				scanf_s("%d", &temporary_password);
				profile[number].password = temporary_password;
				break;
			}
			case 3:
			{

				break;
			}
			case 4:
			{
				break;
			}
			default: printf("�������� ����� (0.0)\n");
			}
		}
	}
}

void unique_login()
{
	char login[20];
	int indicator = 0;
	do
	{
		indicator = 0;
		rewind(stdin);
		gets_s(login);
		for (int counter = 0; counter < count_profiles; counter++)
		{
			if (strcmp(profile[counter].login, login) == 0) indicator = 1;
		}
		if (indicator == 1) printf("���, ����� ����� ��� ����� (0.0). ���������� ������: ");
	} while (indicator != 0);
	strcpy(profile[count_profiles].login, login);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////// ����������� ///////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Hash(int counter)
{
	int hash = 0, x, temp = profile[counter].password;
	while (temp != 0)
	{
		x = temp % 10;
		temp = temp / 10;
		hash = hash * 10 + x;
	}
	return hash;
}

int DeHash()
{
	int password = 0, x, temp = profile[count_profiles].hash;
	while (temp != 0)
	{
		x = temp % 10;
		temp = temp / 10;
		password = password * 10 + x;
	}
	return password;
}


//
//void HashF()
//{
//	for (int counter = 0;counter < count_profiles;counter++)
//	{
//		profile[counter].hash = Hash(counter);
//	}
//}