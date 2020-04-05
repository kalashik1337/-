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
    cout << name << " " << surname << "\t" << clas << "-� �����"<< endl;
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
    cout << obj.name << "  " << obj.surname << "\t ���������(�)  � " << obj.clas << "-� �����\n";
}

int main()
{
    setlocale(LC_ALL, "rus");


    schoolchild visotscaya  ( "���������", "��������", 3);
    schoolchild semenov     ( "���������", "�������", 3);

    cout << "������ �������� 3-�� ������:\n";
    visotscaya.getData();
    semenov.getData();

    child transfer;

    transfer.changeClas(visotscaya, 4);
    transfer.changeClas(semenov, 4);

    cout << "\n������� � ��������� �����:\n";
    transfer.getChangeData(visotscaya);
    transfer.getChangeData(semenov);

    cout << "\n������ �������� 4-�� ������:\n";
    visotscaya.getData();
    semenov.getData();

return 0;
}
