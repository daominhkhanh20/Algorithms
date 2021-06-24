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
    if(index==5 && value==0)return false;
    if(index<7)return true;
    return x[1]*100000+x[2]*10000+x[3]*1000+x[4]*100+x[5]*10+x[6]+x[6]*1000+x[6]*100+value*10+x[3]==n;
}

void TRY(int index){
    for(int i=0;i<=9;i++){
        if(check(i,index)){
            visit[i]=true;
            x[index]=i;
            if(index==7)cnt++;
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
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        reset();
        cnt=0;
        TRY(1);
        cout<<cnt<<endl;
    }
    return 0;
}