//replace each node in binary tree with sum of its inorder predecessor and successor
// thay the moi phan tu bang tong cua phan tu ngay sau va ngay truoc no

//Node: inorder
#include<iostream>
#include<vector>

using namespace std;

struct Node {
	int data;
	struct Node*pLeft;
	struct Node*pRight;

	Node(int x) {
		this->data = x;
		this->pLeft = this->pRight = NULL;
	}
};


//Can truyen tham chieu vector<int>&k vi kich thuoc cua vevtor bi thay doi
//So voi mang thi vecto thuan tien hon, vi ko can khai bao kich thuoc toi da
//cua mang
void StoreAllNodeInArrt(Node *root, vector<int> &k) {
	if (root == NULL)
		return;
	//luu tru cac phan tu ben trai so voi Node
	StoreAllNodeInArrt(root->pLeft, k);
	k.push_back(root->data);
	//lua tru cac phan tu ben phai so voi Node
	StoreAllNodeInArrt(root->pRight, k);

}

void CompetetionSumWithNode(Node*root, vector<int>k, int *i) {
	if (root == NULL)
		return;
	CompetetionSumWithNode(root->pLeft, k, i);
	root->data = k[*i - 1] + k[*i+1];
	++*i;
	CompetetionSumWithNode(root->pRight, k, i);
}
void ReplaceNodeWithSum(Node *root) {
	if (root == NULL)
		return;

	vector<int>k;
	/* muc dich them phan tu 0 vao dau cuoi la de tinh ket qua cho 2 phan tu
     dau va cuoi cua cay nhi phan
	 vi phan tu dau tien cua cay nhi phan =0+ phan tu ke sau cua cay nhi phan
	*/

	//them phan tu 0 vao dau mang k[0]=0
	//Node: vecto::push_back push element in end array
	k.push_back(0);
	
	//luu tru cac phan tu con lai cua cay
	StoreAllNodeInArrt(root, k);
	//them phan tu 0 vao cuoi 
	k.push_back(0);

	
	cout << endl;
	int i = 1;
	CompetetionSumWithNode(root, k, &i);


}
void PrintResult(Node*root) {
	if (!root)
		return;
	PrintResult(root->pLeft);
	cout << root->data << " ";
	PrintResult(root->pRight);
}

int main() {
	struct Node *root = new Node(1);
	root->pLeft = new Node(2);
	root->pLeft->pLeft = new Node(4);
	root->pLeft->pRight = new Node(5);
	root->pRight = new Node(3);
	root->pRight->pLeft = new Node(6);
	root->pRight->pRight = new Node(7);

	cout << "Binary Tree befor replace with sum node(inorder):";
	PrintResult(root);

	cout << "\n\nBinary Tree after replace with sum node(inorder):";
	ReplaceNodeWithSum(root);
	PrintResult(root);
	cout << endl;

	system("pause");
	return 0;
}