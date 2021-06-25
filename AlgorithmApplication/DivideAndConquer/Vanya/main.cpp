#include<bits/stdc++.h>
using namespace std;
const int N=1005;
#define ll long long 
ll a[N];
ll n,l;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>l;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
}

void solve(){
    float temp=0.0;
    for(int i=1;i<=n;i++){
        if(i==1 && a[i]==0)continue;
        else if(i==1 && a[i]!=0)temp=max(temp,float(a[i]));
        else if(i>1){
            temp=max(temp,float(a[i]-a[i-1])/2);
        }
    }
    if(a[n]!=l)temp=max(temp,float(l-a[n]));
    printf("%0.9f",temp);
}

int main(){
    input();
    solve();
    return 0;
}