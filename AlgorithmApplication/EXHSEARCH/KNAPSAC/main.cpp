#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 30
#define B 1000000
int n,b;
long long f[N+1][B+1],w[N+1],v[N+1];
ll cal(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=b;j++){
            if(j<w[i])f[i][j]=f[i-1][j];// if we don't choose the i-th bag
            else f[i][j]=max(f[i-1][j],v[i]+f[i-1][j-w[i]]);// if we choose the i-th bag
        }
    }
    return f[n][b];
}
int main(){
    cin>>n>>b;
    long long a,c;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        w[i]=a;
        v[i]=c;
    }
    cout<<cal();
    return 0;
}
