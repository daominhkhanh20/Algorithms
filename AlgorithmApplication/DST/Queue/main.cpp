#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int a[N],result[N];
int n;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    memset(result,-1,sizeof(result));
}

void solve(){
    for(int i=1;i<n;i++){
        for(int j=n;j>=i+1;j--){
            if(a[j]<a[i]){
                result[i]=j-i-1;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<result[i]<<" ";
}

int main(){
    input();
    solve();
    return 0;
}