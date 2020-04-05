#include <iostream>
using namespace std;

class MyArray
{
    int *numbers;
    int sizeOfArray;
public:
    MyArray()
    {
        sizeOfArray = 0;
        numbers = 0;
    }

    MyArray(int size)
    {
        sizeOfArray = size;
        numbers = new int [sizeOfArray];
        for(int i = 0; i < sizeOfArray; i++)
        {
            numbers[i] = 0;
        }
    }

    ~MyArray()
    {
        delete [] numbers;
    }

    void showData()
    {
        for(int i = 0; i < sizeOfArray; i++)
        {
            cout << numbers[i] << " | ";
        }
    cout << endl << endl;
    }


    int &operator[](int j)
    {
        return numbers[j];
    }


    MyArray& operator=( MyArray &arrInt2 )
    {
        delete [] numbers;

        sizeOfArray = arrInt2.sizeOfArray;

        numbers = new int [sizeOfArray];
        for (int i = 0; i < sizeOfArray; i++)
        {
            numbers[i] = arrInt2.numbers[i];
        }

        return *this;
    }

    friend bool operator ==( MyArray &arrInt, MyArray &arrInt2 );
};

bool operator == ( MyArray &arrInt, MyArray &arrInt2 )
		{
    if(arrInt.sizeOfArray != arrInt2.sizeOfArray)
    {
        cout << "В массивах разное количество элементов\n";
        return 0;
    }
    else
    {
        for (int i = 0; i < arrInt.sizeOfArray; i++)
        {
            if(arrInt.numbers[i] != arrInt2.numbers[i])
            {
                cout << "Значения массивов не равны\n";
                return 0;
            }
        }
    }
return 1;
}

int main()
{
    setlocale(LC_ALL, "rus");

    MyArray ArrayInt(5);
    ArrayInt[0] = 1;
    ArrayInt[1] = 2;
    ArrayInt[2] = 3;
    ArrayInt[3] = 4;
    ArrayInt[4] = 5;
    cout << "Массив ArrayInt:  ";
    ArrayInt.showData();

    MyArray ArrayInt2(5);
    ArrayInt2[0] = 11;
    ArrayInt2[1] = 22;
    ArrayInt2[2] = 33;
    ArrayInt2[3] = 44;
    ArrayInt2[4] = 55;
    cout << "Массив ArrayInt2: ";
    ArrayInt2.showData();

    if(ArrayInt == ArrayInt2){
        cout << "Массив ArrayInt равен массиву ArrayInt2\n";
    }
    else {
        ArrayInt = ArrayInt2;
    }
    cout << "Массив ArrayInt после копирования:  ";
    ArrayInt.showData();

    MyArray ArrayInt3(10);
    cout << "Массив ArrayInt3: ";
    ArrayInt3.showData();
    ArrayInt3 = ArrayInt;
    cout << "Массив ArrayInt3 после копирования: \n";
    ArrayInt3.showData();

    return 0;
}
