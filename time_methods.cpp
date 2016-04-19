#include "time.h"

AbstractTime** Time::Arr = NULL;
int Time::size = 0;
int Time::sizeMax = 0;

Time::Time() : Hour(0), Min(0), Sec(0)
{
	AddTime(*this);
}

Time::Time(int hour, int min=0, int sec=0) : Hour(hour), Min(min), Sec(sec)
{
	AddTime(*this);
}

Time::Time(Time &t) : Hour(t.Hour), Min(t.Min), Sec(t.Sec)
{
	AddTime(*this);
}

Time::~Time()
{
	RemoveTime(*this);
}

void Time::AddTime(Time &t)
{
	if (Arr == NULL)
	{
		sizeMax = 2;
		Arr = new AbstractTime*[sizeMax];
		for (int i = 0; i < sizeMax; i++) Arr[i] = NULL; //?
	}
	if (size == sizeMax)
	{
		sizeMax *= 2;
		AbstractTime** nArr = new AbstractTime*[sizeMax];
		for (int i = 0; i < size; i++) nArr[i] = Arr[i];
		for (int i = size; i < sizeMax; i++) nArr[i] = NULL; //?
		delete[] Arr;
		Arr = nArr;
	}
	Arr[size++] = &t;
}

void Time::RemoveTime(Time &t)
{
	if (size == 1)
	{
		delete[] Arr;
		Arr = NULL;
		size--;
		return;
	}	
	if ((size > 1) && (size - 1 <= sizeMax/3))
	{
		sizeMax /= 2;
		AbstractTime** nArr = new AbstractTime*[sizeMax];
		for (int i = 0, j = 0; i < size; i++)
			if (Arr[i] != &t)
				nArr[j++] = Arr[i];
		for (int i = size - 1; i < sizeMax; i++) nArr[i] = NULL;
		delete[] Arr;
		Arr = nArr;
	}
	else
	{
		int nomer;
		for (int i = 0; i < size; i++)
			if (Arr[i] == &t) { nomer = i; break; }
		for (int i = nomer + 1; i < size; i++)
			Arr[i-1] = Arr[i];
		Arr[size-1] = NULL;		
	}
	size--;
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

void Time::RemoveAllTime()
{
	int n = size;
	for (int i = 0; i < n; i++)
		if (Arr[size-1] != NULL)
			delete Arr[size-1];
}