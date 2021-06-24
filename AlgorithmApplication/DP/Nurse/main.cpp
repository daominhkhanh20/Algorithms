#include<bits/stdc++.h>
using namespace std;

int n,k1,k2;
const int N=1001;
int x[N];
int cnt;
const int M=1e9+7;
void TRY(int value,int index,int len){
    if(index==n){
        if(value==0 && len>=k1 && len<=k2){
            cnt++;
            // for(int i=1;i<=n-1;i++)cout<<x[i]<<" ";
            // cout<<value<<endl;
        }
        else if(value==1){
            len++;
            if(len>=k1 && len<=k2){
                cnt++;
                // for(int i=1;i<=n-1;i++)cout<<x[i]<<" ";
                // cout<<value<<endl;
            }
        }
        return ;
    }
    x[index]=value;
    len=(value==1)?len+1:0;

    if(len>k2)return ;
    else if(len<k1)TRY(1,index+1,len);
    else{
        TRY(1,index+1,len);
        TRY(0,index+1,len);
    }
}
int main(){
    cin>>n>>k1>>k2;
    TRY(0,1,0);
    TRY(1,1,0);
    cout<<cnt%M;
    return 0;
}