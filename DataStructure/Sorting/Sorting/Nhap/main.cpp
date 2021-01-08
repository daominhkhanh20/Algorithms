#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int m[] = {-2,11,-4,13,-5,2 };
	int n = sizeof(m) / sizeof(int);
	
	int smax = m[0];
	int maxendhere = m[0];
	int imax = 1,u,v;
	for (int i = 1; i < n; i++) {
		u = maxendhere + m[i];
		v = m[i];
		if (u > v)
			maxendhere = u;
		else
			maxendhere = v;
		smax = maxendhere;
		imax = i;
	}
	cout << smax;
	system("pause");
	return 0;
}