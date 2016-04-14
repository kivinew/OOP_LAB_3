#include "time.h"

void main()
{
	setlocale(LC_ALL, "Russian");
	AbstractTime* time;
	int nomer, size;
	char c = 0;
	while (c != '0')
	{
		cout << endl << "---------------������� ����---------------" << endl;
		cout << "1. �������� ������ �������" << endl;
		cout << "2. ���� ����� �������� ��� ���������� �������" << endl;
		cout << "3. �������� ���������� �������" << endl;
		cout << "4. ����� �� ����� ���� ��������" << endl;
		cout << "0. �����" << endl;
		cout << "������� ����� �������: ";
		cin >> c;
		switch (c)
		{
		case '0':
			break;	

		case '1':
			cout << endl << "----------�������� ������ �������----------" << endl;
			Time::AddTime();
			nomer = Time::GetSize() - 1;
			cout << "������ "<< nomer << "-�� ������ Time:" << endl;
			time = Time::GetPointerTime(nomer);
			time->PrintTime();
			break;

		case '2':
			cout << "-----���� ����� �������� ��� ���������� �������-----" << endl;
			nomer = -1;
			size = Time::GetSize();
			while ((nomer < 0) || (nomer >= size))
			{
				cout << "������� ����� �������: ";
				cin >> nomer;
				if ((nomer < 0) || (nomer >= size))
					cout << "����� ������� ������ �����������!" << endl;
			}
			time = Time::GetPointerTime(nomer);
			time->InputTime();
			cout << "������� "<< nomer << "-�� ������ Time:" << endl;
			time->PrintTime();
			break;

		case '3':

			break;

		case '4':

			break;

		default:
			cout << "��� ����� �������!" << endl;
			break;
		}
	}
}