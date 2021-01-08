#include<iostream>
using namespace std;

int a[3] = { 0,7,4 };//luu luong nuoc
int max[3] = { 10,7,4 };//luu dung tich
bool visited[10][10][10] = { false };

void find(int h1, int h2, int h3) {
	visited[h1][h2][h3] = true;
	if (h2 == 2 || h3 == 2) {
		cout << a[0] << " " << a[1] << " " << a[2] << endl;
		return;
	}
	else {
		cout << a[0] << " " << a[1] << " " << a[2] << endl;
		for (int i = 0; i < 3; i++) {

			if (a[i] < max[i] && a[(i + 1) % 3]>0) {
				int k = a[i];
				a[i] = a[i] + a[(i + 1) % 3] > max[i] ? max[i] : a[i] + a[(i + 1) % 3];
				a[(i + 1) % 3] = a[i] == max[i] ? k + a[(i + 1) % 3] - max[i] : 0;
				if (!visited[a[0]][a[1]][a[2]])
					find(a[0], a[1], a[2]);
				else {
					a[0] = h1;		a[1] = h2;		a[2] = h3;
				}
			}
			if (a[i] < max[i] && a[(i + 2) % 3]>0) {
				int k = a[i];
				a[i] = a[i] + a[(i + 2) % 3] > max[i] ? max[i] : a[i] + a[(i + 2) % 3];
				a[(i + 2) % 3] = a[i] == max[i] ? k + a[(i + 2) % 3] - max[i] : 0;
				if (!visited[a[0]][a[1]][a[2]])
					 find(a[0], a[1], a[2]);
			}
		}
	}
}

int main() {	
    find(0, 7, 4);
	system("pause");
	return 0;
}