#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long 
ull M=10e9+5;
#define N 105
ull n,k;
ull cnt=1;
void solve(){
    for(ull i=1;i<k;i++){
        cnt*=(n+i)*1.0/i;
    }
}
int main(){
    cin>>n>>k;
    solve();
    cnt=cnt%M;
    cout<<cnt<<endl;
    return 0;
}

