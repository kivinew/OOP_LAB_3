#include "time.h"

void main()
{
	setlocale(LC_ALL, "Russian");
	int nomer;
	char c = 0;
	while (c != '0')
	{
		cout << "---------------������� ����---------------" << endl;
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
			cout << endl << "-----�������� ������ �������-----" << endl;
			Time::AddTime();
			nomer = Time::GetSize();
			cout << "������ "<< nomer << "-�� ������ Time:" << endl;
			Time::ShowTime(nomer);
			break;

		case '2':

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