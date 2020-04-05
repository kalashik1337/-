#include <iostream>
using namespace std;

class FirstClass
{
protected:
    int value;
public:
    FirstClass()
    {
        value = 0;
    }

    FirstClass( int input )
    {
        value = input;
    }

    void show_value()
    {
        cout << value << endl;
    }
};

class SecondClass : public FirstClass
{
public:
    SecondClass() : FirstClass ()
    {}

    SecondClass(int inputS) : FirstClass (inputS)
    {}

    void ValueSqr ()
    {
        value *= value;
    }
};

int main()
{
    setlocale(LC_ALL, "rus");

    FirstClass F_object(3);
    cout << "value F_object = ";
    F_object.show_value();

    SecondClass S_object(4);
    cout << "value S_object = ";
    S_object.show_value();

    S_object.ValueSqr();
    cout << "квадрат value S_object = ";
    S_object.show_value();



    cout << endl;
    return 0;
}
