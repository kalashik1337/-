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
        cout << "��� �������� �����������, ������� ��������� ���������: " << endl;

        cout << "a = " << a << endl;

        cout << "b = " << b << endl << endl;

    }

    void setAB()
    {
        cout << "������� ����� ����� �: ";
        cin >> a;
        cout << "������� ����� ����� b: ";
        cin >> b;
    }

    void getAB()
    {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl << endl;
    }

    ~AB()
    {
        cout << "��� �������� ����������" << endl;
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
