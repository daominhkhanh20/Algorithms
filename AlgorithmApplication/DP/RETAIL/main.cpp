#include<bits/stdc++.h>
using namespace std;
const int N=506;
int a[N];
int n,m;
int cnt=0;
const int Q=1e9+7;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
}

void solve(int index,int total){
    if(index==n+1){
        if(total==m)cnt++;
        return ;
    }
    int t=m/a[index];
    for(int i=1;i<=t;i++){
        total+=i*a[index];
        solve(index+1,total);
        total-=i*a[index];
    }
}

int main(){
    //freopen("in","r",stdin);
    input();
    //cout<<n<<m<<endl;
    solve(1,0);
    cout<<cnt%Q<<endl;
    return 0;
}