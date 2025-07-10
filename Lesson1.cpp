// Lesson1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

class Person
{
private:
    char* firstName;
    char* lastName;
    int age;

public:

    Person();
    void personShow();
    ~Person();
      
};

Person::Person() {
    cout << "Constructor is runnig!!!\n";
    char str[128];
    cout << "Enter name:";
    cin >> str;
    firstName = new char[strlen(str) + 1];
    strcpy_s(firstName, strlen(str) + 1, str);
    cout << "Enter lastname:";
    cin >> str;
    lastName = new char[strlen(str) + 1];
    strcpy_s(lastName, strlen(str) + 1, str);
    cout << "Enter age:";
    cin >> age;
}

Person::~Person()
{
    cout << "Destructor is runnig!!!\n";
    if (firstName) delete[] firstName;
    if (lastName) delete[] lastName;

}

void Person::personShow()
{
    cout << this->firstName << " " << this->lastName << ", age - " << this->age << endl;
}

inline int sum(int a, int b)
{
    return a + b;
}

int main()
{

    {
    Person Vasya;

    Vasya.personShow();

    Person Fedya;
    Fedya.personShow();

    }
  

    system("pause");
    
}
