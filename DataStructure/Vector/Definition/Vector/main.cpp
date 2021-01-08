#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

int main() {
	ifstream filein;
	filein.open("D:\\File\\new.txt", ios_base::in);
	vector<int>s;


	int a;
	while (!filein.eof()) {
		filein >> a;
		s.push_back(a);//push elements
	}
	cout << s.size()<<endl;
	cout << s.front()<<endl;//first element in vetor
	cout << s.back() << endl;//last element
     
	s.pop_back();//delete last element;
	cout << s.back() << endl;
	cout << s.at(5) << endl;//i-th element 0->n
	s.clear();//delete all elements in vector

	cout<<s.empty();//check vetor is empty??
	system("pause");
	return 0;


}