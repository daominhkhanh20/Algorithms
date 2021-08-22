#include<bits/stdc++.h>
using namespace std;
int n,k1,k2;
const int M=1e9+7;
const int N=1005;
int s0[N];//so cach xem cho i ngay dau voi ngay thu i la ngay nghi 
int s1[N];//so cach xep cho i ngay dau voi ngay thu i la ngay lam viec
void solve(){
    for(int i=0;i<=n;i++){
        s0[i]=s1[i]=0;
    }
    s0[0]=s0[1]=1;
    s1[k1]=1;
    for(int i=k1+1;i<=n;i++){
        s0[i]=s1[i-1];
        for(int j=k1;j<=k2;j++){
            if(i-j>=0)s1[i]+=s0[i-j];
        }
    }
    cout<<s0[n]+s1[n];
}
int main(){
    cin>>n>>k1>>k2;
    solve();
    return 0;
}