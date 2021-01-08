#include<iostream>
#include<vector>
#include<fstream>
#include<queue>

using namespace std;
#define N 5

vector<int>a[100];
int dist[100];
void bfs(int v) {
	for (int i = v + 1; i < N; i++) {
		dist[i] = INT16_MAX;
	}
	dist[v] = 0;
	queue<int>q;
	q.push(v);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < a[u].size();i++) {
			if (dist[a[u][i]] == INT16_MAX) {
				q.push(a[u][i]);
				dist[a[u][i]] = dist[u] + 1;
			}
		}
	}
}
int main() {
	ifstream filein;
	filein.open("D:\\File\\bfs.txt", ios_base::in);
	while (!filein.eof()) {
		int x, y;
		filein >> x;
		filein >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	bfs(0);
	for (int i = 0; i < N; i++) {
		cout << dist[i] << " ";
	}
	system("pause");
	return 0;
}