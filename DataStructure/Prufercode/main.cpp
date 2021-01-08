#include<iostream>
#include<fstream>

using namespace std;
#define MAX 100000
int m[MAX + 1][2];//luu canh

int FindVertice_has_deg_1(int a[1000],int n) {
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1) {
			a[i]--;
			return i;
		}
	}
}
void FindPruferCode(int m[MAX + 1][2], int a[1000], int n) {
	//index min co dinh degree 1 
	int k = FindVertice_has_deg_1(a,n);
	
	//in prufer code
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			if (m[i][j] == k) {
				cout << m[i][(j + 1) % 2] << " ";
				//giam bac
				a[m[i][(j + 1) % 2]]--;
				//xoa canh bang cach gan 2 gia tri do =-1
				m[i][j] = -1;
				m[i][(j + 1) % 2] = -1;
			}			
		}
	}

}
int main() {
	ifstream Filein;
	Filein.open("D:\\File\\in.txt", ios_base::in);
	int k;
	Filein >> k;//number of edge
	int a[MAX] = { 0 };
	int n = 0;
	while (!Filein.eof()) {
		for (int i = 0; i < 2; i++) {
			Filein >> m[n][i];
			int x = m[n][i];
			a[x]++;//save degree of m[n][i]
		}
		n++;
	}
	Filein.close();
	//////tim prufer code
	for (int i = 0; i < n - 1; i++) {
		FindPruferCode(m, a, n);
	}
	system("pause");
	return 0;
}
