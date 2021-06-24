#include<bits/stdc++.h>
using namespace std;
const int NMAX=501;
int N,m,k;
int x[NMAX];
int d[NMAX],store[NMAX];
bool check(int mid){
    int sum=0,cnt=0;
    memset(d,0,sizeof(d));
    for(int i=1;i<=m;i++){
        if(x[i]>mid)return false;
        sum+=x[i];
        if(sum>mid){
            d[cnt]=i-1;
            cnt++;
            sum=x[i];
        }
    }
    cnt++;
    cout<<cnt<<" "<<mid<<endl;
    if(cnt==k){
        return true;
    }
    return false;


}
void solve(){
    int *max=max_element(x,x+m+1);
    int start=*max;
    int end=0;
    for(int i=1;i<+m;i++){
        end+=x[i];
    }

    while(start<end){
        int mid=(start+end)/2;
        if(check(mid)){
            for(int i=1;i<=m;i++)store[i]=d[i];
        }
        end=mid-1;
    }
    // int curr=0;
    // for(int i=1;i<=m;i++){
    //     cout<<x[i]<<" ";
    //     if(d[curr]==i){
    //         cout<<"  / ";
    //         curr++;
    //     }
    // }
    // cout<<endl;
}

int main(){
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>m>>k;
        for(int j=1;j<=m;j++){
            cin>>x[j];
        }
        solve();
    }
    return 0;
}