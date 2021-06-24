#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
const int N =1e6+1;
ll x[N];
bool check(int h){
    ll s=0;
    for(int i=1;i<=n;i++){
        if(x[i]>h){
            s+=x[i]-h;
            if(s>=m)return true;
        }
    }
    return false;
}

void find(){
    ll l=0,r=2e9+1;
    ll result=0;
    while(l<=r){
        ll mid=(r+l)/2;
        if(check(mid)){
            l=mid+1; 
            result=mid;
        }
        else{
            r=mid-1;
        }
    }
    cout<<result<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    find();
    return 0;
}