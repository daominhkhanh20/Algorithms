#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
vector<int>a[N];
int n;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int x,y;
    for(int i=1;i<=n-1;i++){
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
}
void solve(){
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(a[i].size()==1)cnt++;
    }
    if(a[1].size()==1)cnt--;
    cout<<cnt;
}

int main(){
    input();
    solve();
    return 0;
}