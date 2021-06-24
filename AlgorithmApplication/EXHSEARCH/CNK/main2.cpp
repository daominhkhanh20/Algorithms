#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int 
 
ll inverse(ll y, ll m){
    i
}
ll cal(ll x,ll y,ll m){
    ll y_inverse=inverse(y,m);
    return mul(x,y,m);

}
void solve(ll n,ll k,ll m){
    ll x=1,t;
    for(ll i=1;i<=k;i++){
        //calculate (n-k+i)/i <==>(n-k+i)*i^-1
        t=cal(n-k+i,i,m);
        //x=x*t
        x=mul(x,t);
    }
    cout<<x<<endl;
}
int main(){
    int t;
    cin>>t;
    ll n,m,k;
    for(int i=0;i<t;i++){
        cin>>n>>k>>m;
        solve(n,m,k);
    }
    return 0;
}
