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
		printf("Ошибка открытия файла(0.0)\n");
	}
	else
	{
		if (getc(f_registration) == EOF)
		{
			count_profiles = 0;
			printf("Для начала необходимо создать учётную запись администратора\n");
			printf("логин <(0.0)- ");
			rewind(stdin);
			gets_s(profile[count_profiles].login);
			printf("пароль <(0.0)- ");
			profile[count_profiles].password = check_int();
			profile[count_profiles].role = 1;
			count_profiles++;
			//printf("____________________________Данные записаны в файл(^.^)_________________________________________________________________");
			printf("\n\n");
		}
		else
		{
			int count, indicator = 0;
			while (indicator != 1)
			{
				count = 0;
				printf("Введител логин <(0.0)- ");
				rewind(stdin);
				gets_s(login);
				printf("Введител пароль <(0.0)- ");   
				password = check_int();
				while (count < count_profiles)
				{
					if ((password == profile[count].password) && (strcmp(profile[count].login, login) == 0))
					{
						indicator = 1;
						if (profile[count].role == 1) role = 1; // 1 - админ, 0 - пользователь
						else role = 0;
						break;
					}
					count++;
				}
				if (indicator == 0) printf("__________________Вы ввели неверный логин или пароль. Попробуйте ещё.(0.0)___________________________________________\n");
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
		printf("<(0.0)- 1.Посмотреть все учётные записи.\n");
		printf("<(0.0)- 2.Добавить новую учётную запись.\n");
		printf("<(0.0)- 3.Удалить учётную.\n");
		printf("<(0.0)- 4.Редактировать данные учётной записи.\n");
		printf("<(0.0)- 5.Вернуться назад.\n");
		printf("Введите свой выбор: ");
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
		printf("Ошибка открытия файла(0.0)\n");
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
		printf("Ошибка открытия файла(0.0)\n");
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
	printf("Логин\t\t Пароль\t\t   Роль\n");
	printf("----------------------------------------------\n");
	while (counter < count_profiles)
	{
		printf(" %s \t\t%d\t\t ", profile[counter].login, profile[counter].password);
		if (profile[counter].role == 1) printf("администратор\n");
		else printf(" пользователь\n");
		printf("----------------------------------------------\n");
		counter++;
	}
	printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
}

void enter_profile()
{
	printf("Введител логин <(0.0)- ");
	rewind(stdin);
	unique_login();
	printf("Введител пароль <(0.0)- ");
	scanf_s("%d", &profile[count_profiles].password);
	printf("Введите роль(1 - администратор, 0 - пользователь)<(0.0)-");
	int indicator = 0, temporary;
	while (indicator == 0)
	{
		scanf_s("%d", &temporary);
		if (temporary != 0 && temporary != 1) printf("Вы ввели неверное значение (1 - администратор, 0 - пользователь)\n");
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
	printf("Введите логин учётной записи, которую надо удалить: ");
	rewind(stdin);
	gets_s(temporary);
	while (counter1 <= count_profiles)
	{
		if (strcmp(profile[counter1].login, temporary) == 0)
		{
			if (profile[counter1].role == 1) printf("Вы не можете удалить другого администратора (0.0)\n");
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
	if (indicator == 0) printf("Профиля с таким логином не существует (0.0)\n");
}

void edit_profiles()
{
	int temporary_password, counter2 = 0, counter = 0, indicator = 0, number = -1;
	char temporary_login[20];
	printf("Введите логин учётной записи, которую надо отредактировать: ");
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
			printf("<(0.0)- 1.Изменить логин.\n");
			printf("<(0.0)- 2.Изменить пароль.\n");
			printf("<(0.0)- 3.Изменить роль.\n");
			printf("<(0.0)- 4.Сохранить внесённые изменения.\n");
			printf("<(0.0)-");
			scanf_s("%d", &choise);
			switch (choise)
			{
			case 1:
			{
				printf("Введите новый логин: ");
				rewind(stdin);
				gets_s(temporary_login);
				strcpy(profile[number].login, temporary_login);
				break;
			}
			case 2:
			{
				printf("Введите новый пароль: ");
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
			default: printf("Неверный выбор (0.0)\n");
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
		if (indicator == 1) printf("Упс, такой логин уже занят (0.0). Попробуйте другой: ");
	} while (indicator != 0);
	strcpy(profile[count_profiles].login, login);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////// ХЕШИРОВАНИЕ ///////////////////////////////////////////////////////////
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