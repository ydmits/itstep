// miniBD.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>

using namespace std;

struct user
{
    char name[20];
    int age;
};

void readBD(user* BD, int &size);
void writeBD(user* BD, int size);
void addBD(user* BD, int &size);
void showBD(user* BD, int size);

int main()
{
    // инициализация
    user BD[100];
    int size = 0;
    
    /* = {
        { "alex", 18 },
        { "max", 20 },
        { "nick", 25 },
        { "masha", 17 },
        { "sveta", 22 }
    };*/

  

    while (true)
    {
        system("cls");
        cout << "Make your choice:" << endl;
        cout << "1. Read BD" << endl;
        cout << "2. Save BD" << endl;
        cout << "3. Add into BD" << endl;
        cout << "4. Show BD" << endl;
        cout << "5. Exit" << endl;
        int key;
        cin >> key;
        switch (key)
        {
            case 1: readBD(BD, size); break;
            case 2: writeBD(BD, size); break;
            case 3: addBD(BD, size); break;
            case 4: showBD(BD, size); break;
            case 5: exit(0);
        }

    }
}


void readBD(user* BD, int &size)
{
    FILE* fptr;
    fopen_s(&fptr, "usersBD.dat", "r");

    int i = 0;
    while (fread(&BD[i], sizeof(user), 1, fptr))
    {
       //fread(&BD[i], sizeof(user), 1, fptr);
       i++;
       size++;
    }
    fclose(fptr);
    cout << "Data was read successful!!!\n";
    system("pause");

}

void writeBD(user* BD, int size)
{
    FILE* fptr;
    fopen_s(&fptr, "usersBD.dat", "w");
    for (int i = 0; i < size; i++)
    {
        fwrite(&BD[i], sizeof(user), 1, fptr);
    }
    fclose(fptr);
    cout << "Data was saved successful!!!\n";
    system("pause");


}

void addBD(user* BD, int &size)
{
    cout << "Enter user name:";
    cin >> BD[size].name;
    cout << "Enter user age:";
    cin >> BD[size].age;
    size++;
}

void showBD(user* BD, int size)
{
    system("cls");
    cout << "========================\n";
    cout << "|    name     |   age  |\n";
    cout << "========================\n";

    for (int i = 0; i < size; i++)
    {
        cout << "|" << setw(11)<< BD[i].name << "  |" << setw(8)<< BD[i].age << "|\n";
        cout << "========================\n";
    }
    system("pause");
}