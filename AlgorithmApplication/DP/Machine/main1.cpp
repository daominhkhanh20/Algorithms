#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n,F1[N],F2[N],s[N],t[N];

void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i]>>t[i];
    }
}

void solve(){
    for(int i=1;i<=n;i++)F1[t[i]]=max(F1[t[i]],t[i]-s[i]);
    for(int i=1;i<=N;i++)F2[i]=max(F2[i-1],F1[i]);
    int result=INT_MIN;
    for(int i=1;i<=n;i++)result=max(result,t[i]-s[i]+F2[s[i]-1]);
    cout<<result<<endl;
}
int main(){
    input();
    solve();
    return 0;
}