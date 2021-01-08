#include<iostream>
#include<fstream>
using namespace std;

struct node {
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node Node;

Node* CreatNode(int x) {
	Node *p = new Node();
	p->data = x;
	p->left = p->right = NULL;
	return p;
}
bool CheckNode(Node*root, int min, int max) {
	if (root == NULL)
		return true;
	if (root->data > max || root->data < min)
		return false;
	return CheckNode(root->left, min, root->data - 1) && CheckNode(root->right, root->data + 1, max);
}
bool CheckBTS(Node *root) {
	return CheckNode(root, INT_MIN, INT_MAX);
}

int main() {
	Node *root = CreatNode(6);
	root->left = CreatNode(1);
	root->right = CreatNode(7);
	root->right->right = CreatNode(10);
	/*root->pRight->pRight->pRight = CreatNode(11);
	root->pRight->pRight->pLeft = CreatNode(8);
	root->pLeft->pLeft = CreatNode(0);
	root->pLeft->pRight = CreatNode(2);*/

	cout<<CheckBTS(root);

	system("pause");
	return 0;
}