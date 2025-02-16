#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<locale.h>
#include <windows.h>
#include "header.h"

void processing_mode()
{
	int choise = 0;
	while (choise != 5)
	{
		printf("Введите, с чем вы хотите поработать\n"
			"<(0.0)-1. Просмотр данных\n"
			"<(0.0)-2. Индивидуальное задание\n"
			"<(0.0)-3. Поиск\n"
			"<(0.0)-4. Сортировка\n"
			"<(0.0)-5. Вернуться назад \n");
		printf("Введите свой выбор: ");
		choise = check_int();
		switch (choise)
		{
		case 1:
		{
			int choise;
			printf("Введите, какие данные вы ходите вывести\n"
				"1 Спектакли\n"
				"2 Театры\n"
				"3 Сеансы спектаклей\n");
			printf("<(0.0)- ");
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
				print_theatres();
				break;
			}
			case 3:
			{
				print_sessions();
				break;
			}
			}
			break;
		}
		case 2:
		{
			int choise;
			system("chcp 1251");
			system("cls");
			printf("Что вы хотите выбрать:\n");
			printf("1 Театры\n");
			printf("2 Спектакли\n <(0.0)-");
			choise = check_int();
			switch (choise)
			{
			case 1:
			{
				print_popular_theatres();
				break;
			}
			//////////////////////////////////////////////// ИНДИВИДУАЛЬНОЕ ЗАДАНИЕ //////////////////////////////////////////
			case 2:
			{
				print_popular_sessions();
				break;
			}
			break;
			}
			break;
		}
		case 3:
		{
			int choise;
			printf("Введите, какие данные вы ходите найти\n"
				"1 Спектакли\n"
				"2 Театры\n"
				"3 Сеансы спектаклей\n");
			printf("<(0.0)- ");
			choise = check_int();
			switch (choise)
			{
			case 1:
			{
				find_performance();
				break;
			}
			case 2:
			{
				find_theatre();
				break;
			}
			case 3:
			{
				find_session();
				break;
			}
			}
			break;
		}
		case 4:
		{
			///////////////////////////////////////////////////////// СОРТИРОВКА /////////////////////////////////////////////////////
			int choise;
			printf("Введите, какие данные вы ходите отсортировать\n"
				"1 Спектакли\n"
				"2 Театры\n"
				"3 Сеансы спектаклей\n");
			printf("<(0.0)- ");
			choise = check_int();
			switch (choise)
			{
			case 1:
			{
				sort_performances();
				print_performances();
				break;
			}
			case 2:
			{
				sort_theatres();
				print_theatres();
				break;
			}
			case 3:
			{
				sort_sessions();
				print_sessions();
				break;
			}
			}
			break;
		}
		case 5:
		{
			system("chcp 1251");
			system("cls");
			break;
		}
		default:printf("Вы ввели неверный выбор (0.0)\n");
		}
	}
}