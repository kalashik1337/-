#include "stdafx.h"
#include <iostream>
#include "stdio.h"
#include "stdlib.h"
using namespace std;

struct scan_info {
    char model[25]; // наименование модели
    int price;  // цена
    double x_size;  // горизонтальный размер области сканирования
    double y_size; // вертикальный размер области сканирования
    int optr; // оптическое разрешение
    int grey; // число градаций серого
};
int ShowMenu();
void CreateFile(int* n);
void ViewFile();
void D(int* n);

int ShowMenu() {
    setlocale(0, "rus");
    char ch = '\0';
    cout << "1 : Создайте файл\n";
    cout << "2 : Просмотр файлов\n";
    cout << "3 : Добавить запись\n";
    cout << "4 : Выход\n";
    ch = getchar();
    return atoi(&ch); // строка в целое число
}
int main() {
    int n;
    while (1) {
        switch (ShowMenu()) {
        case 1: CreateFile(&n); break;
        case 2: ViewFile(); break;
        case 3: D(&n); break;
        case 4: return 0;
        default: break;
        };
    };
}
void CreateFile(int* n) {
    FILE* data;
    char* db = "file.bin";
    data = fopen(db, "wb");
    do {
        cout << endl << "Введите количество записей (6-8): ";
        cin >> *n;
    } while ((*n < 6) || (*n > 8));
    scan_info scan;
    fwrite(&n, sizeof(n), 1, data);
    for (int i = 1; i <= *n; i++) {
        cout << "Сканер N: " << i << endl;
        cout << "Модель: ";
        cin >> scan.model;
        cout << "Цена: ";
        cin >> scan.price;
        cout << "Горизонтальная размер области сканирования: ";
        cin >> scan.x_size;
        cout << "Вертикальный размер области сканирования: ";
        cin >> scan.y_size;
        cout << "Оптическое разрешение: ";
        cin >> scan.optr;
        cout << "Число градаций серого: ";
        cin >> scan.grey;
        cout << endl;
        fwrite(&scan, sizeof(scan), 1, data);
    };
    fclose(data);
    cout << "Файл  file.bin  создан." << endl << endl;
    getchar();
    return;
}

void ViewFile() {
    FILE* data1;
    char* db1 = "file.txt";
    data1 = fopen(db1, "rb");
    if (data1 == NULL) {
        cout << "Нельзя открыть файл для чтения." << endl << endl;
        getchar();
        return;
    };
    int n;
    // прочитали количество записей в файле
    fread(&n, sizeof(n), 1, data1);
    //  выводим на экран через массив
    cout << endl << "Количество сканеров: " << n << endl << endl;
    scan_info* s = new scan_info[n];
    for (int g = 0; g < n; g++)
        fread(&s[g], sizeof(scan_info), 1, data1);
    for (int g = 0; g < n; g++) {
        cout << "Сканер N: " << g + 1 << endl;
        cout << "Модель: " << s[g].model << endl;
        cout << "Цена: " << s[g].price << endl;
        cout << "Горизонтальный размер области сканирования: " << s[g].x_size << endl;
        cout << "Вертикальный размер области сканирования: " << s[g].y_size << endl;
        cout << "Оптическое разрешение: " << s[g].optr << endl;
        cout << "Число градаций серого: " << s[g].grey << endl;
        cout << endl;
    };
    fclose(data1);
    cout << endl << endl;
    getchar();
    return;
}

void D(int* n) {
    FILE* data;
    char* db = "file.bin";
    data = fopen(db, "ab+");
    if (data == NULL) {
        cout << "Не удалось открыть файл для добавления." << endl << endl;
        return;
    };
    int k;
    do {
        cout << endl << "Введите количество дополнительных записей(2-3) ";
        cin >> k;
    } while ((k < 2) || (k > 3));
    n = n + k;
    scan_info scan;
    fwrite(&n, sizeof(n), 1, data);
    for (int i = 1; i <= k; i++) {
        cout << "Дополнительный сканер N: " << i << endl;
        cout << "Модель: ";
        cin.clear(); cin.sync(); gets(scan.model);
        cout << "Цена: ";
        cin >> scan.price;
        cout << "Горизонтальная размер области сканирования: ";
        cin >> scan.x_size;
        cout << "Вертикальный размер области сканирования: ";
        cin >> scan.y_size;
        cout << "Оптическое разрешение: ";
        cin >> scan.optr;
        cout << "Число градаций серого: ";
        cin >> scan.grey;
        cout << endl;
        fwrite(&scan, sizeof(scan), 1, data);
    }

    fclose(data);
    cout << "Запись добавлена." << endl << endl;
    getchar();
    return;
}