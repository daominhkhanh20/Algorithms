#include<iostream>
#include<fstream>

using namespace std;

int main() {
	int m[100];
	ifstream Filein;
	Filein.open("D:\\File\\sample.txt", ios_base::in);
	int n = 0;
	while (!Filein.eof()) {
		int k;
		Filein >> k;
		m[n] = k;
		++n;
	}
	//increase

	for (int i = 0; i < n-1; i++) {
		int a = i;
		//tim vi tri co gia tri nho hon m[i]

		for (int j = i + 1; j < n; j++) {
			//tim min m[a]
			if (m[j] < m[a]) {
				a = j;
			}
		}
		//hoan doi m[a] voi gia tri m[i]
		if (a != i) {
			swap(m[i], m[a]);
		}
		cout << m[i] <<" ";
	}

	system("pause");
	return 0;
}