#include "abstract_time.h"
#include <iostream>
using namespace std;

class Time : public AbstractTime
{
	//static int Count;
	int Hour;
	int Min;
	int Sec;
public:
	Time();
	Time(int, int, int);
	Time(Time &);
	~Time();
	void InputTime();
	void PrintTime();

}