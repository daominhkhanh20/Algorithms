//Stack using 1 queue

#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class Stack 
{
private:
	//chua 2 queue
	queue<int> q1, q2;
	int size;

public:
	Stack() {
		//khoi tao stack rong
		size = 0;
	}
	void push(int x) {

		size++;
		q2.push(x);
		
		while (q1.empty()==false) {
			//them phan tu dau cua q1 vao cuoi q2
	
			q2.push(q1.front());
			//sau khi them thi xoa phan tu pop ra khoi q1
		
			q1.pop();
		}
		//hoan doi q1,q2
		swap(q1, q2);
	}

	void pop() {
		if (q1.empty()) {
			return;
		}
		q1.pop();
		size--;
	}
	int top() {
		if (q1.empty()) {
			return -1;
		}
		return q1.front();
	}
	int sizeS() {
		return size;
	}
};

int main() {
	Stack s;

	s.push(5);
	s.push(15);
	s.push(55);
	cout << "Size of stack " << s.sizeS()<<endl;


	system("pause");
	return 0;
}