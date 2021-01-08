//Implement two stacks in an array
//Method:
/*Them cac phan tu cua Stack 1 vao dau mang ;
Them cac phan tu cua Stack 2 vao cuoi mang theo thu tu nguoc chieu them cua Stack 1
*/
#include<iostream>;
using namespace std;

//Huong doi tuong (class)


class TwoStack {
	//khai bao cac bien,ham thuoc doi tuong class
	int *m;
	int size;
	int top1, top2;

public:
	TwoStack(int n) {
		m = new int();//cap phat dong
		size = n;
		top1 = -1;
		top2 = n;
	}
	//them phan thu cua Stack1 vao mang
	void pushStack1(int x) {
		if (top1 < top2 - 1) {//kiem tra Stak day hay chua
			top1++;
			m[top1] = x;
		}
		else {
			cout << "Stack overflow";
			system("pause");
			return;
		}
	}
	void pushStack2(int x) {//kiem tra Stak day hay chua
		if (top1 < top2 - 1) {
			top2--;
			m[top2] = x;
			//khi dung lai thi top2 la vi tri dau tien cua Stack 2
		}
		else {
			cout << "Stack overflow";
			system("pause");
			return;
		}
	}

	int pop1() {//lay phan tu dau tien cua Stack 1 ra
		if (top1 >=0) {
			int x = m[top1];
			top1--;
			return x;
		}
		else {
			cout << "Stack overflow";
			system("pause");
			return 0;
		}
	}
	int pop2() {//lay phan tu dau tien cua Stack 1 ra
		if (top2 <size) {
			int x = m[top2];
			top2++;
			return x;
		}
		else {
			cout << "Stack overflow";
			system("pause");
			return 0;
		}
	}
};

int main() {
	TwoStack k(5);// chi luu dc 5 phan tu trong mang
	k.pushStack1(10);
	k.pushStack2(5);
	k.pushStack1(1);
	k.pushStack2(9);
	cout << "\nPop element in Stack1 " << k.pop1();
	k.pushStack1(7);
	cout << "\nPop element in Stack2 " << k.pop2()<<endl;
	system("pause");
	return 0;
}