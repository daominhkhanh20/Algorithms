#include<iostream>
#include<fstream>

using namespace std;
void insertion(int m[],int n) {
	for (int i = 1; i < n; i++) {
		int temp = m[i];
		int j = i;
		while (j >0 && m[j-1] > temp) {
			m[j] = m[j - 1];
			j = j - 1;
		}
		m[j] = temp;
	}
}
int main() {
	int m[100];
	ifstream Filein;
	Filein.open("D:\\File\\sample.txt", ios_base::in);
	int n=0;
	while (!Filein.eof()) {
		int k;
		Filein >> k;
		m[n] = k;	
		++n;
	}
	insertion(m,n);

	for (int i = 0; i < n; i++) {
		cout << m[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}