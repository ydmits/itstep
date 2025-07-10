// Matrix.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	// инициализация двумерного массива
	int matrix[2][3] = { 1, 2, 3, 4 };

	// вывод матрицы
	// стандартно используется i - перебор по строкам, j - перебор по столбцам
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}

	// генерация матрицы случайными значениями
	int user_matrix[10][10];
	int rows, columns;
	cout << "Введите количество строк и столбцов матрицы - ";
	cin >> rows >> columns;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			user_matrix[i][j] = rand() % 11 + (-5);
		}
	}
	// вывод сгенерированной матрицы
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << user_matrix[i][j] << "\t";
		}
		cout << endl;
	}

	// сумма положительных элементов матрицы
	cout << "------------------------Task new----------------\n";
	int count_positive = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (user_matrix[i][j] > 0)
			{
				count_positive++;
			}
		}
		
	}
	cout << "Количество положительных элементов - " << count_positive << endl;
	

	// подсчитать сумму каждого столбца
	cout << "------------------------Task new----------------\n";
	for (int j = 0; j < columns; j++)
	{
		int sum = 0;
		for (int i = 0; i < rows; i++)
		{
			sum += user_matrix[i][j];
		}
		cout << "Сумма " << j << "-го столбца - " << sum << endl;

	}

	// сумма 2-го столбца
	cout << "------------------------Task new----------------\n";
	if (2 > columns)
	{
		cout << "Количество столбцов меньше 2" << endl;
	}
	else
	{
		int sum = 0;
		for (int i = 0; i < rows; i++)
		{
			sum += user_matrix[i][1]; // фиксируем j=1 (второй столбец)
		}
		cout << "Сумма 2-го столбца - " << sum << endl;
	}

	//Написать программу, которая в двумерном массиве
	//	находит минимальный элемент каждой строки.
	cout << "------------------------Task new----------------\n";
	for (int i = 0; i < rows; i++)
	{
		int min = user_matrix[i][0]; // считаем, что первый элемент находится на первом месте в строке
		for (int j = 1; j < columns; j++)
		{
			if (user_matrix[i][j] < min)
			{
				min = user_matrix[i][j];
			}
			
		}
		cout << "Минимальный элемент " << i << "-й строки - " << min << endl;
	}

	// заменить 2 элемент соответствующего столбца на количество отрицательных элементов столбца
	cout << "------------------------Task new----------------\n";
	for (int j = 0; j < columns; j++)
	{
		int count_negative = 0;
		for (int i = 0; i < rows; i++)
		{
			if (user_matrix[i][j] < 0)
			{
				count_negative++;
			}
		}
		// производим замену
		user_matrix[2][j] = count_negative;
	}

	// выводим измененную матрицу
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << user_matrix[i][j] << "\t";
		}
		cout << endl;
	}
	
	// поменять местами минимальный и максимальный элемент матрицы
	cout << "------------------------Task new----------------\n";
	int max, min, max_row, max_col, min_row, min_col;
	min = max = user_matrix[0][0];
	max_row = max_col = min_row = min_col = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (user_matrix[i][j] > max)
			{
				max = user_matrix[i][j];
				max_row = i;
				max_col = j;
			}
			if (user_matrix[i][j] < min)
			{
				min = user_matrix[i][j];
				min_row = i;
				min_col = j;
			}
		}
	}
	// вывод минимального и максимального
	cout << max << " - " << max_row << ", " << max_col << endl;
	cout << min << " - " << min_row << ", " << min_col << endl;
	// производим обмен
	user_matrix[max_row][max_col] = min;
	user_matrix[min_row][min_col] = max;
	// выводим измененную матрицу
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << user_matrix[i][j] << "\t";
		}
		cout << endl;
	}




   
	system("pause");
}

