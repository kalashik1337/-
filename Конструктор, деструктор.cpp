# include <iostream>
using namespace std;

class
{
    private:
    int a;
    int b;

    public:
    AB(int A, int B)
    {
        a = A;
        b = B;
        cout << "“ут сработал конструктор, который принимает параметры: " << endl;

        cout << "a = " << a << endl;

        cout << "b = " << b << endl << endl;

    }

    void setAB()
    {
        cout << "¬ведите целое число а: ";
        cin >> a;
        cout << "¬ведите целое число b: ";
        cin >> b;
    }

    void getAB()
    {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl << endl;
    }

    ~AB()
    {
        cout << "“ут сработал деструктор" << endl;
    }
};

int main()
{
setlocale(LC_ALL, "rus");

AB obj1(100, 100);

obj1.setAB();
obj1.getAB();

AB obj2(200, 200);
}
