#include <iostream>
using namespace std;

class AbstractTime 
{
public:
	virtual ~AbstractTime() = 0;
	virtual void InputTime() = 0;
	virtual void PrintTime() = 0;
};