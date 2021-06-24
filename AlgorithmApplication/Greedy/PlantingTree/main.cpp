#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int a[N];
int n;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
}

void solve(){
    ll result=1;
    sort(a+1,a+n+1,greater<int>());
    for(int i=1;i<=n;i++){
        if(i+a[i]>result)result=i+a[i];
    }
    cout<<result+1<<endl;
}

int main(){
    input();
    solve();
    return 0;
}