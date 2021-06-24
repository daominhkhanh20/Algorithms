#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(ll n,ll k,ll m){
    ll f[k+1];
    memset(f,0,sizeof(f));
    f[0]=1;
    k=min(k,n-k);
    for(ll i=1;i<=n;i++){
        for(ll j=min(i,k);j>0;j--){
            f[j]=(f[j]+f[j-1])%m;
        }
    }
    cout<<f[k]<<endl;
}
int main(){
    int t;
    ll n,k,m;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>k>>m;
        solve(n,k,m);
    }
    return 0;

}
