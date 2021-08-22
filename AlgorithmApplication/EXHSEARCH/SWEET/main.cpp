#include<bits/stdc++.h>
using namespace std;
const int M=1e9+7;
#define ll long long
struct MOD{
    int d,x,y;
    MOD(int _d,int _x, int _y):d(_d),x(_x),y(_y){}
};

MOD expand_euclid(int a,int b){
    if(b==0)return MOD(a,1,0);
    MOD temp=expand_euclid(b,a%b);
    return MOD(temp.d,temp.y,temp.x-a/b*temp.y);
}

void solve(int n,int k){
    ll a=1,b=1;
    for(int i=1;i<=k;i++){
        a=((n-k+i)*a)%M;
        b=(b*i)%M;
    }
    MOD result=expand_euclid(b,M);
    if(result.x<0){
        cout<<a*(result.x+M)%M<<endl;
    }
    else{
        cout<<a*result.x%M<<endl;
    }
}
int main(){
    int n,k;
    cin>>n>>k;
    solve(n+k-1,k-1);
    return 0;
}

