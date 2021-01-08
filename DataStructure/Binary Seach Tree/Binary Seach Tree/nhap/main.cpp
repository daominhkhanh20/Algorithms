#include<iostream>
#include<fstream>
using namespace std;

struct node {
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node Node;

Node * insert(Node * root, int data) {
	if (root == NULL) {
		Node*p = new Node();
		p->data = data;
		p->left = p->right = NULL;
		root = p;
	}
	else {
		if (data > root->data) {
			root->right=insert(root->right, data);
		}
		else if (data < root->data) {
		    root->left=insert(root->left, data);
		}
	}
	return root;
}

void PreOrder(Node*root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << " ";
	PreOrder(root->left);
	PreOrder(root->right);
}
int main() {
	ifstream FileIn;
	FileIn.open("D:\\File\\in.txt", ios_base::in);//mo File de doc
	Node*root=NULL;
	while (!FileIn.eof()) {
		int x;
		FileIn >> x;
		root = insert(root, x);
	}
	PreOrder(root);
	FileIn.close();

	system("pause");
	return 0;
}