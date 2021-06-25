#include<bits/stdc++.h>
using namespace std;
int n,m,k;
//dp[i][j]: we assign i-th,(i+1)th,...,n-th books for j subcribers to to this job
//pages[i]: number page for book i-th
int dp[502][502],pages[502];
const int MAX=1e9+2;
int recursive(int position,int n_subs){
    if(position>m){
        if(n_subs==0)return 0;
        return MAX;
    }
    else if(n_subs==0){
        if(position>m)return 0;
        return MAX;
    }

    if(dp[position][n_subs]!=-1)return dp[position][n_subs];
    int ans=MAX,sum=0;
    for(int i=position;i<=m;i++){
        sum+=pages[i];
        ans=min(ans,max(sum,recursive(i+1,n_subs-1)));
    }
    dp[position][n_subs]=ans;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        memset(dp,-1,sizeof(dp));
        cin>>m>>k;
        for(int j=1;j<=m;j++){
            cin>>pages[j];
        }
        recursive(1,k);
        int start=1;
        while(start<=m){
            int pos=-1,sum=0,ans=MAX;
            for(int j=start;j<=m;j++){
                sum+=pages[j];
                int temp=recursive(j+1,k-1);
                if(ans>max(sum,temp)){
                    ans=temp;
                    pos=j;
                }
            }
            k-=1;
            for(int j=start;j<=pos;j++)cout<<pages[j]<<" ";
            if(pos==m)break;
            cout<<" / ";
            start=pos+1;
        }
        cout<<endl;
    }
    return 0;
}