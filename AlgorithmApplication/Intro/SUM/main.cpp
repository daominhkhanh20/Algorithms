#include<bits/stdc++.h>
using namespace std;

long long MOD=1e9+7;
int main(){
    int n,x;
    long long s=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        s=(s+x)%MOD;
    }
    cout<<s;
    return 0;
}