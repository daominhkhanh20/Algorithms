#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
#define ll long long
deque<pair<int,int>>de;
int n,l1,l2;
ll a[N],f[N];
void input(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>l1>>l2;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
}

void solve(){
	for(int i=0;i<n;i++){
		while(de.size()>0 && i-de.front().first>l2) de.pop_front();

		if(i-l1>=0){
			while(de.size()!=0 && de.back().second <=f[i-l1])de.pop_back();

			de.push_back({i,f[i-l1]});
		}

		f[i]=a[i];
		if(de.size()>0)f[i]+=de.front().second;
	}
	ll res=0;
	for(int i=0;i<n;i++)res=max(res,f[i]);
	cout<<res<<endl;
}

int main(){
	input();
	solve();
	return 0;
}