#include<iostream>
#include<fstream>

using namespace std;

void Heapify(int m[], int n, int i) {
	int largest = i;//initialize largest element as root
	int l = 2 * i + 1;//child left
	int r = 2 * i + 2;//child right

	//find index contain max value
	if (l<n&&m[l]>m[largest]) {
		largest = l;
	}
	if (r<n&&m[r]>m[largest]) {
		largest = r;
	}

	//swap parent node and child node have max value
	if (largest != i) {
		swap(m[i], m[largest]);
		Heapify(m, n, largest);
	}
}
void HeapSort(int m[], int n) {
	//build a max Heap
	for (int i = n / 2 - 1; i >= 0; i--) {
		Heapify(m, n, i);
	}


	for (int i = n - 1; i >= 0; i--) {
		swap(m[0], m[i]);
		//determine:m[i]>m[i-1]>m[i-2]>.........  (determine: muc dich)

		//find new maxvalue less than m[i] as root
		Heapify(m, i, 0);
		//i--   continue swap(m[0],m[i-1]) .....
	}
}
void PrintArr(int m[], int n) {
	for (int i = 0; i < n; i++) {
		cout << m[i] << " ";
	}
	cout << endl;
}
int main() {
	int  m[100], i = 0;
	ifstream Filein;
	Filein.open("D:\\File\\heap.txt", ios_base::in);

	for (i = 0; !Filein.eof(); i++) {
		int k;
		Filein >> k;
		m[i] = k;
	}

	cout << "Array befor sortion:";
	//i: sizeof array
	PrintArr(m, i);
	//increase
	HeapSort(m, i);

	cout << "Array after sortion:";
	PrintArr(m, i);

	Filein.close();

	system("pause");
	return 0;
}