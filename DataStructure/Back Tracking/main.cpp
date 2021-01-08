//Print all birary n of algorithm BackTracking

#include<iostream>

using namespace std;
void printarray1(int m[100], int n) {
	for (int i = 1; i <= n; i++) {
		cout << m[i];
	}
	cout << "\n";
}
//algorithms
/*B1:thu tat ca cac truong hop ma m[1] co the nha
	m[1]=0 or m[1]=1;
 B2:ung voi moi truong hop cua m[1], ta lai thu tat ca cac truong hop cua m[2]
	tuong tu cho cac truong hop khac
*/
void thu(int m[100], int i, int n) {
	for (int j = 0; j <= 1; j++) {
		m[i] = j;
		if (i == n)
			printarray1(m, n);
		else
			thu(m, i + 1, n);
	}
}

int main() {
	int m[100], n;
	cin >> n;
	thu(m, 1, n);
	system("pause");
	return 0;
}