#include <iostream>
using namespace std;

int main()
{
	const int n = 8; 
	int m[n] = { 4, -5, 6, 7, 8, 9, -10, 11 }; 
	int sum = 0; 
	int m1[2]; 
	int j = 0;
	int sum2 = 0; 

	cout << "iskhodnyy massiv " << endl;


	for (int i = 0; i < n; i++)
		cout << "m[" << i << "] = " << m[i] << endl;

	
	for (int i = 0; i < n; i++)
		if (m[i] < 0)
			sum += m[i];
	cout << " summa otritsatel elementov = " << sum << endl;


	for (int i = 0; i < n; i++)
		if (m[i] < 0) {
			m1[j] = i;
			cout << "indeks " << j + 1 << " = " << m1[j] << endl;
			j = j + 1;
		}

	
	for (int i = m1[0] + 1; i < m1[1]; i++)
		sum2 += m[i];
	cout << " summa polozhitel elementov = " << sum2 << endl;

	return (0);
}