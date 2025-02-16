#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<locale.h>
#include <windows.h>
#include "header.h"
const int maxLine = 20;
const int maxSize = 50;

FILE* f_theatres, * f_performances, * f_sessions;

struct performance
{
	int code;
	char name_p[maxLine];
	float price;
} performance[maxSize];

struct adress
{
	char street[maxLine];
	int house;
} adress[maxSize];

struct theatre
{
	int code;
	char name_t[maxLine];
	struct adress;
	long int phone_number;
	struct Rank;
} theatre[maxSize];

struct Rank
{
	int rank;
	int year;
	int month;
} rank[maxSize];

struct Date
{
	int year;
	int month;
	int day;
} date[maxSize];

struct Session
{
	int code;
	struct Date;
	struct theatre name_th[maxLine];
	struct performance name_per[maxLine]; 
	int tickets;
}  session[maxSize];

int count_theatres, count_performances, count_sessions;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////// ФАЙЛЫ ////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void read_file()
{
	if (!(f_performances = fopen("f_performances.txt", "a+b")))
	{
		printf("Ошибка создания файла(0.0)\n");
	}
	else
	{
		if (!(f_theatres = fopen("f_theatres.txt", "a+b")))
		{
			printf("Ошибка создания файла(0.0)\n");
		}
		else
		{
			if (!(f_sessions = fopen("f_sessions.txt", "a+b")))
			{
				printf("Ошибка создания файла(0.0)\n");
			}
			else
			{
				 count_performances = 0;
				 count_theatres = 0;
				 count_sessions = 0;
				 fseek(f_performances, 0, SEEK_SET);
				 if (getc(f_performances) != EOF)
				 {
					 fseek(f_performances, 0, SEEK_SET);
					 do
					 {
						 fscanf(f_performances, "%f %s %d ", &performance[count_performances].price, &performance[count_performances].name_p, &performance[count_performances].code);
						 count_performances++;
					 } while (!feof(f_performances));
					 //count_performances--;
				 }
				 if (getc(f_theatres) != EOF)
				 {
					 fseek(f_theatres, 0, SEEK_SET);
					 do
					 {
						 fscanf(f_theatres, "%s %d %s %d %d ", &adress[count_theatres].street, &adress[count_theatres].house, &theatre[count_theatres].name_t, &theatre[count_theatres].code, &theatre[count_theatres].phone_number);
						 fscanf(f_theatres, "%d %d %d ", &rank[count_theatres].rank, &rank[count_theatres].month, &rank[count_theatres].year);
						 count_theatres++;
					 } while (!feof(f_theatres));
					 //count_theatres--;
				 }
				 if (getc(f_sessions) != EOF)
				 {
					 char x1[20], x2[20];
					 fseek(f_sessions, 0, SEEK_SET);
					 do
					 {
						 fscanf(f_sessions, "%d %d %d %s %s %d %d ", &date[count_sessions].day, &date[count_sessions].month, &date[count_sessions].year, &session[count_sessions].name_th->name_t, &session[count_sessions].name_per->name_p, &session[count_sessions].tickets, &session[count_sessions].code);
						 //strcpy(session[count_sessions].name_th->name_t, x1);
						 //strcpy(session[count_sessions].name_per->name_p, x2);
						 count_sessions++;
					 } while (!feof(f_sessions));
					 //count_sessions--;
				 }
				 
			}
		}
		//printf("AAAAAAA\n");
	}
	fclose(f_performances);
	fclose(f_theatres);
	fclose(f_sessions);
}

void write_file()
{
	if (!(f_performances = fopen("f_performances.txt", "w+b")))
	{
		printf("Ошибка создания файла(0.0)\n");
	}
	else
	{
		if (!(f_theatres = fopen("f_theatres.txt", "w+b")))
		{
			printf("Ошибка создания файла(0.0)\n");
		}
		else
		{
			if (!(f_sessions = fopen("f_sessions.txt", "w+b")))
			{
				printf("Ошибка создания файла(0.0)\n");
			}
			else
			{
				for (int count = 0; count < count_performances; count++)
				{
					fprintf(f_performances, "%f %s %d ", performance[count].price, performance[count].name_p, performance[count].code);
				}
				for (int count = 0; count < count_theatres; count++)
				{
					fprintf(f_theatres, "%s %d ", adress[count].street, adress[count].house);
					fprintf(f_theatres, "%s %d %d ", theatre[count].name_t, theatre[count].code, theatre[count].phone_number);
					fprintf(f_theatres, "%d %d %d", rank[count].rank, rank[count].month, rank[count].year);


				}
				for (int counter = 0; counter < count_sessions; counter++)
				{
					fprintf(f_sessions, "%d %d %d %s %s %d %d ", date[counter].day, date[counter].month, date[counter].year, session[counter].name_th->name_t, session[counter].name_per->name_p, session[counter].tickets, session[counter].code);
				}
				fclose(f_performances);
				fclose(f_theatres);
				fclose(f_sessions);
			}
		}
	}
	//printf("BBBBBBBBBBBB\n");
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/************************************************************ СПЕКТАКЛИ ************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void print_performances()
{
	register int counter = 0;
	if (count_performances==0)
	{
		printf("Вы не ввели начальные данные(0.0)\n");
	}
	else
	{
		printf("\n");
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		printf("Код спектакля  \t Название \t  Цена билета\n");
		printf("----------------------------------------------\n");
		while (counter < count_performances)
		{
			printf("  %d   \t  %s \t%.2f рублей\n", performance[counter].code, performance[counter].name_p, performance[counter].price);
			printf("----------------------------------------------\n");
			counter++;
		}
		printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
		printf("\n");
	}
}

void enter_performance()
{
	if (count_performances < maxSize)
	{
		printf("Введите код нового спектакля: ");
		performance[count_performances].code = code();
		printf("Введите название спектакля: ");
		rewind(stdin);
		unique_performance();
		printf("Введите цену билета: ");
		performance[count_performances].price = check_int();
		count_performances++;
	}
	else printf("К сожалению, введено максимальное кол-во спектаклей(~.~).\n Для добавления нового необходимо удалить какой-либо текущий\n\n");
}

void delete_performance()
{
	int temporary_code, counter2 = 0, counter1 = 0, indicator = 0;
	printf("Введите код представления, которое надо удалить: ");
	temporary_code = check_int();
	while (counter1 <= count_performances)
	{
		if (temporary_code == performance[counter1].code)
		{
			counter2 = counter1;
			while (counter2 < count_performances-1)
			{
				performance[counter2] = performance[counter2 + 1];
				counter2++;
			}
			count_performances--;
			indicator = 1;
		}
		counter1++;
	}
	if (indicator == 0) printf("Спектакля с таким кодом не существует (0.0)\n");
}

void edit_performances()
{
	int temporary_code, count = 0, counter = 0, indicator = 0, number = -1;
	printf("Введите код представления, чьи данные надо изменить: ");
	temporary_code = check_int();
	while (counter < count_performances)
	{
		if (performance[counter].code == temporary_code) number = counter;
		counter++;
	}
	if (number != -1)
	{
		int choise = 0;
		while (choise != 4)
		{
			printf("<(0.0)- 1.Изменить код спектакля.\n");
			printf("<(0.0)- 2.Изменить название спектакля.\n");
			printf("<(0.0)- 3.Изменить цену билета на спектакль.\n");
			printf("<(0.0)- 4.Сохранить внесённые изменения.\n");
			printf("<(0.0)-");
			choise = check_int();
			switch (choise)
			{
			case 1:
			{
				printf("Введите новый код представления: ");
				temporary_code = code();
				performance[number].code = temporary_code;
				break;
			}
			case 2:
			{
				char temporary_name[20];
				printf("Введите новое название представления: ");
				rewind(stdin);
				gets_s(temporary_name);
				strcpy(performance[number].name_p, temporary_name);
				break;
			}
			case 3:
			{
				int temporary_price;
				printf("Введите новую цену на билет представления: ");
				temporary_price = check_int();
				performance[number].price = temporary_price;
				break;
			}
			case 4:
			{
				break;
			}
			default: printf("Вы ввели неверный выбор (0.0)\n");
			}
		}
	}
	else printf("Спектакля с таким кодом не существует (0.0)\n");
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/************************************************************ ТЕАТРЫ ***************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void print_theatres()
{
	register int counter = 0;
	if (count_theatres == 0)
	{
		printf("Вы не ввели начальные данные (0.0)\n");
	}
	else
	{
		printf("\n");
		
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		printf("\tАдресс\t\tНазвание       Код театра    Городской номер    Рейтинг    Месяц\n");
		printf("----------------------------------------------------------------------------------------\n");
		while (counter < count_theatres)
		{
			printf("ул. %s д. %d \t %s\t%d\t\t8029%d\t  %d \t %d.%d\n", adress[counter].street, adress[counter].house, theatre[counter].name_t, theatre[counter].code, theatre[counter].phone_number, rank[counter].rank, rank[counter].month, rank[counter].year);
			printf("----------------------------------------------------------------------------------------\n");
			counter++;
		}
		printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
		printf("\n");
	}
}

void enter_theatre()
{
	if (count_theatres < maxSize)
	{
		printf("Для начала введите адресс театра\n");
		printf("Улица: ");
		rewind(stdin);
		gets_s(adress[count_theatres].street);
		printf("Номер дома: ");
		adress[count_theatres].house = check_int();
		printf("Теперь введите его название: ");
		rewind(stdin);
		unique_theatre();
		printf("Введите код театра: ");
		theatre[count_theatres].code = code();
		printf("Введите городской номер телефона (7 цифр без кода оператора): ");
		theatre[count_theatres].phone_number = Pnumber();
		printf("Введите рейтинг театра за месяц (от 1 до 100): ");
		rank[count_theatres].rank = enter_rank();
		printf("Введите сам месяц: ");
		rank[count_theatres].month = enter_month();
		printf("Введите год: ");
		rank[count_theatres].year = enter_year();
		count_theatres++;
	}
	else printf("К сожалению, введено максимальное кол-во театров(~.~).\n Для добавления нового необходимо удалить какой-либо текущий\n\n");

}

void delete_theatre()
{
	int temporary_code, counter2 = 0, counter1 = 0, indicator = 0;
	printf("Введите код театра, который надо удалить: ");
	temporary_code = check_int();
	while (counter1 <= count_theatres)
	{
		if (temporary_code == theatre[counter1].code)
		{
			counter2 = counter1;
			while (counter2 < count_performances - 1)
			{
				theatre[counter2] = theatre[counter2 + 1];
				rank[counter2] = rank[counter2 + 1];
				adress[counter2] = adress[counter2 + 1];
				counter2++;
			}
			count_theatres--;
			indicator = 1;
		}
		counter1++;
	}
	if (indicator == 0) printf("Театра с таким кодом не существует (0.0)\n");
}

void edit_theatres()
{
	int temporary_code, count = 0, counter = 0, indicator = 0, number = -1;
	printf("Введите код театра, чьи данные надо изменить: ");
	temporary_code = check_int();
	while (counter < count_theatres)
	{
		if (theatre[counter].code == temporary_code) number = counter;
		counter++;
	}
	if (number != -1)
	{
		int choise = 0;
		while (choise != 5)
		{
			printf("<(0.0)- 1.Изменить код театра.\n");
			printf("<(0.0)- 2.Изменить название театра.\n");
			printf("<(0.0)- 3.Изменить телефонный номер театра.\n");
			printf("<(0.0)- 4.Изменить рейтинг театра.\n");
			printf("<(0.0)- 5.Сохранить внесённые изменения.\n");
			printf("<(0.0)-");
			scanf_s("%d", &choise);
			switch (choise)
			{
			case 1:
			{
				printf("Введите новый код представления: ");
				temporary_code = check_int();
				theatre[number].code = temporary_code;
				break;
			}
			case 2:
			{
				char temporary_name[20];
				printf("Введите новое название представления: ");
				rewind(stdin);
				gets_s(temporary_name);
				strcpy(theatre[number].name_t, temporary_name);
				break;
			}
			case 3:
			{
				long int temporary_phone_number;
				printf("Введите новую цену на билет представления: ");
				temporary_phone_number = Pnumber();
				theatre[number].phone_number = temporary_phone_number;
				break;
			}
			case 4:
			{
				int rank1;
				printf("Введите новый рейтинг спектакля: ");
				rank1 = enter_rank();
				rank[number].rank = rank1;
				break;
			}
			case 5:
			{
				break;
			}
			default: printf("Вы ввели неверный выбор (0.0)\n");
			}
		}
	}
	else printf("Театра с таким кодом не существует (0.0)\n");
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/************************************************************ СЕАНСЫ ***************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void print_sessions()
{
	register int counter = 0;
	if (count_sessions == 0)
	{
		printf("Вы не ввели начальные данные(0.0)\n");
	}
	else
	{
		printf("\n");
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		printf("Дата  \t \t Название театра  \t Название спектакля\t Кол-во проданных билетов\tКод\n");
		printf("------------------------------------------------------------------------------------------------------\n");
		while (counter < count_sessions)
		{
			printf("%d.%d.%d    \t   %s   \t  %s  \t\t \t %d  \t \t\t%d\n", date[counter].day, date[counter].month, date[counter].year, session[counter].name_th->name_t, session[counter].name_per->name_p, session[counter].tickets, session[counter].code);
			printf("------------------------------------------------------------------------------------------------------\n");
			counter++;
		}
		printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
		printf("\n");
	}
}


void enter_session()
{
	if (count_sessions < maxSize)
	{
		char name_t[20], name_p[20];
		printf("Введите дату спектакля\n");
		printf("год:");
		date[count_sessions].year = enter_year();
		printf("месяц(числом):");
		date[count_sessions].month = enter_month();
		printf("день:");
		date[count_sessions].day = enter_day();
		printf("\n\nТеперь введите данные о новом спектакле\n");
		printf("Название театра: ");
		rewind(stdin);
		gets_s(name_t);
		int indicator = 0;
		for (int count = 0; count < count_theatres; count++)
		{
			if (strcmp(theatre[count].name_t, name_t) == 0) indicator = 1;
		}
		if (indicator == 0)
		{
			printf("Введённого театра не существует. Давайте его создадим\n");
			enter_theatre();
		}
		strcpy(session[count_sessions].name_th->name_t, name_t);

		printf("Название спектакля: ");
		rewind(stdin);
		gets_s(name_p);
		indicator = 0;
		for (int count = 0; count < count_performances; count++)
		{
			if (strcmp(performance[count].name_p, name_p) == 0) indicator = 1;
		}
		if (indicator == 0)
		{
			printf("Введённого спектакля не существует. Давайте его создадим\n");
			enter_performance();
		}
		strcpy(session[count_sessions].name_per->name_p, name_p);
		printf("Количество проданных билетов: ");
		session[count_sessions].tickets = check_int();
		printf("Код: ");
		session[count_sessions].code = code();
		count_sessions++;
	}
	else printf("К сожалению, введено максимальное кол-во сеансов(~.~).\n Для добавления нового необходимо удалить какой-либо текущий\n\n");
}

void delete_session()
{
	int temporary_code, counter2 = 0, counter1 = 0, indicator = 0;
	printf("Введите код сеанса, который надо удалить\n");
	temporary_code = check_int();
	while (counter1 <= count_sessions)
	{
		if (temporary_code == session[counter1].code)
		{
			counter2 = counter1;
			while (counter2 < count_performances - 1)
			{
				session[counter2] = session[counter2 + 1];
				counter2++;
			}
			count_sessions--;
			indicator = 1;
		}
		counter1++;
	}
	if (indicator == 0) printf("Театра с таким кодом не существует (0.0)\n");
}


void edit_session()
{
	int temporary_code, count = 0, counter = 0, indicator = 0, number = -1;
	printf("Введите код сеанса, чьи данные надо изменить\n");
	temporary_code = check_int();
	while (counter < count_sessions)
	{
		if (session[counter].code == temporary_code) number = counter;
		counter++;
	}
	if (number != -1)
	{
		int choise = 0;
		while (choise != 6)
		{
			printf("<(0.0)- 1.Изменить код сеанса.\n");
			printf("<(0.0)- 2.Изменить дату сеанса.\n");
			printf("<(0.0)- 3.Изменить название театра.\n");
			printf("<(0.0)- 4.Изменить название спектакля.\n");
			printf("<(0.0)- 5.Изменить кол-во проданных билетов.\n");
			printf("<(0.0)- 6.Сохранить внесённые изменения.\n");
			printf("<(0.0)-");
			choise = check_int();
			switch (choise)
			{
			case 1:
			{
				printf("Введите новый код представления");
				temporary_code = check_int();
				session[number].code = temporary_code;
				break;
			}
			case 2:
			{
				int choise = 0;
				while (choise != 4)
				{
					printf("<(0.0)- 1.Изменить год.\n");
					printf("<(0.0)- 2.Изменить месяц.\n");
					printf("<(0.0)- 3.Изменить день.\n");
					printf("<(0.0)- 4.Сохранить внесённые изменения.\n");
					printf("<(0.0)-");
					scanf_s("%d", &choise);
					switch (choise)
					{
					case 1:
					{
						int year;
						printf("Введите новый год: ");
						year = enter_year();
						date[number].year = year;
						break;
					}
					case 2:
					{
						int month;
						printf("Введите новый месяц: ");
						month = enter_month();
						date[number].month = month;
						break;
					}
					case 3:
					{
						int day;
						printf("Введите новый день: ");
						day = enter_day();
						date[number].day = day;
						break;
					}
					case 4:
					{
						break;
					}
					}
				}
			}
			case 3:
			{ 
				char temporary_name[20];
				printf("Введите новое название театра: ");
				rewind(stdin);
				gets_s(temporary_name);
				int indicator = 0;
				for (int count = 0; count < count_theatres; count++)
				{
					if (strcmp(theatre[count].name_t, temporary_name) == 0) indicator = 1;
				}
				if (indicator == 0)
				{
					printf("Введённого театра не существует. Давайте его создадим\n");
					enter_theatre();
				}
				strcpy(session[number].name_th->name_t, temporary_name);
				break;
			}
			case 4:
			{
				char temporary_name[20];
				printf("Введите новое название театра: ");
				rewind(stdin);
				gets_s(temporary_name);
				int indicator = 0;
				for (int count = 0; count < count_theatres; count++)
				{
					if (strcmp(performance[count].name_p, temporary_name) == 0) indicator = 1;
				}
				if (indicator == 0)
				{
					printf("Введённого спектакля не существует. Давайте его создадим\n");
					enter_performance();
				}
				strcpy(session[number].name_per->name_p, temporary_name);
				break;
			}
			case 5:
			{
				int temporary;
				printf("Введите новое кол-во проданных билетов: ");
				temporary = check_int();
				session[number].tickets = temporary;
				break;
			}
			case 6:
			{
				break;
			}
			default: printf("Вы ввели неверный выбор (0.0)\n");
			}
		}
	}
	else printf("Сеанс с таким кодом не существует (0.0)\n");
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////// ФУНКЦИИ ПОИСКА /////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void find_performance()
{
	int temporary, choise, count = 0, indicator = 0;
	char name[20];
	printf("Выберете, по чему поводить поиск:\n");
	printf("1. Код \n");
	printf("2. Название спектакля \n");
	printf("3. Стоимость билета \n");
	choise = check_int();
	switch (choise)
	{
	case 1:
		{
			printf("Введите код: ");
			temporary = check_int();
			while (count <= count_performances)
			{
				if (temporary == performance[count].code)
				{
					printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
					printf("Код спектакля  \t Название \t  Цена билета\n");
					printf("----------------------------------------------\n");
					printf("  %d   \t  %s \t%.2f рублей\n", performance[count].code, performance[count].name_p, performance[count].price);
					printf("----------------------------------------------\n");
					indicator = 1;
				}
				count++;
			}
			if (indicator == 0) printf("Спектакля с таким кодом не существует (0.0)\n");
			break;
		}
	case 2:
		{
			printf("Введите название спектакля: ");
			rewind(stdin);
			gets_s(name);
			while (count <= count_performances)
			{
				if ((strcmp(performance[count].name_p, name) == 0))
				{
					printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
					printf("Код спектакля  \t Название \t  Цена билета\n");
					printf("----------------------------------------------\n");
					printf("  %d   \t  %s \t%.2f рублей\n", performance[count].code, performance[count].name_p, performance[count].price);
					printf("----------------------------------------------\n");
					indicator = 1;
				}
				count++;
			}
			if (indicator == 0) printf("Спектакля с таким кодом не существует (0.0)\n");
			break;
		}
	case 3:
		{
			printf("Введите цену билета: ");
			temporary = check_int();
			while (count <= count_performances)
			{
				if (temporary == performance[count].price)
				{
					printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
					printf("Код спектакля  \t Название \t  Цена билета\n");
					printf("----------------------------------------------\n");
					printf("  %d   \t  %s \t%.2f рублей\n", performance[count].code, performance[count].name_p, performance[count].price);
					printf("----------------------------------------------\n");
					indicator = 1;
				}
				count++;
			}
			if (indicator == 0) printf("Спектакля с таким кодом не существует (0.0)\n");
			break;
		}
	}
}


void find_theatre()
{
	int temporary, choise, count = 0, counter = 0, indicator = 0;
	char name[20];
	printf("Выберете, по чему поводить поиск:\n");
	printf("1. Код \n");
	printf("2. Название театра \n");
	printf("3. Телефонный номер \n");
	choise = check_int();
	switch (choise)
	{
	case 1:
		{
			printf("Введите код театра, который вы хотите найти: ");
			temporary = check_int();
			while (count <= count_theatres)
			{
				if (temporary == theatre[count].code)
				{
					printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
					printf("\tАдресс\t\tНазвание       Код театра    Городской номер    Рейтинг\n");
					printf("--------------------------------------------------------------------------------\n");
					printf("ул. %s д. %d \t %s\t%d\t\t8029%d\t  %d\n", adress[counter].street, adress[counter].house, theatre[counter].name_t, theatre[counter].code, theatre[counter].phone_number, rank[counter].rank);
					printf("--------------------------------------------------------------------------------\n");
					indicator = 1;
				}
				count++;
			}
			if (indicator == 0) printf("Театра с таким кодом не существует (0.0)\n");
			break;
		}
	case 2:
		{
			printf("Введите название театра, который вы хотите найти: "); 
			rewind(stdin);
			gets_s(name);
			while (count <= count_theatres)
			{
				if ((strcmp(theatre[count].name_t, name) == 0))
				{
					printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
					printf("\tАдресс\t\tНазвание       Код театра    Городской номер    Рейтинг\n");
					printf("--------------------------------------------------------------------------------\n");
					printf("ул. %s д. %d \t %s\t%d\t\t8029%d\t  %d\n", adress[counter].street, adress[counter].house, theatre[counter].name_t, theatre[counter].code, theatre[counter].phone_number, rank[counter].rank);
					printf("--------------------------------------------------------------------------------\n");
					indicator = 1;
				}
				count++;
			}
			if (indicator == 0) printf("Театра с таким названием не существует (0.0)\n");		
			break;
		}
	case 3:
		{
			printf("Введите телефонный номер театра, который вы хотите найти\n");
			temporary = check_int();
			while (count <= count_theatres)
			{
				if (temporary == theatre[count].phone_number)
				{
					printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
					printf("\tАдресс\t\tНазвание       Код театра    Городской номер    Рейтинг\n");
					printf("--------------------------------------------------------------------------------\n");
					printf("ул. %s д. %d \t %s\t%d\t\t8029%d\t  %d\n", adress[counter].street, adress[counter].house, theatre[counter].name_t, theatre[counter].code, theatre[counter].phone_number, rank[counter].rank);
					printf("--------------------------------------------------------------------------------\n");
					indicator = 1;
				}
				count++;
			}
			if (indicator == 0) printf("Театра с таким кодом не существует (0.0)\n");
			break;
		}
	}
}

void find_session()
{
	int temporary, choise, count = 0, counter = 0, indicator = 0;
	char name[20];
	printf("Выберете, по чему поводить поиск:\n");
	printf("1. Название спектакля \n");
	printf("2. Название театра \n");
	printf("3. Кол-во проданных билетов \n");
	choise = check_int();
	switch (choise)
	{
	case 1:
		{
			printf("Введите название спектакля, чей сеанс вы ищете\n");
			rewind(stdin);
			gets_s(name);
			while (count <= count_sessions)
			{
				if ((strcmp(session[count].name_per->name_p, name) == 0))
				{
					printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
					printf("Дата  \t \t Название театра  \t Название спектакля\t Кол-во проданных билетов\tКод\n");
					printf("------------------------------------------------------------------------------------------------------\n");
					printf("%d.%d.%d    \t   %s   \t  %s  \t\t \t %d  \t \t\t%d\n", date[counter].day, date[counter].month, date[counter].year, session[counter].name_th->name_t, session[counter].name_per->name_p, session[counter].tickets, session[counter].code);
					printf("------------------------------------------------------------------------------------------------------\n");
					indicator = 1;
				}
				count++;
			}
			if (indicator == 0) printf("Такого сеанса не существует (0.0)\n");
			break;
		}
	case 2:
		{
			printf("Введите название театра, в котором будет необходимый сеанс\n");
			rewind(stdin);
			gets_s(name);
			while (count <= count_sessions)
			{
				if ((strcmp(session[count].name_th->name_t, name) == 0))
				{
					printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
					printf("Дата  \t \t Название театра  \t Название спектакля\t Кол-во проданных билетов\tКод\n");
					printf("------------------------------------------------------------------------------------------------------\n");
					printf("%d.%d.%d    \t   %s   \t  %s  \t\t \t %d  \t \t\t%d\n", date[counter].day, date[counter].month, date[counter].year, session[counter].name_th->name_t, session[counter].name_per->name_p, session[counter].tickets, session[counter].code);
					printf("------------------------------------------------------------------------------------------------------\n");
					indicator = 1;
				}
				count++;
			}
			if (indicator == 0) printf("Такого сеанса не существует (0.0)\n");
			break;
		}
	case 3:
		{
			printf("Введите телефонный номер театра, который вы хотите найти\n");
			temporary = check_int();
			while (count <= count_sessions)
			{
				if (temporary == session[count].tickets)
				{
					printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
					printf("Дата  \t \t Название театра  \t Название спектакля\t Кол-во проданных билетов\tКод\n");
					printf("------------------------------------------------------------------------------------------------------\n");
					printf("%d.%d.%d    \t   %s   \t  %s  \t\t \t %d  \t \t\t%d\n", date[counter].day, date[counter].month, date[counter].year, session[counter].name_th->name_t, session[counter].name_per->name_p, session[counter].tickets, session[counter].code);
					printf("------------------------------------------------------------------------------------------------------\n");
					indicator = 1;
				}
				count++;
			}
			if (indicator == 0) printf("Такого сеанса не существует (0.0)\n");
			break;
		}
	}
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////// СОРТИРОВКА ///////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void sort_performances()
{
	int choise;
	printf("Выберете, по чему поводить сортировку:\n");
	printf("1. Код \n");
	printf("2. Название спектакля \n");
	printf("3. Стоимость билета \n");
	choise = check_int();
	switch (choise)
	{
	case 1:
		{
			int i, j;
			int gap;     //шаг сортировки     
			int sorted;  //флаг окончания этапа сортировки
			for (gap = count_performances / 2; gap > 0; gap /= 2)//начало сортировки
				do {
					sorted = 0;
					for (i = 0, j = gap; j < count_performances; i++, j++)
						if (performance[i].code > performance[j].code)
						{
							struct performance temp;
							temp = performance[i];
							performance[i] = performance[j];
							performance[j] = temp;
							sorted = 1;
						}
				} while (sorted);
				break;
		}
	case 2:
		{
			int i, j;
			int gap;     //шаг сортировки     
			int sorted;  //флаг окончания этапа сортировки
			for (gap = count_performances / 2; gap > 0; gap /= 2)//начало сортировки
				do {
					sorted = 0;
					for (i = 0, j = gap; j < count_performances; i++, j++)
						if (strcmp(performance[i].name_p, performance[j].name_p) > 0)
						{
							struct performance temp;
							temp = performance[i];
							performance[i] = performance[j];
							performance[j] = temp;
							sorted = 1;
						}
				} while (sorted);
				break;
		}
	case 3:
		{
			int i, j;
			int gap;     //шаг сортировки     
			int sorted;  //флаг окончания этапа сортировки
			for (gap = count_performances / 2; gap > 0; gap /= 2)//начало сортировки
				do {
					sorted = 0;
					for (i = 0, j = gap; j < count_performances; i++, j++)
						if (performance[i].price > performance[j].price)
						{
							struct performance temp;
							temp = performance[i];
							performance[i] = performance[j];
							performance[j] = temp;
							sorted = 1;
						}
				} while (sorted);
				break;
		}
	}
}


void sort_theatres()
{
	int choise;
	printf("Выберете, по чему поводить сортировку:\n");
	printf("1. Код \n");
	printf("2. Название театра \n");
	printf("3. Телефонный номер \n");
	choise = check_int();
	switch (choise)
	{
	case 1:
		{
			int i, j;
			int gap;     //шаг сортировки     
			int sorted;  //флаг окончания этапа сортировки
			for (gap = count_theatres / 2; gap > 0; gap /= 2)//начало сортировки
				do {
					sorted = 0;
					for (i = 0, j = gap; j < count_theatres; i++, j++)
						if (theatre[i].code > theatre[j].code)
						{
							struct theatre temp;
							temp = theatre[i];
							theatre[i] = theatre[j];
							theatre[j] = temp;
							sorted = 1;
						}
				} while (sorted);
				break;
		}
	case 2:
		{
			int i, j;
			int gap;     //шаг сортировки     
			int sorted;  //флаг окончания этапа сортировки
			for (gap = count_theatres / 2; gap > 0; gap /= 2)//начало сортировки
				do {
					sorted = 0;
					for (i = 0, j = gap; j < count_theatres; i++, j++)
						if (strcmp(theatre[i].name_t, theatre[j].name_t) > 0)
						{
							struct theatre temp;
							temp = theatre[i];
							theatre[i] = theatre[j];
							theatre[j] = temp;
							sorted = 1;
						}
				} while (sorted);
				break;
		}
	case 3:
		{
			int i, j;
			int gap;     //шаг сортировки     
			int sorted;  //флаг окончания этапа сортировки
			for (gap = count_theatres / 2; gap > 0; gap /= 2)//начало сортировки
				do {
					sorted = 0;
					for (i = 0, j = gap; j < count_theatres; i++, j++)
						if (theatre[i].phone_number > theatre[j].phone_number)
						{
							struct theatre temp;
							temp = theatre[i];
							theatre[i] = theatre[j];
							theatre[j] = temp;
							sorted = 1;
						}
				} while (sorted);
				break;
		}
	}
}


void sort_sessions()
{
	int choise;
	printf("Выберете, по чему поводить сортировку:\n");
	printf("1. Название спектакля \n");
	printf("2. Название театра \n");
	printf("3. Кол-во проданных билетов \n");
	choise = check_int();
	switch (choise)
	{
	case 1:
		{
			int i, j;
			int gap;     //шаг сортировки     
			int sorted;  //флаг окончания этапа сортировки
			for (gap = count_sessions / 2; gap > 0; gap /= 2)//начало сортировки
				do {
					sorted = 0;
					for (i = 0, j = gap; j < count_sessions; i++, j++)
						if ((strcmp(session[i].name_th->name_t, session[j].name_th->name_t) > 0))
						{
							struct Session temp;
							struct Date temp1;
							temp = session[i];
							session[i] = session[j];
							session[j] = temp;
							temp1 = date[i];
							date[i] = date[j];
							date[j] = temp1;
							sorted = 1;
						}
				} while (sorted);
				break;
		}
	case 2:
		{
			int i, j;
			int gap;     //шаг сортировки     
			int sorted;  //флаг окончания этапа сортировки
			for (gap = count_sessions / 2; gap > 0; gap /= 2)//начало сортировки
				do {
					sorted = 0;
					for (i = 0, j = gap; j < count_sessions; i++, j++)
						if ((strcmp(session[i].name_per->name_p, session[j].name_per->name_p) > 0))
						{
							struct Session temp;
							struct Date temp1;
							temp = session[i];
							session[i] = session[j];
							session[j] = temp;
							temp1 = date[i];
							date[i] = date[j];
							date[j] = temp1;
							sorted = 1;
						}
				} while (sorted);
				break;
		}
	case 3:
		{
			int i, j;
			int gap;     //шаг сортировки     
			int sorted;  //флаг окончания этапа сортировки
			for (gap = count_sessions / 2; gap > 0; gap /= 2)//начало сортировки
				do {
					sorted = 0;
					for (i = 0, j = gap; j < count_sessions; i++, j++)
						if (session[i].tickets > session[j].tickets)
						{
							struct Session temp;
							struct Date temp1;
							temp = session[i];
							session[i] = session[j];
							session[j] = temp;
							temp1 = date[i];
							date[i] = date[j];
							date[j] = temp1;
							sorted = 1;
						}
				} while (sorted);
				break;
		}
	}
}





/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////// ИНДИВИДУАЛЬНОЕ ЗАДАНИЕ //////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*Индивидуальное задание : вывести список самых популярных театров в порядке убывания в
указанный месяц.Вывести список самых популярных спектаклей в порядке убывания в указанный месяц.
Месяц вводится с клавиатуры.*/

void print_popular_sessions()
{
	int month, year;
	printf("Введите месяц, в котором вы хотите узнать самые популярные сеансы спектаклей: ");
	month = enter_month();
	printf("Введите год: ");
	year = enter_year();
	int count, count_temp=0;
	struct Session temporary[50];
	struct Date temp_date[50];
	for (count = 0; count < count_sessions; count++)
	{
		if (date[count].month == month && date[count].year == year)
		{
			temporary[count_temp] = session[count];
			temp_date[count_temp] = date[count];
			count_temp++;
		}
	}
	if (count_temp == 0) printf("В этом месяце не было ни одного спектакля (0.0)\n");
	else
	{
		int i, j;
		int gap;     //шаг сортировки     
		int sorted;  //флаг окончания этапа сортировки
		for (gap = count_temp / 2; gap > 0; gap /= 2)//начало сортировки
			do {
				sorted = 0;
				for (i = 0, j = gap; j < count_temp; i++, j++)
					if (temporary[i].tickets > temporary[j].tickets)
					{
						struct Session temp;
						struct Date temp1;
						temp = temporary[i];
						temporary[i] = temporary[j];
						temporary[j] = temp;
						temp1 = temp_date[i];
						temp_date[i] = temp_date[j];
						temp_date[j] = temp1;
						sorted = 1;
					}
			} while (sorted);

			int counter = 0;
			printf("\n");
			printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
			printf("Дата  \t \t Название театра  \t Название спектакля\t Кол-во проданных билетов\tКод\n");
			printf("------------------------------------------------------------------------------------------------------\n");
			while (counter < count_temp)
			{
				printf("%d.%d.%d    \t   %s   \t  %s  \t\t \t %d  \t \t\t%d\n", temp_date[counter].day, temp_date[counter].month, temp_date[counter].year, temporary[counter].name_th->name_t, temporary[counter].name_per->name_p, temporary[counter].tickets, temporary[counter].code);
				printf("------------------------------------------------------------------------------------------------------\n");
				counter++;
			}
			printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
			printf("\n");

	}

}



void print_popular_theatres()
{
	int month, year;
	printf("Введите месяц, в котором вы хотите узнать самые популярные театры: ");
	month = enter_month();
	printf("Введите год: ");
	year = enter_year();
	int count, count_temp = 0;
	struct theatre temporary[50];
	struct adress temp_adress[50];
	struct Rank temp_rank[50];
	for (count = 0; count < count_theatres; count++)
	{
		if (rank[count].month == month && rank[count].year == year)
		{
			temporary[count_temp] = theatre[count];
			temp_adress[count_temp] = adress[count];
			temp_rank[count_temp] = rank[count];
			count_temp++;
		}
	}
	if (count_temp == 0) printf("Об этом месяце нет данных (0.0)\n");
	else
	{
		int i, j;
		int gap;     //шаг сортировки     
		int sorted;  //флаг окончания этапа сортировки
		for (gap = count_temp / 2; gap > 0; gap /= 2)//начало сортировки
			do {
				sorted = 0;
				for (i = 0, j = gap; j < count_temp; i++, j++)
					if (temp_rank[i].rank < temp_rank[j].rank)
					{
						struct theatre temp;
						struct adress temp1;
						struct Rank temp2;
						temp = temporary[i];
						temporary[i] = temporary[j];
						temporary[j] = temp;
						temp1 = temp_adress[i];
						temp_adress[i] = temp_adress[j];
						temp_adress[j] = temp1;
						temp2 = temp_rank[i];
						temp_rank[i] = temp_rank[j];
						temp_rank[j] = temp2;
						sorted = 1;
					}
			} while (sorted);

			int counter = 0;
			printf("\n");
			printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
			printf("\tАдресс\t\tНазвание       Код театра    Городской номер    Рейтинг    Месяц\n");
			printf("----------------------------------------------------------------------------------------\n");
			while (counter < count_theatres)
			{
				printf("ул. %s д. %d \t %s\t%d\t\t8029%d\t  %d \t %d.%d\n", temp_adress[counter].street, temp_adress[counter].house, temporary[counter].name_t, temporary[counter].code, temporary[counter].phone_number, temp_rank[counter].rank, temp_rank[counter].month, temp_rank[counter].year);
				printf("----------------------------------------------------------------------------------------\n");
				counter++;
			}
			printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
			printf("\n");
	}
}




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////// ПРОВЕРКИ //////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int check_int()  ///// CHECK INT 
{
	int x, number;
	x = scanf("%d", &number);
	while (x != 1)
	{
		printf("Вы где-то ошиблись (0.0), попробуйте ещё раз:");
		while(getchar() != '\n');
		x = scanf("%d", &number);
	}
	return number;
}


int code()
{
	int code, code1, count, indicator=0;
	while (indicator != 1)
	{
		count = 0;
		code = check_int();
		code1 = code;
		while (code1 != 0)
		{
			code1 = code1 / 10;
			count++;
		}
		if (count != 5) printf("Код должен состоять из пяти цифр (0,0). Давайте введём его ещё раз: ");
		else indicator = 1;
	}
	return code;
}


long int Pnumber()
{
	long int code, code1, count, indicator = 0;
	while (indicator != 1)
	{
		count = 0;
		code = check_int();
		code1 = code;
		while (code1 != 0)
		{
			code1 = code1 / 10;
			count++;
		}
		if (count != 7) printf("Номер должен состоять из семи цифр (0,0). Давайте введём его ещё раз: ");
		else indicator = 1;
	}
	return code;
}

int enter_year()
{
	int year, count, indicator = 0;
	while (indicator != 1)
	{
		year = check_int();
		if (year > 2022 || year < 1991) printf("Вы ввели неверный год (необходимо с 1991 по 2022). Попробуйте ещё раз: ");
		else indicator = 1;
	}
	return year;
}

int enter_month()
{
	int month, count, indicator = 0;
	while (indicator != 1)
	{
		month = check_int();
		if (month > 12 || month < 1) printf("Вы ввели неверный месяц. Попробуйте ещё раз: ");
		else indicator = 1;
	}
	return month;
}


int enter_day()
{
	int day, count, indicator = 0;
	while (indicator != 1)
	{
		day = check_int();
		if (date[count_sessions].month == 2 && (day > 28 || day < 1)) printf("Вы ввели неверный число февраля (в нём всего 28 дней). Попробуйте ещё раз: ");
		else
		{
			if (day > 30 || day < 1) printf("Вы ввели неверный день. Попробуйте ещё раз: ");
			else indicator = 1;
		}
	}
	return day;
}

int enter_rank()
{
	int rank, count, indicator = 0;
	while (indicator != 1)
	{
		rank = check_int();
		if (rank > 100 || rank < 1) printf("Вы ввели неверный рейтинг. Попробуйте ещё раз: ");
		else indicator = 1;
	}
	return rank;
}

void unique_theatre()
{
	char name[20];
	int indicator = 0;
	do
	{
		indicator = 0;
		rewind(stdin);
		gets_s(name);
		for (int counter = 0; counter < count_theatres; counter++)
		{
			if (strcmp(theatre[counter].name_t, name) == 0) indicator = 1;
		}
		if (indicator == 1) printf("Упс, такой театр уже существует (0.0). Попробуйте другой: ");
	} while (indicator != 0);
	strcpy(theatre[count_theatres].name_t, name);
}


void unique_performance()
{
	char name[20];
	int indicator = 0;
	do
	{
		indicator = 0;
		rewind(stdin);
		gets_s(name);
		for (int counter = 0; counter < count_performances; counter++)
		{
			if (strcmp(performance[counter].name_p, name) == 0) indicator = 1;
		}
		if (indicator == 1) printf("Упс, такой  спектакль уже существует (0.0). Попробуйте другой: ");
	} while (indicator != 0);
	strcpy(performance[count_performances].name_p, name);
}