#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m;
int x[N],y[N],f[N][N];

void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    for(int j=1;j<=m;j++)cin>>y[j];
}
void solve(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i]==y[j])f[i][j]=f[i-1][j-1]+1;
            else f[i][j]=max(f[i-1][j],f[i][j-1]);
        }
    }
    cout<<f[n][m];
}
int main(){
    input();
    solve();
    return 0;
}