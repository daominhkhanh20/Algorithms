#include<bits/stdc++.h>
using namespace std;
long long MOD=1e9+7;

int main(){
    unsigned long long  a,b,c,d;
    cin>>a>>b;
    c=a%MOD;
    d=b%MOD;
    d+=c;
    cout<<d%MOD;
    return 0;
}
