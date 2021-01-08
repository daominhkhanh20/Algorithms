#include <iostream>      
#include <stack>          
using namespace std;

int max(stack<int>s, int n, int k) {
	int max = s.top(), m[50], a = 0;
	for (int i = 1; i < k; i++) {
		int x = s.top();
		s.pop();
		m[a] = x;
		a++;
	}
	for (int i = 0; i < a; i++) {
		if (m[i] >= max) {
			max = m[i];
		}
	}
	s.push(max);
	return s.top();
}
int main() {
	stack<int>s;
	int m[50], n, k;
	cin >> n;
	cin >> k;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		m[i] = k;
	}
	for (int i = n; i >= 1; i--) {
		s.push(m[i]);
	}
	cout << max(s, n, k);
	system("pause");
	return 0;
}