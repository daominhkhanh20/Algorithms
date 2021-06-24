#include<bits/stdc++.h>
using namespace std;
int t,n,m;
const int N=101;
#define ll long long 
ll a[N];
int main(){
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        ll res,x;
        for(int i=1;i<=n;i++){
            cin>>x;
            if(i==1){
                res=(1<<x);
            }
            else res|=(1<<x);
        }
        cin>>m;
        int cnt=0;
        for(int i=1;i<=m;i++){
            cin>>x;
            if(res&(1<<x))cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}