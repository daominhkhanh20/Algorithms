#include<iostream>
#include<stack>
#include<queue>

using namespace std;

class MyQueue {
	
	queue<int>k;
	stack <int>h;

public:
	/*Idea:
	chuyen cac phan tu cua Queue k sang Stack h
	sau do chuyen cac phan tu cua Stack h sang Queue k
	k: 1 2 3 4 5
	chuyen sang h:5 4 3 2 1
	chuyen sang k:5 4 3 2 1 <==> Resever k
	*/
	
	void enqueue(int x) {
		k.push(x);//them phan tu vao queue;
	};
	void resever(){
		while (!k.empty()) {
			h.push(k.front());
			k.pop();
		}
		while (!h.empty()) {
			k.push(h.top());
			h.pop();
		}
	}
	void PrintQueueAfterResever() {
		
		while (!k.empty()) {
			cout << k.front() << endl;
			k.pop();
		}
	}

	
};

int main() {
	MyQueue k;
	k.enqueue(1);
	k.enqueue(2);
	k.enqueue(3);
	k.enqueue(4);
	k.enqueue(5);
	k.resever();
	k.PrintQueueAfterResever();

	system("pause");
	return 0;
}