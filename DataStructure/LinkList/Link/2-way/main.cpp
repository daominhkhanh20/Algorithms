

#include<iostream>
#include<fstream>
#include<stack>
using namespace std;

struct node {
	int data;
	struct node *next;
	struct node *pre; //previous
	
};
typedef struct node Node;

//local variable
Node*head;

Node*CreateNode(int x) {
	Node*p = new Node();
	p->data = x;
	p->next = NULL;
	p->pre = NULL;
	return p;
}

void PushHead( int x) {
	Node*k = CreateNode(x);
	if (head == NULL) {
		head = k;
		return;
	}
	head->pre = k;
	k->next = head;
	head = k;
}

void Print_List() {
	Node*k = head;
	while (k != NULL) {
		cout << k->data<<" ";
		k = k->next;
	}
	/*while (k != NULL&&k->next!=NULL)
		k = k->next;
	while (k != NULL) {
		cout << k->data<<" ";
		k = k->pre;
	}*/
}

//Insert Node into a sorted list while maintain the sort

Node*InsertedNode(int data) {
	//Method 1:
	Node*k = CreateNode(data);
	if (head == NULL) {
		head = k;
	}
	else if (head->data > data) {
		k->next = head;
		k->pre = NULL;
		head->pre = k;
		head = k;
	}
	else {
		Node*g = head;
		while (g != NULL) {
			if (g->data >= k->data) {
				k->next = g;
				k->pre = g->pre;
				g->pre->next = k;
				g->pre = k;
				return head;
			}
			if (g->next != NULL)
				g = g->next;
			else
				break;
		}

		//Method 2:
		/*while (g->next != NULL&&g->next->data<data) {
			g = g->next;
		}
		k->pre = g;
		k->next = g->next;
		if (g->next != NULL) {
			g->next->pre = k;
		}*/
		g->next = k;
	}
	
	return head;
}

//Reverse DoubleLinkList
Node* reverse() {
	if (head == NULL) {
		return NULL;
	}
	stack<int>s;
	for (Node*k = head; k != NULL; k = k->next) {
		s.push(k->data);
	}
	Node*g = head;
	while (s.empty()==false) {
		g->data = s.top();
		s.pop();
		if (g->next != NULL) {
			g = g->next;
		}
		else {
			break;
		}
	}
	return head;
}
int main() {
	ifstream FileIn;
	FileIn.open("D:\\File\\2way2.txt", ios_base::in);//open file
	//initialize Head pointer =NULL
	head = NULL;
	
	//Check File empty or not
	bool empty = FileIn.peek() == EOF;

	while (!FileIn.eof()&&!empty) {
		int x;
		FileIn >> x;		
		//Why don't pass the reference Head pointer
		/*Idea:
		  Because: if head pointer is passed , default head=NULL
		*/
		PushHead(x);
	}

	head = InsertedNode(11);
	Print_List();
	cout << endl;
	head = reverse();
	Print_List();
	system("pause");
	return 0;
}

