// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	//// определяем константу для размера массива
	//const int SIZE = 10;
	//// объявляем целочисленны массив на 10 элементов (выделяем память)
	//int arr[SIZE];

	//// размер, определенный пользователем
	//int userSize;
	//setlocale(LC_ALL, "rus");
	//// ввод массива
	//cout << "Введите количество студентов: ";
	//cin >> userSize;
	//for (int i = 0; i < userSize; i++)
	//{
	//	cout << "Введите оценку " << i + 1 << "-го студента: ";
	//	cin >> arr[i];
	//}

	//// вывод массива
	//for (int i = 0; i < userSize; i++)
	//{
	//	cout << "arr[" << i << "] - " << arr[i] << endl;
	//}

	// объявление массива с инициализацией
	//int arr2[5] = { 1, 6, 4, 9, 4 };
	//int arr3[5];

	//// массив из случайных значений
	//srand(time(NULL));
	//for (int i = 0; i < 5; i++)
	//{
	//	arr3[i] = rand() % 10;
	//}

	// найти сумму отрицательных элементов массива
	int arr4[] = { -1, -2, -3, -5, -7, -8, -9, -4 }; // s - -13
	int sum = 0;
	for (int i = 0; i < 8; i++)
	{
		if (arr4[i] < 0) {
			sum += arr4[i];
		}
	}
	cout << "sum - " << sum << endl;
	// найти произведение положительных элементов массива
	int prod = 1, count = 0;
	for (int i = 0; i < 8; i++)
	{
		if (arr4[i] > 0) {
			prod *= arr4[i];
			count++;
		}
	}

	system("chcp 1251");
	(count != 0) ? (cout << "prod - " << prod << endl) : (cout << "Нет положительных элементов" << endl);

	// копирование элементов массива
	int arr5[8];
	for (int i = 0; i < 8; i++)
	{
		arr5[i] = arr4[i];
	}

	cout << &arr4 << endl;

	int a = 10;
	cout << "Значение а - " << a << ", адрес памяти - " << &a << endl;


	// максимальная, минимальная температура за неделю (значения температуры хранятся в массиве)
	double arr6[] = { 1, -2, -3.5, -7.8, -15.4, -18.2, -15.5 };
	// считаем минимальной (максимальной) температурой первое значение массива
	double min, max;
	int minDay = 0, maxDay = 0;
	min = max = arr6[0];
	for (int i = 0; i < 7; i++)
	{
		if (max < arr6[i]) 
		{
			max = arr6[i];
			maxDay = i;
		}
		if (min > arr6[i])
		{
			min = arr6[i];
			minDay = i;
		}
	}
	cout << "max - " << max << ", maxDay - " << maxDay + 1 << endl;
	cout << "min - " << min << ", minDay - " << minDay + 1 << endl;

	// Задан массив с диаметрами ядер, необходимо отобрать ядра для заданного диаметра пушки с допуско +- 2
	// генерируем массив из диапазона от 5 до 15
	srand(time(NULL));
	double bomb[20];
	for (int i = 0; i < 20; i++)
	{
		bomb[i] = (rand() % 100) / 10.0 + 5;
	}

	for (int i = 0; i < 20; i++)
	{
		cout << bomb[i] << "\t";
	}
	cout << endl;

	// отбираем ядра и кладем в новый ящик
	double bomb2[20];
	int size = 0;
	for (int i = 0; i < 20; i++)
	{
		if (bomb[i] < 10 + 2 && bomb[i] > 10 - 2)
		{
			bomb2[size++] = bomb[i];
		}
	}

	// вывод
	for (int i = 0; i < size; i++)
	{
		cout << bomb2[i] << endl;
	}
	cout << endl;



	system("pause");
	
	return 0;
}
