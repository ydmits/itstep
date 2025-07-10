#include "Counter.h"
#include <iostream>

Counter::Counter()
{
	std::cout << "Constructor is running!!!\n";
	value = 0;
}

Counter::Counter(int value)
{
	this->value = value;
}

Counter::~Counter()
{
	std::cout << "Destructor is running!!!\n";
}

void Counter::increment()
{
	value++;
}

void Counter::decrement()
{
	value--;
}
void Counter::setValue(int value)
{
	this->value = value;
}
int Counter::getvalue()
{
	return value;
}


