#include<iostream>
using namespace std;

int kiemtra(int n) {
	return n % 2 ? 1 : 0;
}

int main() {
	int n;
	cout << "n=";
	cin >> n;
    
	if (kiemtra(n)==0) {
		cout << n << " la so chan ";
	}
	else {
		cout << n << " la so le";
	}
	system("pause");
	return 0;
}