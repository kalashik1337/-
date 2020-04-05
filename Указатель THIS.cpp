#include <iostream>

using namespace std;

class SetGetData
{
    char str[128];
    int number;

public:
    void setData()
    {
        cout << "¬ведите строку: ";
        cin.getline(str, 128);
        cout << "¬ведите целое число: ";
        cin >> number;
    }

    void getData()
    {
        cout << "\n" << this->str  << this->number << endl << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "rus");

    SetGetData object;
    object.setData();
        system("cls");
    object.getData();

return 0;
}
