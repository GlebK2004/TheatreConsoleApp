#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<locale.h>
#include <windows.h>
#include "header.h"

void editing_mode()
{
	int choise;
	printf("Введите, с чем вы хотите поработать\n"
		"1 Спектакли\n"
		"2 Театры\n"
		"3 Сеансы спектаклей\n");
	choise = check_int();
	system("chcp 1251");
	system("cls");
	switch (choise) //Выбрать, с какими данными работать
	{
		////////////////////////////////////////////////////////// СПЕКТАКЛИ /////////////////////////////////////////////////////////////
	case 1:
	{
		int choise = 0, count = 0;
		while (choise != 5)
		{
			
			printf("<(0.0)- 1.Посмотреть все спектакли.\n");
			printf("<(0.0)- 2.Добавить новый спектакль.\n");
			printf("<(0.0)- 3.Удалить спектакль.\n");
			printf("<(0.0)- 4.Редактировать данные о спектакле.\n");
			printf("<(0.0)- 5.Вернуться назад.\n");
			printf("Введите свой выбор: ");
			choise = check_int();
			switch (choise)
			{
			case 1:
			{
				print_performances();
				break;
			}
			case 2:
			{
				enter_performance();
				break;
			}
			case 3:
			{
				delete_performance();
				break;
			}
			case 4:
			{
				edit_performances();
				break;
			}
			case 5:
			{
				system("chcp 1251");
				system("cls");
				break;
			}
			default: printf("Вы ввели неверный выбор (0.0)\n");
			}
		}
		break;
	}

	////////////////////////////////////////////////////////// ТЕАТРЫ /////////////////////////////////////////////////////////////
	case 2:
	{
		int choise = 0, count = 0;
		while (choise != 5)
		{
			printf("<(0.0)- 1.Посмотреть все театры.\n");
			printf("<(0.0)- 2.Добавить новый театр.\n");
			printf("<(0.0)- 3.Удалить театр.\n");
			printf("<(0.0)- 4.Редактировать данные о театре.\n");
			printf("<(0.0)- 5.Вернуться назад.\n");
			printf("Введите свой выбор: ");
			choise = check_int();
			switch (choise)
			{
			case 1:
			{
				print_theatres();
				break;
			}
			case 2:
			{
				enter_theatre();
				break;
			}
			case 3:
			{
				delete_theatre();
				break;
			}
			case 4:
			{
				edit_theatres();
				break;
			}
			case 5:
			{
				system("chcp 1251");
				system("cls");
				break;
			}
			default: printf("Вы ввели неверный выбор (0.0)\n");
			} 
		}
		break;
	}

	////////////////////////////////////////////////////////// СЕАНСЫ СПЕКТАКЛЕЙ //////////////////////////////////////////////////////////
	case 3:
	{
		int choise = 0, count = 0;
		while (choise != 5)
		{
			printf("<(0.0)- 1.Посмотреть все спектакли.\n");
			printf("<(0.0)- 2.Добавить новый сеанс спектакля.\n");
			printf("<(0.0)- 3.Удалить спектакль.\n");
			printf("<(0.0)- 4.Редактировать данные о спектакле.\n");
			printf("<(0.0)- 5.Вернуться назад.\n");
			printf("Введите свой выбор: ");
			choise = check_int();
			switch (choise)
			{
			case 1:
			{
				print_sessions();
				break;
			}
			case 2:
			{
				enter_session();
				break;
			}
			case 3:
			{
				delete_session();
			}
			case 4:
			{
				edit_session();
				break;
			}
			case 5:
			{
				system("chcp 1251");
				system("cls");
				break;
			}
			default: printf("Вы ввели неверный выбор (0.0)\n");
			}
		}
		break;
	}
	default: printf("Вы ввели неверный выбор (0.0)\n");
	}
}