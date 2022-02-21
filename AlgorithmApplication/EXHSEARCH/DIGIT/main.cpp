#include<bits/stdc++.h>
using namespace std;
#define N 10000
int n,x[8];
bool visit[11];
bool check(int v,int k){
    if(visit[v])return false;
    if(k<7)return true;
    return (x[0]*(1e6-1e4)+x[1]*1e5+x[2]*(1e4+1e3-1e6)+x[3]*(1e2-1e3)+x[4]*10+x[5]-x[6]*1e5-v*1e2-19)==n;
}

int cnt=0;
void solution(){
    cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<" "<<x[3]<<" "<<x[4]<<" "<<x[5]<<" "<<x[6]<<" "<<x[7]<<" "<<endl;
    cnt++;
}
void Try(int k){
    int start=0;
    if(k==0||k==2)start=1;
    for(int i=start;i<10;i++){
        if(check(i,k)){
            x[k]=i;
            visit[i]=true;
            if(k==7)solution();
            else Try(k+1);
            visit[i]=false;
        }
    }
}
int main(){
    cin>>n;
    Try(0);
    cout<<cnt;
    return 0;
}
