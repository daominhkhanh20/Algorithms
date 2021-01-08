#include<iostream>
#include<fstream>
using namespace std;

struct node{
	int data; //data
	struct node *pNext; //khai bao con tro tro den vi tri ke tiep(tro sang ben phai)
};
typedef struct node Node;

struct list{
	Node *pHead;
	Node*pTail;
};
typedef struct list List;

void khoitaodanhsach(List &l) {
	l.pHead = l.pTail = NULL;
}

Node *khoitaogiatri(int x) {
	Node *p = new Node();
	if (p == NULL) {
		cout << "Cap phat ko thanh cong\n";
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}
//them Node vao dau
void themvaodau(List &l, Node *k) {
	if (l.pHead == NULL) {
		l.pHead = k;
	}
	else {
		k->pNext = l.pHead;//tro con tro k den pHead
		l.pHead = k;//cap nhat lai con tro dau
	}
}
//them Node vao cuoi
void themvaocuoi(List &l, Node *k) {
	if (l.pHead == NULL) {
		l.pHead =l.pTail= k;
	}
	else {
		l.pTail->pNext = k;;//tro con tro k den pHead
		l.pTail = k;//cap nhat lai con tro dau
	}
}
void PrintList(List l) {
	//tuong tu
	//for(int i=0;i<n;i++)
	for (Node *k = l.pHead; k != NULL; k = k->pNext) {
		cout << k->data << " ";
	}
}
void DeleteNodeHead(list &l, int x) {
	//xoa dau
	if (l.pHead->data == x) {
		l.pHead = l.pHead->pNext;
		DeleteNodeHead(l, x);
	}
	return;
}
void DeleteNodeTail(list &l, int x) {
	//xoa cuoi
	if (l.pTail->data == x) {
		for (Node *a = l.pHead; a != NULL; a = a->pNext) {
			if (a->pNext == l.pTail) {
				delete l.pTail;
				a->pNext = NULL;
				l.pTail = a;
			}
		}
	}
}
void DeleteNode(List &l, int x) {
	
	DeleteNodeHead(l, x);

	Node*g = new Node();
	for (Node *a = l.pHead; a != NULL; a = a->pNext) {
		if (a->data == x &&a->pNext!=NULL&& a->pNext->data == x) {
			g->pNext = a->pNext;
			a = g;
		}
		if (a->data == x) {
			g->pNext = a->pNext;
		}
		g = a;
	}
	DeleteNodeTail(l, x);
}
void Chen_Node_q_Sau_Node_p(List &l, int x) {
	int a;
	cout << "\nGia tri Node can chen vao phia sau:";
	cin >> a;

	for (Node *k = l.pHead; k != NULL; k = k->pNext) {
		Node *m = khoitaogiatri(x);
		if (k->data == a) {
			m->pNext = k->pNext;
			k->pNext = m;
		}
	}
}
void Chen_Node_q_Truoc_Node_p(List &l, int x) {
	int a;
	cout << "\nGia tri Node can chen vao phia truoc:";
	cin >> a;
	Node *g = new Node();
	for (Node *k = l.pHead; k != NULL; k = k->pNext) {
		Node *m = khoitaogiatri(x);
		if (k->data == a) {
			m->pNext = k;
			g->pNext = m;
		}
		g = k;
	}
}

//Delete all Duplocate in the List
Node*RemoveDuplicate(Node*k) {
	Node*g = k;
	while (g->pNext != NULL) {
		if (g->data == g->pNext->data) {
			Node*t = g->pNext;
			g->pNext = t->pNext;
			delete(t);
		}
		else {
			g = g->pNext;
		}
	}
	return k;
}
int main() {
	ifstream FileIn;
	FileIn.open("D:\\File\\vc.txt", ios_base::in);//mo file
	List l;
	khoitaodanhsach(l);
	while (!FileIn.eof()) {
		int x;
		FileIn >> x;
		Node *k = khoitaogiatri(x);
		themvaocuoi(l, k);
	}
	PrintList(l);

	//Ham xoa Node
	/*while (1) {
		cout << "\nNhap gia tri can xoa:";
		int x;
		cin >> x;
		DeleteNode(l, x);
		PrintList(l);
	}*/
	

	//Delete duplicate-value nodes from a sorted in list
	//5 5 3 3 2 4 3 3 1 2  ----> 5 3 2 4 3 1 2
	cout << endl;
	l.pHead = RemoveDuplicate(l.pHead);
	PrintList(l);
	

	//Ham chen tham 1 Node
	/*int k;
	cout << "\nGia tri Node can them:";
	cin >> k;*/
	//chen vao phia sau


	//Chen_Node_q_Sau_Node_p(l, k);


	//chen vao phai truoc


	//Chen_Node_q_Truoc_Node_p(l, k);


	//PrintList(l);
	system("pause");
	return 0;

}