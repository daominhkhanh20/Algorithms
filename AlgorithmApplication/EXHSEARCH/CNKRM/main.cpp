#include<bits/stdc++.h>
using namespace std;

const int N=1e9+7;
int a[1001][1001];

int solve(int n,int k){
    if(n==k)return 1;
    if(k==0) return 1;
    else if(k==1)return n;
    if(a[n][k]!=0)return a[n][k]%N;
    a[n][k]=solve(n-1,k)+solve(n-1,k-1);
    return a[n][k]%N;
}

int main(){
    int n,k;
    cin>>k>>n;
    cout<<solve(n,k);
    return 0;
}