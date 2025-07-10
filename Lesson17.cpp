// Lesson17.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

struct user
{
    char name[20];
    int age;
};

int main()
{
    setlocale(LC_ALL, "rus");
    // use C
    int a = 10;
    printf("a=%d\n", a);

    // input data
    puts("Enter a:");
    scanf_s("%d", &a);
    printf("a=%d\n", a);

    // функции С
    char str[128];
    cin.ignore(cin.rdbuf()->in_avail());
    puts("Enter string:");
    gets_s(str, 128);
    printf("str = %s\n", str);

    // работа с текстовым файлом
    FILE* fptr;
    fopen_s(&fptr,"test.txt", "w");
    fputs("Пробирается медведь сквозь густой валежник.\n", fptr);
    fputs("Стали птицы громче петь. И расцвел подснежник.\n", fptr);
    fclose(fptr);

    // добавление информации в файл
    fopen_s(&fptr, "test.txt", "a");
    fputs("С.Я.Маршак\n", fptr);
    fclose(fptr);

    // чтение данных
    fopen_s(&fptr, "test.txt", "r");
    while (fgets(str, 128, fptr))
    {
        puts(str);
    }
    fclose(fptr);

    // чтения файла посимвольно
    char ch;
    fopen_s(&fptr, "test.txt", "r");
    while (!feof(fptr))
    {   
        ch = fgetc(fptr);
        putchar(ch);
    }
    fclose(fptr);

    // работа с двоичными файлами
    a = 100;
    float pi = 3.14;
    fopen_s(&fptr, "test.dat", "w");
    fprintf(fptr, "%d %f", a, pi);
    fclose(fptr);

    // чтение этого файла
    int b;
    float x;
    fopen_s(&fptr, "test.dat", "r");
    fscanf_s(fptr, "%d%f", &b, &x);
    fclose(fptr);
    printf("b = %d, x = %f", b, x);

    // работа со структурами
    user student1 = { "nick", 25 };
    /*fopen_s(&fptr, "users.dat", "w");
    fprintf(fptr, "%s %d", student1.name, student1.age);
    fclose(fptr);

    user student2;
    fopen_s(&fptr, "users.dat", "r");
    fscanf_s(fptr, "%s %d", &student2.name, &student2.age);
    fclose(fptr);

    printf("name - %s, age - %d", student2.name, student2.age);*/

    fopen_s(&fptr, "users.dat", "w");
    fwrite(&student1, sizeof(user), 1, fptr);
    fclose(fptr);

    user student2;
    fopen_s(&fptr, "users.dat", "r");
    fread(&student2, sizeof(user), 1, fptr);
    fclose(fptr);
    printf("name - %s, age - %d", student2.name, student2.age);


   



}
