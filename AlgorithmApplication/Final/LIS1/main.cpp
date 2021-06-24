#include<bits/stdc++.h>
using namespace std;
#define ll long long 
map<ll,ll>a;
int t,n;
const int N=1e5+6;
vector<int>b;
ll res=0;

void solve(){
    for(int i=0;i<b.size();i++){
        ll temp=b[i];
        if(a[temp-1]==0 && a[temp]==0)a[temp]=1;
        else if(a[temp-1]!=0)a[temp]=a[temp-1]+1;
        res=max(a[temp],res);
    }
    cout<<res<<endl;
}
int main(){
    cin>>t;
    for(int i=1;i<=t;i++){
        res=0;
        a.clear();
        b.clear();
        cin>>n;
        ll x;
        for(int i=1;i<=n;i++){
            cin>>x;
            b.push_back(x);
        }
        solve();        
    }
    return 0;
}