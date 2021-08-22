#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=1e6+5;
ll n,m;
ll a[N];
ll max_height;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    max_height=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        max_height=max(a[i],max_height);
    }
}

void solve(){
    ll left=0,right=max_height,result;
    while(left<=right){
        ll mid=(right+left)/2;
        ll count_curr=0;
        for(int i=1;i<=n;i++){
            count_curr+=a[i]>mid?a[i]-mid:0;
        }
        if(count_curr>=m){
            left=mid+1;
            result=mid;
        }
        else right=mid-1;

    }
    cout<<result<<endl;
}

int main(){
    input();
    solve();
    return 0;
}