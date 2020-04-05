#include <iostream>
using namespace std;

class
{
private:
    int day,
        month,
        year;
public:
    void message()
    {
        cout << "\nwebsite: cppstudio.comntheme: Classes and Objects in C + +\n";
    }
    void setDate(int date_day, int date_month, int date_year)
    {
        day   = date_day;
        month = date_month;
        year  = date_year;
    }
    void getDate()
    {
        cout << "Date: " << day << "." << month << "." << year << endl;
    }
};

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "rus");
    int day, month, year;
    cout << "¬ведите текущий день мес€ц и год!\n";
    cout << "день: ";     cin >> day;
    cout << "мес€ц: ";    cin >> month;
    cout << "год: ";  cin >> year;
    CppStudio objCppstudio;
    objCppstudio.message();
    objCppstudio.setDate(day, month, year);
    objCppstudio.getDate();
    system("pause");
    return 0;
}
