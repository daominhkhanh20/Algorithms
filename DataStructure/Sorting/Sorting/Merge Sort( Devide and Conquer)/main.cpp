#include<iostream>
#include<fstream>
using namespace std;

void Merge(int m[], int first, int a, int end) {
	//intilize temporary array
	int k[50],h[50];
	//copy all elements to the temporary array
	for (int i = 0; i <= a - first; i++) {
		k[i] = m[first + i];
	}
	for (int i = 0; i < end - a; i++) {
		h[i] = m[a + i+1];//add 1 because m[a] belongs to k[]
	}
	int i = 0,j=0,c=first;
	//Merge 2 subarray to m[]
	while (i <= a - first && j < end - a) {
		if (k[i] <= h[j]) {
			m[c] = k[i];
			i++;
		}
		else {
			m[c] = h[j];
			j++;
		}
		c++;
	}

	//int this case: the remaining element of k[] or h[] isn't added to the m[]
	while (i <= a - first) {
		m[c] = k[i];
		i++;
		c++;
	}

	while (j < end - a) {
		m[c] = h[j];
		j++;
		c++;
	}


}
void MergeSort(int m[], int first, int end) {
	if (first < end) {
		//the devide point
		int a = (first + end) / 2;

		//Devide and Conquer
		//devide 2 halves
		MergeSort(m, first, a);
		MergeSort(m, a + 1, end);

		//merge 2 halves
		Merge(m, first, a, end);
	}
}
int main() {
	int m[100];
	ifstream Filein;
	Filein.open("D:\\File\\sample1.txt", ios_base::in);
	int n = 0;
	while (!Filein.eof()) {
		int k;
		Filein >> k;
		m[n] = k;
		++n;
	}
	//increase
	MergeSort(m, 0, n);

	for (int i = 0; i < n; i++) {
		cout << m[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}