#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,m,k,final_sum,final_mid;
ll a[505];

void input(){
    cin>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
}

int is_valid(ll mid){
    ll i=1,count=0,sum=0,max_curr=INT_MIN;
    while(i<=m && count<=k-1){
        sum+=a[i];
        if(sum>mid){
            max_curr=max(max_curr,sum-a[i]);
            count++;
            sum=a[i];
        }
        //cout<<sum<<" "<<count<<endl;
        i++;
    }
    if(i<m){
        ll temp=0;
        for(int j=i;j<=m;j++)temp+=a[i];
        max_curr=max(max_curr,temp);
    }
    if(count>k-1){
        if(max_curr<=final_sum){
            final_sum=max_curr;
            final_mid=mid;
        }
        return 1;
    }
    return 0;
}
void print_solution(int mid){
    ll sum=0,count=0;
    for(int i=1;i<=m;i++){
        sum+=a[i];
        if(sum>=mid && count<k-1){
            cout<<" / ";
            sum=a[i];
            count++;
        }
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void solve(){
    ll left=0,right=5*1e9;
    final_sum=INT_MAX;
    final_mid=0;
    while(left<=right){
        ll mid=(left+right)/2;
        int check=is_valid(mid);
        if(check==1){
            left=mid+1;
        }
        else right=mid-1;
        cout<<mid<<" "<<final_sum<<" "<<final_mid<<endl;
    }
    cout<<final_sum<<endl;
    print_solution(final_mid);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    for(int i=1;i<=t;i++){
        memset(a,0,sizeof(a));
        input();
        solve();
    }
    return 0;
}
