#include<bits/stdc++.h>
using namespace std;
#define N 200000
#define ll long long
ll dp[N][2];
int ans=0,n,arr[N];


ll make(int pos,int k){
    int a=1,b=1;
    if(dp[pos][k]!=-1){
        return dp[pos][k];
    }

    if(arr[pos+1]>arr[pos]&&pos!=n-1){
        a=make(pos+1,k)+1;
    }

    if(pos!=n-2&&arr[pos+2]>arr[pos]&&k==0){
        b=make(pos+2,k+1)+1;
    }

    return dp[pos][k]=max(a,b);

}

int main(){
    memset(dp,-1,sizeof(dp));
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        int k=make(i,0);
        ans=max(ans,k);
    }
    cout<<ans<<endl;
    return 0;
}