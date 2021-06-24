#include<bits/stdc++.h>
using namespace std;
#define N 1000000+5
int a[N],s[N];
int n;
bool solved[N];
int dp(int index){
    if(index==1){
        s[1]=a[1];
    }
    else{
        if(!solved[index]){
            s[index]=max(a[index],dp(index-1)+a[index]);
        }
    }
    solved[index]=true;
    return s[index];
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=INT_MIN;
    for(int i=1;i<=n;i++){
        int temp=dp(i);
        ans=max(ans,temp);
    }
    cout<<ans<<endl;
    return 0;
}
