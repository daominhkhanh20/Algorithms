#include<bits/stdc++.h>
using namespace std;
#define N 10000
int n,x[7];
bool visit[11];
bool check(int v,int k){
    if(visit[v])return false;
    if(k<6)return true;
    return (x[0]*100+x[1]*10+x[2]-x[3]*100-62+x[4]*1000+x[5]*100+v*10+x[2])==n;
}

int cnt=0;
void solution(){
    cnt++;
}
void Try(int k){
    for(int i=1;i<10;i++){
        if(check(i,k)){
            x[k]=i;
            visit[i]=true;
            if(k==6)solution();
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
