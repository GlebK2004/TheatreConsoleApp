#pragma once
extern void editing_mode(); // ����� ��������������
extern void processing_mode(); // ����� ���������
extern int log_in_to_the_system(); // ���� � �������
extern void print_performances(); // ����� �������������
extern void print_sessions(); // ����� �������
extern void print_theatres(); // ����� �������
extern void enter_performance(); // ���� �������������
extern void enter_theatre(); // ���� �������
extern void enter_session(); // ���� ������
extern void find_performance(); // ����� �������������
extern void find_theatre();  // ����� �������
extern void find_session(); // ����� ������
extern void delete_performance(); // �������� �������������
extern void delete_theatre(); // �������� ������
extern void delete_session(); // �������� ������
extern void edit_performances(); // �������������� ���������
extern void edit_theatres(); // �������������� ������
extern void edit_session(); // �������������� ������
extern void sort_performances(); // ���������� �������������
extern void sort_theatres(); // ���������� �������
extern void sort_sessions(); // ���������� ������
extern void print_popular_theatres(); // ����� ����� ���������� �������
extern void print_popular_sessions(); // ����� ����� ���������� ������ ����������
extern void read_file(); // ������ ������ �� �����
extern void write_file(); // ������ ������ � ����
extern void profile_mode(); // ����� ������ � �������� ��������
extern void open_profiles(); // ������ �������� �� �����
extern void write_profiles(); // ������ �������� � ����
extern void print_profiles(); // ����� ��������
extern void enter_profile(); // ���� �������
extern void delete_profile(); // �������� �������
extern void edit_profiles(); // �������������� �������
extern int check_int(); // �������� ������������ ����� �����
extern int code(); // �������� ������������ ����� ����
extern long int Pnumber(); //�������� ������������ ����� ����������� ������
extern int enter_year(); // �������� ������������ ����� ����
extern int enter_month(); // �������� ������������ ����� ������
extern int enter_day(); // �������� ������������ ����� ���
extern void unique_login(); // �������� ������ �� ������������
extern int enter_rank(); // ���� �������� ������
extern void unique_theatre(); // �������� �� ������������ �������� ������ 
extern void unique_performance(); // �������� �� ������������ �������� ���������
extern int Hash(int); // ����������� ������ � ���
extern int DeHash(); // ����������� ���� � ������
