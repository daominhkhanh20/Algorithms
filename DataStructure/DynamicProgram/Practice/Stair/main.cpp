#include<bits/stdc++.h>
using namespace std;
#define N 100000
#define ll long long

ll a[N];
int n;

ll countWay(int s,ll k){
    ll res=0;
    if(k==0){
        return 0;
    }
    else if(s==n){
        return 1;
    }

    for(int i=1;i<=k;i++){
        if(s+i>n){
            continue;
        }
        else{
            res+=countWay(s+i,a[s+i]);
        }
    }
    return res;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<countWay(1,a[1]);
    return 0;
}