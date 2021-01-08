#include<iostream>
#include<queue>

using namespace std;

void show(priority_queue<int> k) {
	priority_queue<int> s = k;
	while (!s.empty()) {
		cout << s.top()<<endl;
		s.pop();
	}
}
int main() {
	//in C++, defaut crates a bulid max-heap for priority heap
	priority_queue<int> k;

	// if you want to build a min-heap, 
	//you will intilize     priority_queue <int, vector<int>, greater<int>> g
	k.push(9);
	k.push(1);
	k.push(15);
	k.push(32);
	k.push(11);

	show(k);
	system("pause");
	return 0;
}