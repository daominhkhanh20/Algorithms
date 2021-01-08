//https://www.hackerearth.com/fr/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/ultimate-stairway-to-heaven/description/
//not opimize
//calculate very slow
#include<bits/stdc++.h>
using namespace std;
#define N 100000
#define ll long long 
ll dp[N];
ll minWayToReachTheTop(ll a[],int n,int step){
	if(step==n-1)
		return 1;
	else if(step>=n)
		return 0;
	else if(dp[step]!=-1)
		return dp[step];
	ll ans=0;
	for(int i=1;i<=a[step];i++){
		ans+=minWayToReachTheTop(a,n,step+i);
		ans=ans%1000000007;
	}
	return ans;
}
int main(){
	int n;
	cin>>n;
	ll a[n];
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<minWayToReachTheTop(a,n,0);
	return 0;
}