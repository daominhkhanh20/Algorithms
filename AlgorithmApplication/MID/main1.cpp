#include<bits/stdc++.h>
using namespace std;
int x[10];
bool visit[8];
#define N 15
int t;
int cnt=0;
int n;
bool check(int value,int index){
    if(visit[value])return false;
    if(index==1 && value==0)return false;
    if(index==2 && value==0)return false;
    if(index<6)return true;
    return x[1]*100000+x[2]*10000+x[3]*1000+x[4]*100+x[5]*10+x[2]+x[2]*1000+x[2]*100+value*10+x[3]==n;
}

void TRY(int index){
    for(int i=0;i<=9;i++){
        if(check(i,index)){
            visit[i]=true;
            x[index]=i;
            if(index==6)cnt++;
            else TRY(index+1);
            visit[i]=false;
        }
    }

}
void reset(){
    for(int i=0;i<=N;i++){
        visit[i]=false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    reset();
    cin>>n;
    TRY(1);
    cout<<cnt;
    return 0;
}