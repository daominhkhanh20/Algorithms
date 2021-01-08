#include<iostream>
using namespace std;

struct node {
	int data;
	struct node *pLeft;
	struct node *pRight;
};
typedef struct node Node;
typedef struct node* tree;//cay quan ly cac Node

//khoi tao cay rong
void khoitaocay(tree&t) {
	t = NULL;
}
Node*khoitaogiatri(int x) {
	Node*k = new Node();
	k->data = x;
	k->pLeft = k->pRight = NULL;
	return k;
}

void PrintTree(tree t) {//thu tu in: left -> node-> right
	if (t == NULL)
		return;
	cout << t->data << " ";
	PrintTree(t->pLeft);
	PrintTree(t->pRight);
}
//chen 1 gia tri vao cay de dc full binary tree
void insert(tree &t,int x) {
	if (t == NULL) {		
		return;
	}
	else {
		if (t->pRight == NULL && t->pLeft != NULL) {
			Node *k = khoitaogiatri(x);
			t->pRight = k;
		}
		else if (t->pLeft == NULL && t->pRight != NULL) {
			Node *k = khoitaogiatri(x);
			t->pLeft = k;
		}

		insert(t->pLeft, x);
		insert(t->pRight, x);
	}
}

//xoa node
void DeleteTree(tree &t, int k) {
	if (t == NULL) {
		return;
	}
	if (t->data == k) {
		//node la
		if (t->pRight == NULL && t->pLeft == NULL) {
			t = NULL;
		}
		//nut 1 la
		else if (t->pRight != NULL && t->pLeft == NULL) {
			t = t->pRight;
		}
		else if (t->pRight == NULL && t->pLeft != NULL) {
			t = t->pLeft;
		}
		//nut 2 la	
		else {

		}
	}
	DeleteTree(t->pLeft, k);
	DeleteTree(t->pRight, k);

}
//chieu cau cay
int HeightTree(tree t) {
	if (t == NULL)
		return 0;
	int a = HeightTree(t->pLeft);
	int b = HeightTree(t->pRight);
	return a > b ? a + 1 : b + 1;
}

//return true of false 
//if find path return true
bool hasPathWithGivenSum(tree t, int s) {

	if (t == NULL)
		return s == 0;
	// case : tree has 1 node
	else if (t->pLeft == NULL && t->pRight == NULL)
		return s == t->data;
	//case: parent has 1 node
	else if (t->pLeft == NULL)
		return hasPathWithGivenSum(t->pRight, s - t->data);
	else if (t->pRight == NULL)
		return hasPathWithGivenSum(t->pLeft, s - t->data);
	//case: parent has 2 node
	else
		return hasPathWithGivenSum(t->pLeft, s - t->data) || hasPathWithGivenSum(t->pRight, s - t->data);
}
int main() {
	tree t;
	khoitaocay(t);
	//them cac node vao cay
	t = khoitaogiatri(10);
	t->pLeft = khoitaogiatri(11);
	t->pRight = khoitaogiatri(9);
	t->pLeft->pLeft = khoitaogiatri(7);
	t->pRight->pLeft = khoitaogiatri(15);
	t->pLeft->pRight = khoitaogiatri(3);
	t->pRight->pRight = khoitaogiatri(8);

	//PrintTree(t);
	//cout << "\nHeight tree:" << HeightTree(t);
	//int k;
	//cout << "\nThe element in tree need delete:";
	//cin >> k;
	//DeleteTree(t, k);
	//PrintTree(t);
	
	//Find path from root ->leaf satisfy sum of all value = s
	cout << hasPathWithGivenSum(t, 27);
	system("pause");
	return 0;
}