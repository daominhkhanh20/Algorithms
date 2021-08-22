#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
ull n,k,m;
struct MOD{
    ll d;
    ll x;
    ll y;
    MOD(ll _d=0,ll _x=0,ll _y=0):d(_d),x(_x),y(_y){}
};

MOD extend_euclid(ll a, ll b){
    if(b==0)return MOD(a,1,0);
    MOD temp=extend_euclid(b,a%b);
    MOD result=MOD(temp.d,temp.y,temp.x-a/b*temp.y);
    return result;
}

void find(ull n,ull k,ull m){
    ull a=1,b=1;
    for(int i=1;i<=k;i++){
        a=(a*(n-k+i))%m;
        b=(b*i)%m;
    }
    MOD temp=extend_euclid(b,m);
    if(temp.d!=1)cout<<"Doesn't exist";
    else{
        ll x=temp.x;
        if(x<0)x+=m;
        else x=x%m;
        cout<<(a*x)%m<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>k>>m;
        find(n,k,m);
    }
    return 0;
}



