#include<bits/stdc++.h>
using namespace std; 
#define N 20005
#define ll long long 
ll x[N];
int main(){
    int n,m,M;
    cin>>n>>m>>M;

    for(int i=1;i<=n;i++){
        cin>>x[i];
        x[i]+=x[i-1];
        //cout<<x[i]<<" ";
    }
    ll count=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            if(x[i]-x[j]>=m && x[i]-x[j]<=M)count++;
        }
    }
    cout<<count;
    return 0;    
}