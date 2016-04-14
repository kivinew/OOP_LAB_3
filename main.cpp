#include "time.h"

void main()
{
	setlocale(LC_ALL, "Russian");
	int nomer;
	char c = 0;
	while (c != '0')
	{
		cout << "---------------ГЛАВНОЕ МЕНЮ---------------" << endl;
		cout << "1. Создание нового объекта" << endl;
		cout << "2. Ввод новых значений для указанного объекта" << endl;
		cout << "3. Удаление указанного объекта" << endl;
		cout << "4. Вывод на экран всех объектов" << endl;
		cout << "0. ВЫХОД" << endl;
		cout << "Введите номер команды: ";
		cin >> c;
		switch (c)
		{
		case '0':
			break;	

		case '1':
			cout << endl << "-----Создание нового объекта-----" << endl;
			Time::AddTime();
			nomer = Time::GetSize();
			cout << "Создан "<< nomer << "-ый объект Time:" << endl;
			Time::ShowTime(nomer);
			break;

		case '2':

			break;

		case '3':

			break;

		case '4':

			break;

		default:
			cout << "Нет такой команды!" << endl;
			break;
		}
	}
}