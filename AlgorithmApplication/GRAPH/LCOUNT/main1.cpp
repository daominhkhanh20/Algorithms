#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
map<int,int>a;
int n;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        a[x]++;
        a[y]++;
    }
}
void solve(){
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(a[i]==1)cnt++;
    }
    cout<<cnt<<endl;
}
int main(){
    input();
    solve();
    return 0;
}