#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
#define N 5

int muc[N] = { 1 };//luu muc
int color[N] = { 1 };//luu mau
vector<int>a[N];
bool visit[N] = { false };

void expoler(vector<int> a[N], int v) {
	visit[v] = true;
	int k=muc[v]++;
	//luu dinh v thuoc thanh phan lien thong so may
	int i = 0;

	while (v < N&& i < a[v].size()) {
		if (visit[a[v][i]] == false) {
			expoler(a, a[v][i]);
		}
		if (i < a[v].size()) {
			i++;
			muc[a[v][i]] = k;
		}
	}
}

void dfs(vector<int> a[N], int v) {//v:vertex
	//intilize visit[] ={false} <==> all vertex weren't visited
	for (int i = 0; i < v; i++) {
		visit[i] = false;
	}

	for (int i = 0; i < v; i++) {
		//if i weren't visited, build all vertex can connect i
		if (visit[i] == false) {
			expoler(a, i);
		}
	}
}
int main() {
	//ifstream filein;
	//filein.open("D:\\File\\color.txt", ios_base::in);
	//int v;
	//filein >> v;//vertex
	//int eg;//edge
	//filein >> eg;


	//while (!filein.eof()) {
	//	int x, y;
	//	for (int i = 0; i < N; i++) {
	//		filein >> x;
	//		filein >> y;
	//		a[x].push_back(y);
	//	}
	//}
	//for (int i = 0; i < N; i++) {
	//	//luu y: tai nhung a[i][j] nhat dinh thi a[i][j] ko co gia tri
	//	for (int j = 0; j < a[i].size(); j++) {
	//		cout << a[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	a[0].push_back(1);
	a[1].push_back(2);
	a[2].push_back(3);
	a[3].push_back(0);
	a[0].push_back(4);

	dfs(a, 0);
	for (int i = 0; i < N; i++) {
		cout << muc[i] << " ";
	}
	system("pause");
	return 0;
}

