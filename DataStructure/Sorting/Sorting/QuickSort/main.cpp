//idea: phan chia roi hoan doi cac phan tu trong mang thanh cac mien de xap xep

#include<iostream>
#include<fstream>

using namespace std;

//front: starting of index
//end  : end of index

//Ham tra ve vi tri icua phan tu phan chi mang thanh 2 mien
//mien ben trai :tat ca phan tu co gia tri <=m[i]
//mien ben phan :tat ca phan tu co gia tri >=m[i]

int partition(int m[100], int front, int end) {
	int i = front ;
	int temp = m[end];//phan tu cuoi la khoa
	                  //la phan tu tai vi tri can tra ve
	
	for (int j = front; j <= end-1; j++) {//bo qua phan tu cuoi vi no dc xem la key
		if (m[j] <= temp) {
			swap(m[i], m[j]);
			i++;
		}
	}
	//sau khi het thuc vong lap thi m[i+1] > all element m[0->i]
	//hoan doi gia tri cua phan tu khoa va m[i+1]
	swap(m[i + 1], m[end]);
	
	// phan chia thanh cac mien thanh cong
	return i+1;

}

void QuickSort(int m[100], int front, int end) {
	if (front < end) {
		int k = partition(m, front, end);
		//tiep tuc xap xep sau khi da dc phan chia mien

		QuickSort(m, front, k - 1);
		QuickSort(m, k + 1, end);
	}
}
int main() {
	int m[100];
	ifstream Filein;
	Filein.open("D:\\File\\sample1.txt", ios_base::in);
	int n = 0;
	while (!Filein.eof()) {
		int k;
		Filein >> k;
		m[n] = k;
		++n;
	}
	//increment
	QuickSort(m, 0, n-1);

	for (int i = 0; i < n; i++) {
		cout << m[i] << " ";
	}
	system("pause");
	return 0;
}