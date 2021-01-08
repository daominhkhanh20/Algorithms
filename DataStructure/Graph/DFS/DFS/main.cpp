//https://www.dropbox.com/sh/54119l9thrv3r1x/AACoohrVBHzoaBldGLQ5ktrXa/Slides?dl=0&preview=lec17-dfs.pdf&subfolder_nav_tracking=1
#include<iostream>
#include<vector>
using namespace std;
#define N 10 //number of vertex

int cc;
bool visit[N];
int ccnum[N] = { 0 };
int pre[N], post[N];
int clock = 1;

void ConnectedComponent(int v) {
	ccnum[v] = cc;
}

//time in
void previsit(int v) {
	pre[v] = clock;
	clock++;
}

//time out
void postvisit(int v) {
	post[v] = clock;
	clock++;
}

void expoler(vector<int> a[N], int v) {
	visit[v] = true;
	previsit(v);
	//luu dinh v thuoc thanh phan lien thong so may
	ConnectedComponent(v);
	int i = 0;

	while (v < N&& i < a[v].size() ) {
		if (visit[a[v][i]] == false) {
			expoler(a, a[v][i]);
		}
		i++;
	}
	postvisit(v);
	cout << v << "  [" << pre[v] << "," << post[v] << "] Connected Component   " << ccnum[v] << "th" << endl;
}

void dfs(vector<int> a[N],int v) {//v:vertex
	cc = 0;
	//intilize visit[] ={false} <==> all vertex weren't visited
	for (int i = 0; i < v; i++) {
		visit[i] = false;
	}

	for (int i = 0; i < v; i++) {
		//if i weren't visited, build all vertex can connect i
		if (visit[i] == false) {
			cc++;
			expoler(a, i);
		}
	}
}
int main() {
	//in row, if i can connect j by directed vector ==>a[i][j]=1
	//Graph  D:\File\problem3.png   page 37

	vector<int> a[N];
	a[0].push_back(2); // <==> 0 --->2
	a[0].push_back(7);
	a[1].push_back(0);
	a[1].push_back(6);
	a[2].push_back(3);
	a[0].push_back(5);
	a[3].push_back(5);
	a[4].push_back(7);
	a[4].push_back(0);
	a[5].push_back(9);
	a[6].push_back(8);
	a[7].push_back(5);
	a[7].push_back(6);
	a[8].push_back(7);
	a[9].push_back(2);
	dfs(a, N);


	system("pause");
	return 0;
}