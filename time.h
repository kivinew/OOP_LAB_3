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
	static void AddTime();
	static void DeleteTime(int n);
};