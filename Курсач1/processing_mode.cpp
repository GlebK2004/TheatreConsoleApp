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
		printf("�������, � ��� �� ������ ����������\n"
			"<(0.0)-1. �������� ������\n"
			"<(0.0)-2. �������������� �������\n"
			"<(0.0)-3. �����\n"
			"<(0.0)-4. ����������\n"
			"<(0.0)-5. ��������� ����� \n");
		printf("������� ���� �����: ");
		choise = check_int();
		switch (choise)
		{
		case 1:
		{
			int choise;
			printf("�������, ����� ������ �� ������ �������\n"
				"1 ���������\n"
				"2 ������\n"
				"3 ������ ����������\n");
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
			printf("��� �� ������ �������:\n");
			printf("1 ������\n");
			printf("2 ���������\n <(0.0)-");
			choise = check_int();
			switch (choise)
			{
			case 1:
			{
				print_popular_theatres();
				break;
			}
			//////////////////////////////////////////////// �������������� ������� //////////////////////////////////////////
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
			printf("�������, ����� ������ �� ������ �����\n"
				"1 ���������\n"
				"2 ������\n"
				"3 ������ ����������\n");
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
			///////////////////////////////////////////////////////// ���������� /////////////////////////////////////////////////////
			int choise;
			printf("�������, ����� ������ �� ������ �������������\n"
				"1 ���������\n"
				"2 ������\n"
				"3 ������ ����������\n");
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
		default:printf("�� ����� �������� ����� (0.0)\n");
		}
	}
}