#include <iostream>
#include <string.h>

using namespace std;

class child;

class schoolchild
{
    char name[16];
    char surname[16];
    int clas;
public:
    schoolchild (char*, char*, int);
    void getData();
    friend child;
};

schoolchild::schoolchild(char *n, char *s, int c)
{
    strcpy(name, n);
    strcpy(surname, s);
    clas = c;
}

void schoolchild::getData()
{
    cout << name << " " << surname << "\t" << clas << "-й класс"<< endl;
}

class child
{
public:
    void changeClas(schoolchild &, int );
    void getChangeData(schoolchild);
};

void child::changeClas(schoolchild &obj, int newCl)
{
    obj.clas = newCl;
}

void child::getChangeData(schoolchild obj)
{
    cout << obj.name << "  " << obj.surname << "\t переведен(а)  в " << obj.clas << "-й класс\n";
}

int main()
{
    setlocale(LC_ALL, "rus");


    schoolchild visotscaya  ( "Маргарита", "Высоцкая", 3);
    schoolchild semenov     ( "Александр", "Семенов", 3);

    cout << "Список учеников 3-го класса:\n";
    visotscaya.getData();
    semenov.getData();

    child transfer;

    transfer.changeClas(visotscaya, 4);
    transfer.changeClas(semenov, 4);

    cout << "\nПеревод в следующий класс:\n";
    transfer.getChangeData(visotscaya);
    transfer.getChangeData(semenov);

    cout << "\nСписок учеников 4-го класса:\n";
    visotscaya.getData();
    semenov.getData();

return 0;
}
