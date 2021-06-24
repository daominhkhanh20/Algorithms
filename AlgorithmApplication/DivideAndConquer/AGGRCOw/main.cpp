#include<bits/stdc++.h>
using namespace std;
int n,c;
#define N 100000+1
int x[N];
void input(){
    cin>>n>>c;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
}

bool check(int d){
    int temp=x[1],cnt=1;
    for(int i=2;i<=n;i++){
        if(x[i]-temp>=d){
            cnt++;
            temp=x[i];
        }
        if(cnt==c)return true;
    }
    return false;
}
void solve(){
     sort(x+1,x+n+1);
    int l=0,r=1e9;
    int result;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            l=mid+1;
            result=mid;
        }
        else{
            r=mid-1;
        }
        //cout<<l<<" "<<mid<<" "<<r<<endl;
    }
    cout<<result<<endl;
}
int main(){
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        input();
        solve();
    }
}