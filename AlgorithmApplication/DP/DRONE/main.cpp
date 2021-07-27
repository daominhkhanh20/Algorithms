#include<bits/stdc++.h>
using namespace std;
const int N=3005;
const int K=105;
int f[N][K],c[N],a[N];
int n,k;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
}
void show(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k+1;j++){
            cout<<f[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void solve(){
    for(int i=1;i<=n;i++){
        f[1][i]=c[1];
    }
    for(int i=2;i<=n;i++){
        for(int j=2;j<=k+1;j++){
            int temp=INT_MIN;
            for(int x=1;x<=i;x++){
                if(a[i-x]>=x && f[i-x][j-1]!=0){
                    temp=max(temp,f[i-x][j-1]+c[i]);
                }
            }
            f[i][j]=max(temp,0);
        }
    }
    show();
    int temp=0;
    for(int i=1;i<=k+1;i++)temp=max(temp,f[n][i]);
    if(temp==0)cout<<-1;
    else cout<<temp;
}
int main(){
    input();
    solve();
    return 0;
}
