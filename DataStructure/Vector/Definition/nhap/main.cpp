#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

int main() {
	ifstream filein;
	filein.open("D:\\File\\new.txt", ios_base::in);
	vector<int>s;
	
	while (!filein.eof()) {
		int x;
		filein >> x;
		s.push_back(x);
	}
	for (int i = 0; i < s.size(); i++) {
		cout << s[i]<<endl;
	}
	cout << s[-1];
	system("pause");
	return 0;
}