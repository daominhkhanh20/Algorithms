#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

struct node {
	int data; //data
	struct node *pNext; //khai bao con tro tro den vi tri ke tiep(tro sang ben phai)
};
typedef struct node Node;

struct list {
	Node *pHead;
	Node*pTail;
};
typedef struct list List;

void khoitaodanhsach1(List &l) {
	l.pHead = l.pTail = NULL;
}

Node *khoitaogiatri1(int x) {
	Node *p = new Node();
	if (p == NULL) {
		cout << "Cap phat ko thanh cong\n";
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}
//them Node vao dau
void themvaodau1(List &l, Node *k) {
	if (l.pHead == NULL) {
		l.pHead =l.pTail= k;
	}
	else {
		k->pNext = l.pHead;//tro con tro k den pHead
		l.pHead = k;//cap nhat lai con tro dau
	}
}
void themvaocuoi1(List &l, Node *k) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = k;
	}
	else {
		l.pTail->pNext = k;;//tro con tro k den pHead
		l.pTail = k;//cap nhat lai con tro dau
	}
}
void PrintList1(List l) {
	//tuong tu
	//for(int i=0;i<n;i++)
	for (Node *k = l.pHead; k != NULL; k = k->pNext) {
		cout << k->data << " ";
	}
}
bool CompareList(list l1, list l2) {
	int a = 0;
	Node*k = l1.pHead;
	Node*g = l2.pHead;
	while (k != NULL && g != NULL) {
		if (k->data != g->data) {
			a = 1;
			break;
		}
		k = k->pNext;
		g = g->pNext;
	}
	if (a == 1 || k != NULL || g != NULL) {
		return false;
	}
	else
		return true;
}
//Method 1:


//void StoreALlElement2List(list l1, list l2,int m[]) {
//	int n = 0;
//	Node*k = l1.pHead;
//	Node*g = l2.pHead;
//	while (k != NULL || g != NULL) {
//		if (k != NULL) {
//			m[n] = k->data;
//			n++;
//			k = k->pNext;
//		}
//		if (g != NULL) {
//			m[n] = g->data;
//			n++;
//			g = g->pNext;
//		}
//	}
//}
//void push(list &l3,int m[],int n) {
//	//sort array
//	sort(m, m + n, less<int>());
//
//	l3.pHead= khoitaogiatri1(m[0]);
//	Node*k = l3.pHead;
//	for (int i = 1; i < n; i++) {
//		k->pNext = khoitaogiatri1(m[i]);
//		k = k->pNext;
//	}
//	
//}
//void MergeSorted2ListAcending(list l3,list l1,list l2, int n) {	
//	int m[50];
//	StoreALlElement2List(l1, l2, m);
//	push(l3, m, n);	
//	PrintList1(l3);
//}

//Method 2:

Node* Merge2LinkList(Node*a, Node*b) {
	Node*k = new Node();
	if (a == NULL)
		return b;
	if (b == NULL) {
		return a;
	}

	if (a->data <= b->data) {
		k = a;
		k->pNext = Merge2LinkList(a->pNext, b);
	}
	else if (a->data >= b->data) {
		k = b;
		k->pNext = Merge2LinkList(a, b->pNext);
	}
	return k;
}
int main() {
	ifstream FileIn;
	FileIn.open("D:\\File\\2list.txt", ios_base::in);//mo file
	List l1,l2;
	khoitaodanhsach1(l1);
	khoitaodanhsach1(l2);
	int b, a;
	//a: number of element in list l1
	//b:number of element in list l2
	FileIn >> b;
	FileIn >> a;
	for (int i = 1; i <= b; i++) {
		int x;
		FileIn >> x;
		Node *k = khoitaogiatri1(x);
		themvaodau1(l1, k);
	}
	for (int i = 1; i <= a; i++) {
		int x;
		FileIn >> x;
		Node *k = khoitaogiatri1(x);
		themvaodau1(l2, k);
	}
	
	//Compair 2 List
	//cout << CompareList(l1, l2)<<endl;

	
	//Merge 2 List satisfy into 1 list ascending
	list l3;
	khoitaodanhsach1(l3);

	//Method 1:

	//MergeSorted2ListAcending(l3, l1, l2, a + b);

	//Method 2:Note:Method 2 is true if the data in both Lists will be stored ascending order

	//l3.pHead = Merge2LinkList(l1.pHead, l2.pHead);


	PrintList1(l3);
	system("pause");
	return 0;
}