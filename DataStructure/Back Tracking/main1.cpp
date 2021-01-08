//Ananlysis n into sum of positive integers

#include<iostream>

using namespace std;

void PrintResult(int m[100], int n) {
	int i;
	for (i = 1; i < n; i++) {
		cout << m[i] << " + ";
	}
	cout << m[i] << "\n";
}

void test(int m[100], int x[100], int n, int i) {
	for (int j = m[i - 1]; j <= (n - x[i - 1]) / 2; j++) {
		m[i] = j;
		x[i] = x[i - 1] + j;
		test(m, x, n, i + 1);
	}
	m[i] = n - x[i - 1];

	PrintResult(m, i);
}
int main() {
	int m[100], x[100], n;
	m[0] = 1; x[0] = 0;
	cin >> n;
	test(m, x, n, 1);
	system("pause");
	return 0;
}