#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//khai bao cau truc sinh vien
struct SinhVien {
	string name;
	int ns;
};
typedef struct SinhVien SinhVien;
//khai bao cau truc Node
struct node {
	SinhVien data;
	struct node *pNext;// con tro chuyen sang node ke tiep
};
typedef struct node Node;
//Khai bao Danh sach
struct list {
	Node *pHead;//con tro quan ly dau danh sach
	Node *pTail;//con tro quan ly cuoi danh sach
};
typedef struct list List;


void khoitaoList(List &t) {
	t.pHead = t.pTail = NULL;
}

Node* khoitaoNode(SinhVien x) {
	Node *p = new Node;
	if (p == NULL) {
		cout << "Cap phat dong ko thanh cong";
		system("pause");
		return 0;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}

void themvaocuoi(List &l, Node *k) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = k;
	}
	else {
		l.pTail->pNext = k;
		l.pTail = k;//cap nhat con tro cuoi danh sach
	}
}
//doc thong tin cua tung nguoi
void DocThongTinTungNguoi(ifstream &FileIn, SinhVien &k) {
	getline(FileIn, k.name, ',');//doc cho den dau ,
	FileIn >> k.ns;

}
//doc thong tin toan bo danh sach
void DocFile(ifstream &FileIn, List &l) {
	while (!FileIn.eof()) {
		SinhVien x;
		DocThongTinTungNguoi(FileIn, x);
		Node *k = khoitaoNode(x);
		themvaocuoi(l, k);
	}
}
void xuat(SinhVien x) {
	cout << "Ten:" << x.name << endl;
	cout << "ns:" << x.ns << endl;
}
//xuat danh sach
void XuatDs(List l) {
	int temp = 1;
	for (Node *k = l.pHead; k != NULL; k = k->pNext) {
		cout << "Nguoi Thu:" << temp++ << endl;
		xuat(k->data);
		cout << endl;
	}
}
void Delete(List &l) {
	//delete head
	if (l.pHead->data.ns == 1974) {
		Node *p = l.pHead;
		l.pHead = l.pHead->pNext;
		free(p);
	}

	//Node*g = new Node();
	for (Node*k = l.pHead; k != NULL; k = k->pNext) {
		if (k->pNext->data.ns == 1974&& k->pNext->pNext!=NULL) {
			k->pNext = k->pNext->pNext;
		}
	}
}
int main() {
	List l;
	struct SinhVien;
	khoitaoList(l);
	ifstream FileIn;
	FileIn.open("D:\\File\\ds.txt", ios_base::in);//mo file de doc

	DocFile(FileIn, l);
	XuatDs(l);

	cout << "\nList after delete:\n\n";
	Delete(l);
	XuatDs(l);
	FileIn.close();//dong File
	system("pause");
	return 0;
}