// Points.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Point.h"

using namespace std;

int main()
{
    Point p1(1, 1);
    p1.showPoint();

    Point line[2];
    for (int i = 0; i < 2; i++)
    {
        line[i].showPoint();
    }

    Point triangle[3] =
    {
        Point(1, 1),
        Point(2, 2),
        Point(1, 3)
    };

    for (int i = 0; i < 3; i++)
    {
        triangle[i].showPoint();
    };


    system("pause");
}

