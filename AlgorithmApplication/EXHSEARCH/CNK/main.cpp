#include<bits/stdc++.h>
using namespace std;
#define N 102
int a[N][N];

int solve(int n,int k,int m){
    if(n==k)return 1;
    if(k==0) return 1;
    else if(k==1)return n;
    if(a[n][k]!=0)return a[n][k];
    a[n][k]=solve(n-1,k,m)+solve(n-1,k-1,m);
    return a[n][k]%m;
}

int main(){
    int t;
    cin>>t;
    int n,k,m;
    for(int i=1;i<=t;i++){
        memset(a,0,sizeof(a[0][0])*N*N);
        cin>>n>>k>>m;
        cout<<solve(n,k,m)<<endl;
    }
    return 0;
}