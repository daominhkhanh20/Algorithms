//Using 2 Stack
#include<iostream>
#include<stack>
#include<queue>


/*Su khac nhau giua Stack va Queue chi la cach xoa phan tu 
 Stack thi xoa phan tu moi dc them vao
 Queue thi xoa phan tu dc them vao nhung phan tu do o trong Stack lau hon 
 (gia hon) so voi cac phan tu con lai
*/
using namespace std;

class Queue {
	stack<int> s1, s2;

public:
	//Method:
/*Dau tien push cac phan tu cua Stack 1 sang Stack 2 roi push cac phan tu cua Stack 2
sang Stack 1
ex:
   s1:1 2 3 4
   s2:  5 6

   push s1->s2  4 3 2 1 5 6
   push s2->s1  6 5 1 2 3 4 <==> queue

*/
	void enqueue(int x) {//them phan tu
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
		s1.push(x);

		while (!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}
	}
	int dequeue() {//tra ve gia tri phan tu dau tien va xoa no di
		if (s1.empty()) {
			cout << "Queue empty \n";
			
			system("pause");
			return 0;
		}
		int x = s1.top();//lay gai tri phan tu dau
		s1.pop();//xoa phan tu dau di
		return x;
	}
};


int main() {
	Queue p;
	p.enqueue(9);
	p.enqueue(99);
	p.enqueue(999);

	cout << "First element:" << p.dequeue() << endl;
	cout << "First element:" << p.dequeue() << endl;
	cout << "First element:" << p.dequeue() << endl;
	cout << "First element:" << p.dequeue() << endl;

	system("pause");
	return 0;
}