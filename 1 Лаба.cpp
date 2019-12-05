#include<iostream>
using namespace std;
int main() {
    float a[10], sum = 0, proiz = 1;
    int i, j, n, k, l;
    cout << "Vvedite elementy massiva";
    for (i = 0; i < n; i++) cin >> a[i] >> "\n";
    float max = a[0], min = a[0];
    for (i = 0; i <= n; i++) {
        if (a[i] < 0) sum += a[i];
        if (max > a[i]) k = i;
        if (min < a[i]) l = i;
    };
    cout << "\nsum=" << sum << "\n";
    while (i <= n) {
        if (l < k) for (i = l; i <= k; i++) proiz *= a[i]; else for (i = k; i <= l; i++) proiz *= a[i];
    };
    cout << "\nproiz=" << proiz;
    for (i = 0; i <= n - 1; i++)
        for (j = i + 1; j <= n; i++)
            if (a[i] > a[j]) {
                sum = a[i];
                a[i] = a[j];
                a[j] = sum;
            }
    for (i = 0; i <= n; i++) { cout << "\na[i]=" << a[i] << "\n"; };
    system("pause");
    return 0;
}