#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<locale.h>
#include <windows.h>
#include "header.h"

void editing_mode()
{
	int choise;
	printf("�������, � ��� �� ������ ����������\n"
		"1 ���������\n"
		"2 ������\n"
		"3 ������ ����������\n");
	choise = check_int();
	system("chcp 1251");
	system("cls");
	switch (choise) //�������, � ������ ������� ��������
	{
		////////////////////////////////////////////////////////// ��������� /////////////////////////////////////////////////////////////
	case 1:
	{
		int choise = 0, count = 0;
		while (choise != 5)
		{
			
			printf("<(0.0)- 1.���������� ��� ���������.\n");
			printf("<(0.0)- 2.�������� ����� ���������.\n");
			printf("<(0.0)- 3.������� ���������.\n");
			printf("<(0.0)- 4.������������� ������ � ���������.\n");
			printf("<(0.0)- 5.��������� �����.\n");
			printf("������� ���� �����: ");
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
			default: printf("�� ����� �������� ����� (0.0)\n");
			}
		}
		break;
	}

	////////////////////////////////////////////////////////// ������ /////////////////////////////////////////////////////////////
	case 2:
	{
		int choise = 0, count = 0;
		while (choise != 5)
		{
			printf("<(0.0)- 1.���������� ��� ������.\n");
			printf("<(0.0)- 2.�������� ����� �����.\n");
			printf("<(0.0)- 3.������� �����.\n");
			printf("<(0.0)- 4.������������� ������ � ������.\n");
			printf("<(0.0)- 5.��������� �����.\n");
			printf("������� ���� �����: ");
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
			default: printf("�� ����� �������� ����� (0.0)\n");
			} 
		}
		break;
	}

	////////////////////////////////////////////////////////// ������ ���������� //////////////////////////////////////////////////////////
	case 3:
	{
		int choise = 0, count = 0;
		while (choise != 5)
		{
			printf("<(0.0)- 1.���������� ��� ���������.\n");
			printf("<(0.0)- 2.�������� ����� ����� ���������.\n");
			printf("<(0.0)- 3.������� ���������.\n");
			printf("<(0.0)- 4.������������� ������ � ���������.\n");
			printf("<(0.0)- 5.��������� �����.\n");
			printf("������� ���� �����: ");
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
			default: printf("�� ����� �������� ����� (0.0)\n");
			}
		}
		break;
	}
	default: printf("�� ����� �������� ����� (0.0)\n");
	}
}