#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;

int n,l1,l2;
int a[N],f[N];

void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>l1>>l2;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
}

void show(){
    for(int i=1;i<=n;i++){
        cout<<f[i]<<" ";
    }
}

void solve(){
    f[1]=a[1];
    int best=0;
    for(int i=2;i<=n;i++){
        if(i-l1>=1){
            for(int j=max(i-l2,1);j<=i-l1;j++){
                f[i]=max(f[i],f[j]+a[i]);
            }
        }
        else{
            f[i]=a[i];
        }
        best=max(best,f[i]);
    }
    cout<<best<<endl;
}

int main(){
    input();
    solve();
    return 0;
}