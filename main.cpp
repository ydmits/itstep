// Counter.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Counter.h"

using namespace std;

int main()
{

	Counter counter1;
	cout << counter1.getvalue() << endl;
	counter1.increment();
	counter1.increment();
	cout << counter1.getvalue() << endl;
	counter1.decrement();
	cout << counter1.getvalue() << endl;

	cout << "------------------------------------------------\n";
	Counter counter2(20);
	cout << counter2.getvalue() << endl;
	counter2.increment();
	counter2.increment();
	cout << counter2.getvalue() << endl;
	counter2.decrement();
	cout << counter2.getvalue() << endl;




	system("pause");

}
