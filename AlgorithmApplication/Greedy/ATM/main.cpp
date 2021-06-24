#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long 
int fn[]={0,1,1,1,2,1,2,2,2,3};
int fs[]={1,1,1,1,2,1,2,1,1,3};
ll t,w,c;

void solve(){
    ll res_n=0;
    ll res_s=1;
    ll w2=w;
    for(int i=0;i<c;i++){
        ll temp=w2%10;
        w2/=10;
        res_n+=fn[temp];
        res_s*=fs[temp];
    }
    if (w2>0){
        ll temp=w2%10;
        w2-=temp;
        if(w2>0 && temp<5){
            temp+=5;
            w2-=5;
        }
        res_n+=fn[temp];
        res_s*=fs[temp];
    }
    res_n+=w2/5;
    cout<<res_n<<" "<<res_s<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>w>>c;
        if(w%1000!=0){
            cout<<0<<endl;
            continue;
        }
        w=w/1000;
        solve();
    }
    return 0;
}