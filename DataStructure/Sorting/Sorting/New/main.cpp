// Print k elements the largest in array

#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

void kLagest(int arr[], int n, int k) {
	//implementation sort in array
	//**************NOTE*************

	//increment
	sort(arr, arr + n,greater<int>());

	//decrement
	//sort(arr, arr + n,less<int>());
	for (int i = 0; i < k; i++) {
		cout << arr[i]<<" ";
	}

}
int main() {
	int m[100];
	ifstream Filein;
	Filein.open("D:\\File\\sample.txt", ios_base::in);
	int i = 0;
	while (!Filein.eof()) {
		Filein >> m[i];
		i++;
	}
	cout << endl;
	kLagest(m, i, 3);
	cout << endl;
	system("pause");
	return 0;
}