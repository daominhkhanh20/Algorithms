//https://vn.spoj.com/problems/NKSEQ/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll n;
	cin>>n;
	vector<ll>s(n+1);
	s[0]=0;
	for (int i=1;i<=n;i++){
		cin>>s[i];
		s[i]+=s[i-1];
	}
	//array m[0..n]
	/*s[k]=m[0]+m[1]+...+m[k]
	 * find i satisfied:
	 * s[k]-s[i-1]>0 i<=k
	 * s[k]+s[n-1]-s[i-1]>0  k<i
	 * */
	vector<bool>f(n+1),g(n+1);
	//condition 1:
    ll smin=s[n];
	for(int i=n;i>0;i--){
		f[i]=s[i-1]<smin; //smin=min(s[i],s[i+1],s[n])
		smin=min(smin,s[i-1]);
	}
    //condition 2:
	smin=s[n];
	for(int i=1;i<=n;i++){
		g[i]=s[i-1]<smin;
		smin=min(smin,s[i]+s[n]);
	}
	int count=0;
	for(int i=1;i<=n;i++){
		count+=f[i]&&g[i];
	}
	cout<<count;
	return 0;
	
}
