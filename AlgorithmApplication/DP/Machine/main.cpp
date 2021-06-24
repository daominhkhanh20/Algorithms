#include<bits/stdc++.h>
using namespace std;
const int N=2*1e6+3;
#define ll long long
ll F1[N]; // f[j] thời gian dài nhất kết thúc tại thời điểm j 
ll F2[N];//F2[i] là khoảng thời gian dài nhất kết thúc trước thời điểm i  
ll n,s[N],t[N];

void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>s[i]>>t[i];
}

void solve(){
    for(int i=1;i<=n;i++){
        F1[t[i]]=max(F1[t[i]],t[i]-s[i]);
    }
    for(int i=1;i<=N;i++){
        F2[i]=max(F2[i-1],F1[i]);//F2[i]=max(F1[i]--> F1[0])
    }
    ll best=0;//best=max(best,t[i]-s[i]+F2[s[i]-1])
    for(int i=1;i<=n;i++){
        best=max(best,t[i]-s[i]+F2[s[i]-1]);
    }
    cout<<best;
}

int main(){
    input();
    solve();
    return 0;
}