#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
ull MOD= 1e9+7;
int main(){
    ull a,b;
    cin>>a>>b;
    a=a%MOD;
    ull res=1;
    for(ull i=b;i;i>>=1){
        if(i&1)res=(res*a)%MOD;
        a=(a*a)%MOD;
    }
    cout<<res<<endl;
    return 0;
    
}
