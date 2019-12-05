#include<conio.h>
#include<iostream>
#include<iomanip>
#include<time.h>
#include<Windows.h>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int a, b;
    cout << "Введите размеры матрицы: ";
    cin >> a >> b;
    int** M = new int* [a];
    for (int i(0); i < a; i++)
        M[i] = new int[b];
    for (int i(0); i < a; i++) {
        for (int j(0); j < b; j++) {
            M[i][j] = 99 - rand() % 198;
            cout << setw(5) << M[i][j];
        }
        cout << endl;
    }
    int Zero(0), Count(a), Max(0), MaxCount(0), Max2(0), C(0);

    for (int i(0); i < a; i++) {
        for (int j(0); j < b; j++) {
            if (M[i][j] == 0)
                Zero++;
            if (C == 0) {
                Max = M[i][j];
                C++;
            }
            if (M[i][j] == Max)
                MaxCount++;
            if (MaxCount >= 2) {
                Max2 = Max;
                MaxCount = 0;
            }
            if (abs(M[i][j]) > abs(Max))
                Max = M[i][j];
        }
        if (Zero != 0) {
            Zero = 0;
            Count--;
        }
    }
    cout << endl << "Количество строк, которые не содержат ни одного нулевого элемента: " << Count << endl;
    if (Max2 == 0) cout << "Нет чисел, встречающихся более одного раза!";
    else cout << endl << "Максимальное из чисел, встречающихся в заданной матрице более одного раза: " << Max2;
    for (int i(0); i < a; i++)
        delete[] M[i];
    delete[] M;
    cout << "\n\nДля выхода нажмите любую клавишу...";
    _getch();
    return 0;
}