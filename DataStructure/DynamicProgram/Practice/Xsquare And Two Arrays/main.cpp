//https://www.hackerearth.com/fr/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/xsquare-and-two-arrays/
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define N 100000
ll dp1[N],dp2[N];

void calculate(int n,ll a[],ll b[]){
	dp1[0]=0; dp1[1]=a[0];
	dp2[0]=0; dp2[1]=b[0];
	bool temp=true;
	for(int i=1;i<n;i++){
		if(temp){
			dp1[i+1]=b[i]+dp1[i];
			dp2[i+1]=a[i]+dp2[i];
		}
		else{
			dp1[i+1]=a[i]+dp1[i];
			dp2[i+1]=b[i]+dp2[i];
		}
		temp=!temp;
	}
}

int main(){
	int n,q;
	cin>>n>>q;
	ll a[n],b[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}

	calculate(n,a,b);
	
	while(q-->0){
		int m,l,r;
		cin>>m>>l>>r;
		if(m==1&&l%2==1||m==2 &&l%2==0){
			cout<<dp1[r]-dp1[l-1]<<endl;
		}
		else {
			cout<<dp2[r]-dp2[l-1]<<endl;
		}
	}

}