#include<bits/stdc++.h>
using namespace std; 
#define N 1001

int n,T,D;
int a[N],t[N],f[N][101];

void input(){
    cin>>n>>T>>D;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>t[i];
    }
}

void solve(){
    int best=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=T;j++){
            if(j>=t[i]){
                for(int k=i-1; (k>=i-D) && (k>0); k--){
                    f[i][j]=max(f[i][j],f[k][j-t[i]]);
                }
                f[i][j]+=a[i];
            }
            best=max(best,f[i][j]);
        }
    }
    cout<<best;
}

int main(){
    input();
    solve();
    return 0;
}