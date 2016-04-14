#include "time.h"

void main()
{
	setlocale(LC_ALL, "Russian");
	AbstractTime* time;
	int nomer, size;
	char c = 0;
	while (c != '0')
	{
		cout << endl << "---------------ГЛАВНОЕ МЕНЮ---------------" << endl;
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
			cout << endl << "----------Создание нового объекта----------" << endl;
			Time::AddTime();
			nomer = Time::GetSize() - 1;
			cout << "Создан "<< nomer << "-ый объект Time:" << endl;
			time = Time::GetPointerTime(nomer);
			time->PrintTime();
			break;

		case '2':
			cout << endl << "-----Ввод новых значений для указанного объекта-----" << endl;
			nomer = -1;
			size = Time::GetSize();
			while ((nomer < 0) || (nomer >= size))
			{
				cout << "Введите номер объекта: ";
				cin >> nomer;
				if ((nomer < 0) || (nomer >= size))
					cout << "Номер объекта введен некорректно!" << endl;
			}
			time = Time::GetPointerTime(nomer);
			time->InputTime();
			cout << "Изменен "<< nomer << "-ый объект Time:" << endl;
			time->PrintTime();
			break;

		case '3':
			cout << endl << "----------Удаление указанного объекта----------" << endl;
			nomer = -1;
			size = Time::GetSize();
			while ((nomer < 0) || (nomer >= size))
			{
				cout << "Введите номер объекта: ";
				cin >> nomer;
				if ((nomer < 0) || (nomer >= size))
					cout << "Номер объекта введен некорректно!" << endl;
			}
			Time::DeleteTime(nomer);
			cout << "Удален "<< nomer << "-ый объект Time:" << endl;
			break;

		case '4':
			cout << endl << "----------Вывод на экран всех объектов----------" << endl;
			Time::ShowArrayTime();
			break;

		default:
			cout << "Нет такой команды!" << endl;
			break;
		}
	}
}