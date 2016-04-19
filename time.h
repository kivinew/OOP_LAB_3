#include "abstract_time.h"
#include <iostream>
using namespace std;

class Time : public AbstractTime
{
	int Hour;
	int Min;
	int Sec;
	static AbstractTime** Arr;
	static int size;
	static int sizeMax;
	static void AddTime(Time &t);
	static void RemoveTime(Time &t);
public:
	Time();
	Time(int, int, int);
	Time(Time &);
	~Time();
	void InputTime();
	void PrintTime();
	static int GetSize();
	static AbstractTime* GetPointerTime(int n);
	static void ShowArrayTime();
	static void RemoveAllTime();
};