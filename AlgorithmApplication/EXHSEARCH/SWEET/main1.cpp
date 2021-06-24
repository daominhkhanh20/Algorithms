#include<bits/stdc++.h>
using namespace std;

const int N=105;
#define ll long long
ll a[N][N];
const int M=1e9+7;
int cal(int x,int y){
    if(y==0 || x==y)return 1;
    for(int i=1;i<=x;i++){
        for(int j=0;j<=i;j++){
            if(j>y)continue;
            if(j==0 || j==i)a[i][j]=1;
            else{
                a[i][j]=(a[i-1][j]+a[i-1][j-1])%M;
            }
        }
    }
    return a[x][y];
}

int main(){
    int n,k;
    cin>>n>>k;
    cout<<cal(n+k-1,k-1);
    return 0;
}