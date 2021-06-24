#include<bits/stdc++.h>
using namespace std;
int t,n;
#define N 15
bool visit[N];
int x[N];
int result;
void update(){
    //cout<<x[0]<<x[1]<<x[2]<<x[3]<<"+"<<x[2]<<x[4]<<x[5]<<x[6]<<x[3]<<"="<<n<<endl;
    result++;
}
bool check(int value,int index){
    if(visit[value])return false;
    if(index==0 && value==0)return false;
    if(index==2 && value==0)return false;
     if(index<6)return true;
    int a=x[0]*1000+x[1]*100+x[2]*10+x[3]+x[2]*10000+x[4]*1000+x[5]*100+value*10+x[3];
    return a==n;
}
void solve(int index){
    for(int i=0;i<=9;i++){
        if(check(i,index)){
            x[index]=i;
            visit[i]=true;
            if(index==6)update();
            else solve(index+1);
            visit[i]=false;
        }
    }
}
void reset(){
    for(int i=0;i<=6;i++)x[i]=0;
    for(int i=0;i<=9;i++)visit[i]=false;
}
int main(){
    cin>>t;
    for(int i=0;i<t;i++){
        reset();
        result=0;
        cin>>n;
        solve(0);
        cout<<result<<endl;
    }
    return 0;
}
