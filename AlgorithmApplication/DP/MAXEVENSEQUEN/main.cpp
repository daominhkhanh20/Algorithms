#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int a[N],s[N];
int n;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
}
void solve(){
    int result=INT_MIN;
    for(int i=1;i<n;i++){
        for(int j=i;j<=n;j++){
            int temp=s[j]-s[i-1];
            if(temp%2==0 &&temp>result){
                result=temp;
            }
        }
    }
    if(result==INT_MIN)cout<<"NOT_FOUND";
    else cout<<result;
}

int main(){
    input();
    solve();
    return 0;
}