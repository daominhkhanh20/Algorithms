#include<iostream>
#include<queue>
using namespace std;

int main() {
	queue<int>s;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		switch (x) {
		case 1:
			int k;
			cin >> k;
			s.push(k);
			break;
		case 2:
			s.pop();
			break;
		case 3:
			cout << s.front() << " ";
			break;
		}
	}

	system("pause");
	return 0;
}