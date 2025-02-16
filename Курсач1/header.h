#pragma once
extern void editing_mode(); // Режим редактирования
extern void processing_mode(); // Режим обработки
extern int log_in_to_the_system(); // Вход в систему
extern void print_performances(); // Вывод представлений
extern void print_sessions(); // Вывод сеансов
extern void print_theatres(); // Вывод театров
extern void enter_performance(); // Ввод представлений
extern void enter_theatre(); // Ввод театров
extern void enter_session(); // Введ сессий
extern void find_performance(); // Поиск представлений
extern void find_theatre();  // Поиск театров
extern void find_session(); // Поиск сессий
extern void delete_performance(); // Удаление представления
extern void delete_theatre(); // Удаление театра
extern void delete_session(); // Удаление сессии
extern void edit_performances(); // Редактирование спектакля
extern void edit_theatres(); // Редактирование театра
extern void edit_session(); // Редактирование сессии
extern void sort_performances(); // Сортировка представлений
extern void sort_theatres(); // Сортировка театров
extern void sort_sessions(); // Сортировка сессий
extern void print_popular_theatres(); // Вывод самых популярных театров
extern void print_popular_sessions(); // Вывод самых популярных сессий спектаклей
extern void read_file(); // Чтение данных из файла
extern void write_file(); // Запись данных в файл
extern void profile_mode(); // Режим работы с учётными записями
extern void open_profiles(); // Чтение профилей из файла
extern void write_profiles(); // Запись профилей в файл
extern void print_profiles(); // Вывод профилей
extern void enter_profile(); // Ввод профиля
extern void delete_profile(); // Удаление профиля
extern void edit_profiles(); // Редактирование профиля
extern int check_int(); // Проверка корректности ввода числа
extern int code(); // Проверка корректности ввода кода
extern long int Pnumber(); //Проверка корректности ввода телефонного номера
extern int enter_year(); // Проверка корректности ввода года
extern int enter_month(); // Проверка корректности ввода месяца
extern int enter_day(); // Проверка корректности ввода дня
extern void unique_login(); // Проверка логина на уникальность
extern int enter_rank(); // Ввод рейтинга театра
extern void unique_theatre(); // Проверка на уникальность названия театра 
extern void unique_performance(); // Проверка на уникальность названия спектакля
extern int Hash(int); // Превращение пароля в хэш
extern int DeHash(); // Превращение хэша в пароль
