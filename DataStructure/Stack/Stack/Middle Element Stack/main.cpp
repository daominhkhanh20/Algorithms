//FindMiddle element in Stack
#include<iostream>

using namespace std;
/*<==>struct Node{
   ........
   }
*/
class DLLNode {//double link list
	//public: cac yeu to trong nay co the dc truy cap tu ben ngoai
	//protect: thi chi co trong class ms dc truy cap
public:
	DLLNode*next;//tro toi con tro ben phai no
	DLLNode*pre;//tro toi con tro ben trai cua no
	int data;
};
/*<==>struct List{
   ........
   }
*/
class myStack {
public:
	int count;//so phan tu cua danh sach lien ket
	DLLNode*head;//Node dau
	DLLNode*mid;//middle: Node giua
};

myStack*creat() {
	myStack*ms = new myStack();//cap phat dong bo nho cho my class
	ms->count = 0;//khoi tao so phan tu ban dau bang 0;

	return ms;
}

void push(myStack *ms, int x) {
	//them cao dau stack
	DLLNode*k = new DLLNode();
	k->data = x;
	k->next = ms->head;
	k->pre = NULL;
	ms->count++;
	//cap nhat mid 
	if (ms->count == 1) {
		ms->mid = k;
	}
	
	else {
		ms->head->pre = k;//can dong ay de chi ro moi quan he 2 chieu cua Node k va Node head
		if (ms->count % 2 == 0) {
			ms->mid = ms->mid->pre;//tai sao lai huong sang trai??
			/* gia su dau tien push(ms,1) vao thi mid chinh la 1
			 push(ms,2) thi mid la 2
			 push(ms,3) thi mid van la 2
			 ............
			 tong ket lai la xu huong cua con tro mid la huong sang ben trai


			*/
		}
	}
	ms->head = k;
}
int FindMiddle(myStack *ms) {
	if (ms->count == 0) {
		return -1;
	}
	return ms->mid->data;
}
void pop(myStack *ms) {
	DLLNode *k = ms->head;
	ms->head = k->next;
	ms->head->pre = NULL;
	free(k);
	ms->count--;
		
}
int top(myStack*ms) {
	return ms->head->data;
}
//delete old middle element, return new middle
int DeleteMiddle(myStack *ms) {
	//xoa mid cu
	DLLNode *k = ms->mid;
	if (ms->count % 2 == 0) {//neu so phan tu la chan thi dich chuyen con tro giua sang phai
		ms->mid = ms->mid->next;
		k->pre->next = ms->mid;
		free(k);
		ms->count--;
		// tra ve gia tri can tim
		return ms->mid->data;
	}
	else {//neu so phan tu la le thi dich chuyen con tron Mid sang trai
		ms->mid = ms->mid->pre;
		ms->mid->next = k->next;
		free(k);
		ms->count--;
		// tra ve gia tri can tim
		return ms->mid->data;
	}
}
int main() {
	myStack *ms= creat();
	push(ms, 5);
	push(ms, 6);
	push(ms, 7);
	push(ms, 8);
	push(ms, 9);
	push(ms, 10);
	push(ms, 0);
	cout<<FindMiddle(ms)<<endl;

	/*pop(ms);
	cout <<ms->count<<" "<< top(ms) << endl;
	pop(ms);
	cout << ms->count << " " << top(ms) << endl;
	pop(ms);
	cout << ms->count << " " << top(ms) << endl;
	pop(ms);
	cout << ms->count << " " << top(ms) << endl;*/

	cout << "count:" << ms->count << "\n" << "New Middle element:" << DeleteMiddle(ms)<<endl;
	cout << "count:" << ms->count << "\n" << "New Middle element:" << DeleteMiddle(ms) << endl;
	system("pause");
	return 0;
}