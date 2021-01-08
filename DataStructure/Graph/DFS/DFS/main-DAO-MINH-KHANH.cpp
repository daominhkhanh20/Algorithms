//https://www.dropbox.com/sh/54119l9thrv3r1x/AACoohrVBHzoaBldGLQ5ktrXa/Slides?dl=0&preview=lec17-dfs.pdf&subfolder_nav_tracking=1
#include<iostream>
#include<vector>
using namespace std;
#define N 8 //number of vertex

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

void expoler(vector < vector<int>>a, int v) {
	visit[v] = true;
	previsit(v);
	//luu dinh v thuoc thanh phan lien thong so may
	ConnectedComponent(v);
	int i = 0;

	while (v < N&& i < a[v].size() ) {
		if (a[v][i] == 0) {
			i++;
			continue;
		}
		if (a[v][i]==1&&visit[i] == false) {
			expoler(a, i);
		}
		i++;
	}
	postvisit(v);
}

void dfs(vector < vector<int>>a,int v) {//v:vertex
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
	//Graph      D:\File\Problem1.png
	vector<vector<int> > a{ { 0, 1, 0,0,0,0,1,0 },
							{ 0, 0, 1,0,0,0,0,0 },
							{ 0, 0, 0,1,1,1,0,0 },
							{ 0, 1, 0,0,1,0,0,0 },
							{ 0, 0, 0,0,0,0,0,0 },
							{ 0, 0, 0,0,0,0,0,0 },
							{ 0, 0, 0,0,0,0,0,1 },
							{ 1, 0, 0,0,1,0,0,0 }
                                                    };

	dfs(a, N);
	for (int i = 0; i < N; i++) {
		cout << "["<<pre[i] << "," << post[i]<<"] Connected Component   "<<ccnum[i]<<"th" << endl;
	}

	system("pause");
	return 0;
}