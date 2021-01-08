#include<iostream>
#include<queue>
#include<fstream>
using namespace std;

int main() {
	priority_queue<int>k;
	ifstream filein;
	filein.open("D:\\File\\vc.txt", ios_base::in);
	while (!filein.eof()) {
		int x;
		filein >> x;
		k.push(x);
	}
	while (!k.empty()) {
		cout << k.top() << endl;;
		k.pop();
	}
	system("pause");
	return 0;
}