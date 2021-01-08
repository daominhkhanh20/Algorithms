//CAY NHI PHAN TIM KIEM

//Note: chi chua cac phan tu khac nhau
#include<iostream>
#include<fstream>
using namespace std;

struct node {
	int data;
	struct node *pLeft;
	struct node *pRight;
};
typedef struct node Node;
typedef Node* Tree;

void khoitaocay(Tree &t) {// <==> void khoitaocay(Node* &t) can dung con tro cap 2 de quan ly cac node
	t = NULL;//khoi tao cay rong
}

void themvaocay(Tree &t, int x) {
	if (t == NULL) {//Node dau tien(hay con goi la Node goc:root)
		Node *p = new Node();// cap phat dong
		p->data = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;/*neu ko co dung nay thi Node dau tien chua dc tao ra ma chi tao ra Node p ma ta
			  khoi tao(tuc la chua them Node p vao dau cay)
			  khi t=p <==> root(goc) dc khoi tao
			  */
	}
	else {
		if (x < t->data) {//phan tu nho hon gia tri nut(leaf) se sang ben trai

			//*************De quy*************


			themvaocay(t->pLeft, x);
			/* de quy nay khi nao thi dung ??
			  khi t->NULL tuc la no se thuc hien dong lenh 20 ->24
			*/
		}
		else if (x > t->data) {
			themvaocay(t->pRight, x);//tuong tu nhu giai thich o tren
		}
	}
}

void duyetcay(Tree t) {//Node left right
	if (t != NULL) {
		cout << t->data << " ";
		duyetcay(t->pLeft);
		/*duyet tu ben trai truoc
		de quy dung khi ->NULL
		*/
		duyetcay(t->pRight);
	}
}
bool check(int n) {
	if (n <= 1)
		return false;
	else {
		if (n == 2)
			return true;
		else {
			for (int i = 2; i < n; i++) {
				if (n%i == 0)
					return false;
			}
		}
	}
	return true;
}

int duyetcayLNR(Tree t, int &n) {// tinh so nguyen to co trong cay
	if (t != NULL) {
		if (check(t->data) == true) {
			n++;
		}
		duyetcayLNR(t->pLeft, n);
		duyetcayLNR(t->pRight, n);
	}
	return n;
}


//Tim kiem phan tu trong cay

int looking_for_element(Tree t, int x) {
	if (t == NULL)
		return 0;
	else {
		if (x > t->data)
			looking_for_element(t->pRight, x);
		else if (x < t->data)
			looking_for_element(t->pLeft, x);
		else
			return 1;
	}
}



int max(int a, int b) {
	return a > b ? a : b;
}

//height tree


int height(Tree t) {
	if (t == NULL) {
		return 0;
	}
	else {
		int a = height(t->pLeft);
		int b = height(t->pRight);

		return max(a, b)+1 ;
	}
}
Node *move(Tree t) {
	Node *p = t->pRight;
	if (p != NULL && t->pRight->pRight == NULL)
		return t->pRight;
	else
		move(t->pRight);
}
//Tim gia tri max trong cay
//TH : cay nhi phan co du 2 nhanh left va nhanh right
int value_max_in_tree(Tree t) {
	if (t != NULL) {
		Node *p = move(t);
		return p->data;
	}
}

//TH: tong quat

int max2(Tree t) {
	//TH: nhanh ben phai ko co phan tu thi phan tu root la MAX
	if (t->pRight == NULL)
		return t->data;
	else
		max2(t->pRight);
}


//xoa node trong binary tree
//xoa node 1 con

void DeleteNode(Tree &t, int x) {
	//b1 tim vi tri cua Node can tim
	if (x > t->data)
		DeleteNode(t->pRight, x);
	else if (x < t->data)
		DeleteNode(t->pLeft, x);
	else {
		//tim thay vi tri Node can xoa
		//th1 Node do la leaf
		if (t->pLeft == NULL && t->pRight == NULL) {
			t = NULL;
		}
		//th2: Node la nut
		//ben trai=NULL
		else if (t->pLeft == NULL && t->pRight != NULL) {
			t = t->pRight;
		}
		//ben phai =NULL
		else if (t->pLeft != NULL && t->pRight == NULL) {
			t = t->pLeft;
		}
		//TH3: co 2 con
		else {
			Node *g = t->pLeft;
			Node*k = t->pRight;
			Node*h = k;
			//tim phan tu chua gia tri Min ve phia ben trai cua Node can xoa
			//tro gia tri cua Node can xoa den gia tri Min
			// free bo nho cua Node chua gia tri min
			while (h->pLeft != NULL) {
				h = h->pLeft;
			}

			t = t->pRight;
			h->pLeft=g;
		}
	}

}

int main() {
	ifstream FileIn;
	FileIn.open("D:\\File\\in.txt", ios_base::in);//mo File de doc
	Tree t;
	khoitaocay(t);
	while (!FileIn.eof()) {
		int x;
		FileIn >> x;
		themvaocay(t, x);
	}
	duyetcay(t);
	/*for (int i = 0; i <= 5; i++) {
		int x;
		cin >> x;
		themvaocay(t, x);
	}*/
	/*int n = 0;
	cout << "\nCay co " << duyetcayLNR(t, n) << " so nguyen to";*/
	cout << "\nHeight Tree:" << height(t);


	/*int x;
	cout << "\nGia tri can tim kiem:"; cin >> x;
	if (looking_for_element(t, x))
		cout << "\nGia tri " << x << " co trong cay";
	else
		cout << "\nKo tim thay " << x << endl;*/

		//tim max trong cay
		//cout << "\nMax in tree: " << value_max_in_tree(t);


		//delete node
	/*int a;
	cout << "\nGia tri cua Node can xoa:"; cin >> a;
	DeleteNode(t, a);*/
	//duyetcay(t);

	FileIn.close();

	system("pause");
	return 0;
}