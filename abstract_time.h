#include <iostream>
using namespace std;

class AbstractTime 
{
public:
	virtual ~AbstractTime() {};
	virtual void InputTime() = 0;
	virtual void PrintTime() = 0;
};