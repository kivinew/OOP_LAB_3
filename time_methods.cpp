#include "time.h"

AbstractTime** Time::Arr = NULL;
int Time::size = 0;

Time::Time() : Hour(0), Min(0), Sec(0)
{
	AbstractTime** tmp = new AbstractTime*[size + 1];
	for (int i = 0; i < size; i++)
		tmp[i] = Arr[i];
	tmp[size] = this;
	if (Arr != NULL) delete[] Arr;
	Arr = tmp;
	size++;
}

Time::Time(int hour, int min=0, int sec=0) : Hour(hour), Min(min), Sec(sec)
{
	AbstractTime** tmp = new AbstractTime*[size + 1];
	for (int i = 0; i < size; i++)
		tmp[i] = Arr[i];
	tmp[size] = this;
	if (Arr != NULL) delete[] Arr;
	Arr = tmp;
	size++;
}

Time::Time(Time &t) : Hour(t.Hour), Min(t.Min), Sec(t.Sec)
{
	AbstractTime** tmp = new AbstractTime*[size + 1];
	for (int i = 0; i < size; i++)
		tmp[i] = Arr[i];
	tmp[size] = this;
	if (Arr != NULL) delete[] Arr;
	Arr = tmp;
	size++;
}

Time::~Time()
{
	if (size == 1)
	{
		if (Arr != NULL) delete[] Arr;
		delete this;
		Arr = NULL;
		size--;
	}
	if (size > 1)
	{
		AbstractTime** tmp = new AbstractTime*[size - 1];
		for (int i = 0, j = 0; i < size; i++)
			if (Arr[i] != this)
				tmp[j++] = Arr[i];
		if (Arr != NULL) delete[] Arr;
		delete this;
		Arr = tmp;
		size--;
	}
}

void Time::InputTime ()
{
	int hour = -1, min = -1, sec = -1;
	while((hour < 0) || (hour >= 24))
	{
		cout << "Введите часы в диапазоне от 0 до 23: ";
		cin >> hour;
		if ((hour < 0) || (hour >= 24))
			cout << "Часы введены некорректно!" << endl;
	}
	while ((min < 0) || (min >= 60))
	{
		cout << "Введите минуты в диапазоне от 0 до 59: ";
		cin >> min;
		if ((min < 0) || (min >= 60))
			cout << "Минуты введены некорректно!" << endl;
	}
	while ((sec < 0) || (sec >= 60))
	{
		cout << "Введите секунды в диапазоне от 0 до 59: ";
		cin >> sec;
		if ((sec < 0) || (sec >= 60))
			cout << "Секунды введены некорректно!" << endl;
	}	
	Hour = hour;
	Min = min;
	Sec = sec;
	//SetTime(hour, min, sec);
}

void Time::PrintTime()
{
	if (Hour < 10) {
		cout << "0" << Hour << ":";
	} else {
		cout << Hour << ":";
	}
	if (Min < 10) {
		cout << "0" << Min << ":";
	} else {
		cout << Min << ":";
	}
	if (Sec < 10) {
		cout << "0" << Sec << endl;
	} else {
		cout << Sec << endl;
	}
}

int Time::GetSize()
{
	return size;
}

AbstractTime* Time::GetPointerTime(int n)
{
	return Arr[n];
}

void Time::ShowArrayTime()
{
	cout << "size = " << size << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "[" << i << "] ";
		Arr[i]->PrintTime();
	}
}

void Time::AddTime()
{
	AbstractTime* p = new Time();
	p->InputTime();
}

void Time::DeleteTime(int n)
{
	if ((n >= 0) && (n < size))
		delete Arr[n];
}