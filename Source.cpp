#include <iostream>
#include <iomanip>

using namespace std;


struct phoneuser
{
    char name[30];
    int age;
    char adress[30];
    char phone_number[10];
};

void readBD(phoneuser* BD, int& size);
void writeBD(phoneuser* BD, int size);
void addBD(phoneuser* BD, int& size);
void showBD(phoneuser* BD, int size);
void sortBD(phoneuser* BD, int size);
void user_sort(phoneuser* BD,int size);
void phone_sort(phoneuser* BD, int size);
void adress_sort(phoneuser* BD, int size);
void deleteBD(phoneuser* BD, int& size);



int main()
{
    
    phoneuser BD[100];

    int size = 0;

    while (true)
    {
        system("cls");
        cout << "Make your choice:" << endl;
        cout << "1. Read BD" << endl;
        cout << "2. Save BD" << endl;
        cout << "3. Add into BD" << endl;
        cout << "4. Show BD" << endl;
        cout << "5. Delete BD" << endl;
        cout << "6. Sort BD" << endl;
        cout << "7. Exit" << endl;
        int key;
        cin >> key;
        switch (key)
        {
        case 1: readBD(BD, size); break;
        case 2: writeBD(BD, size); break;
        case 3: addBD(BD, size); break;
        case 4: showBD(BD, size); break;
        case 5: deleteBD(BD, size); break;
        case 6: sortBD(BD, size); break;
        case 7: exit(0);
        }

    }
}


void readBD(phoneuser* BD, int& size)
{
    FILE* fptr;
    fopen_s(&fptr, "usersBD.dat", "r");

    int i = 0;
    while (fread(&BD[i], sizeof(phoneuser), 1, fptr))
    {
      
        i++;
        size++;
    }
    fclose(fptr);
    cout << "Data was read successful!\n";
    system("pause");

}

void writeBD(phoneuser* BD, int size)
{
    FILE* fptr;
    fopen_s(&fptr, "usersBD.dat", "w");
    for (int i = 0; i < size; i++)
    {
        fwrite(&BD[i], sizeof(phoneuser), 1, fptr);
    }
    fclose(fptr);
    cout << "Data was saved successful!\n";
    system("pause");


}

void addBD(phoneuser* BD, int& size)
{
    cout << "Enter user name:";
    cin >> BD[size].name;
    cout << endl;
    cout << "Enter user age:";
    cin >> BD[size].age;
    cout << endl;
    cout << "Enter user adress:";
    cin >> BD[size].adress;
    cout << endl;
    cout << "Enter user phone number:";
    cin >> BD[size].phone_number;

    size++;
}

void showBD(phoneuser* BD, int size)
{
    system("cls");
    cout << "=========================================================================================================\n";
    cout << "|\tName\t|\tAge\t|\t\t Adress\t\t|\t\tPhone number\t\t|\n";
    cout << "=========================================================================================================\n";

    for (int i = 0; i < size; i++)
    {
        cout << "|" << setw(15) << BD[i].name << "|" << setw(15) << BD[i].age << "|" << setw(31) << BD[i].adress << "|" << setw(39) << BD[i].phone_number << "|\n";
        cout << "=========================================================================================================\n";
    }
    system("pause");
}

void sortBD(phoneuser* BD, int size)
{
    system("cls");
    cout << "Make your choice:" << endl;
    cout << "1. Sort user name" << endl;
    cout << "2. Sort phone number" << endl;
    cout << "3. Sort adress" << endl;
    cout << "4. Exit" << endl;

    int key1;
    cin >> key1;
    switch (key1)
    {
    case 1: user_sort(BD, size); break;
    case 2: phone_sort(BD, size); break;
    case 3: adress_sort(BD, size); break;
    case 4: exit(0);
    }

}

void user_sort(phoneuser* BD, int size)
{
    
    for (int i = 0; i <= size; i++)
    {
        for (int j = size - 1; j > i; j--)
        {
            if (strcmp(BD[j].name, BD[j - 1].name) < 0)
            {
              BD[size + 1] = BD[j];
              BD[j] = BD[j - 1];
              BD[j - 1] = BD[size + 1];
            }
        }
    }
 
}
void phone_sort(phoneuser* BD, int size)
{
    for (int i = 0; i <= size; i++)
    {
        for (int j = size - 1; j > i; j--)
        {
            if (strcmp(BD[j].phone_number, BD[j - 1].phone_number) < 0)
            {
                BD[size + 1] = BD[j];
                BD[j] = BD[j - 1];
                BD[j - 1] = BD[size + 1];
            }
        }
    }
}
void adress_sort(phoneuser* BD, int size)
{
    for (int i = 0; i <= size; i++)
    {
        for (int j = size - 1; j > i; j--)
        {
            if (strcmp(BD[j].adress, BD[j - 1].adress) < 0)
            {
                BD[size + 1] = BD[j];
                BD[j] = BD[j - 1];
                BD[j - 1] = BD[size + 1];
            }
        }
    }
}

void deleteBD(phoneuser* BD, int& size)
{
    system("cls");
    showBD(BD, size);
    cout << "Choose someone you will delete:";
    int index;
    cin >> index;
    if (index >= size)
    {
        cout << "Wrong index\n";
    }
    else
    {
        for (int i = index; i < size - 1; i++)
        {
            BD[i] = BD[i + 1];
        }
        size--;
    }
}