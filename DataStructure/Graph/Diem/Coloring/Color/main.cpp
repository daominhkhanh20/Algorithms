#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

#define N 7
vector<int>a[N];
int color[N] = {0};
bool visit[N] = { false };


void paint(int v) {
	visit[v] = true;
	color[v]++;
	int i = 0;
	while (v < N&&i < a[v].size()) {
		if (color[v] == color[a[v][i]]) {
			color[v]++;
		}
		i++;
	}
}

void FillColor(int i) {
	switch (i) {
	case 1:
		cout << "[fillcolor=red, style=filled];";
		break;
	case 2:
		cout << "[fillcolor=green, style=filled];;";
		break;
	case 3:
		cout << "[fillcolor=moccasin, style=filled];";
		break;
	case 4:
		cout << "[fillcolor=honeydew, style=filled];";
		break;
	case 5:
		cout << "[fillcolor=white, style=filled];";
		break;
	case 6:
		cout << "[fillcolor=black, style=filled];";
		break;
	default:
		break;
	}
}
int main() {
	ifstream filein;
	filein.open("D:\\File\\color1.txt", ios_base::in);
	//int n, m;//n:vertex
	//         //m:edge
	//filein >> n;
	//filein >> m;
	cout << "Graph G {"<<endl;
	while (!filein.eof()) {
		int x, y;
		filein >> x;
		filein >> y;
		a[x].push_back(y);
		a[y].push_back(x);
		cout << x << "--" << y << endl;;
	}
	color[0] = 1;
	visit[0] = true;
	for (int i = 1; i < N; i++) {
		if (visit[i] == false)
			paint(i);
	}
	for (int i = 0; i < N; i++) {
		cout << i << " "; FillColor(color[i]);
		cout << endl;
	}
	cout << "}";
	system("pause");
	return 0;
}