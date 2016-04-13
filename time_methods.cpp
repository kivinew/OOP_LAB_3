#include "time.h"

//int Time::Count = 0;

Time::Time() : Hour(0), Min(0), Sec(0)
{
	//Count++;
}

Time::Time(int hour, int min=0, int sec=0) : Hour(hour), Min(min), Sec(sec)
{
	//Count++;
}

Time::Time(Time &t) : Hour(t.Hour), Min(t.Min), Sec(t.Sec)
{
	//Count++;
}

Time::~Time()
{
	//Count--;
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