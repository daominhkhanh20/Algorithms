#include<bits/stdc++.h>
using namespace std;
int f[105][505];
const int N=1e9+7;
int n,m,a[105];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    f[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=j;k++){
                if(k%a[i]==0)f[i][j]=(f[i][j]+f[i-1][j-k])%N;
            }
        }
    }
    cout<<f[n][m]<<endl;
    return 0;
}