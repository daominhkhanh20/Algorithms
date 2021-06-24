#include<bits/stdc++.h>
using namespace std;
int t,n,result;
bool visit[11];
int x[8];


bool check(int value,int index){
    if(visit[value])return false;
    if(index<7)return true;
    return (x[1]*1000+x[2]*100+x[3]*10+x[4]+x[3]*10000+x[5]*1000+x[6]*100+value*10+x[4])==n;
}

void show(){
    cout<<x[1]<<x[2]<<x[3]<<x[4]<<"+"<<x[3]<<x[5]<<x[6]<<x[7]<<x[4]<<"="<<n<<endl;
}
void TRY(int index){
    for(int i=1;i<=9;i++){
        if(check(i,index)){
            visit[i]=true;
            x[index]=i;
            if(index==7){
                result++;
                show();
            }
            else TRY(index+1);
            visit[i]=false;
        }
    }
}

void reset(){
    for(int i=0;i<=8;i++)x[i]=0;
    for(int i=0;i<=9;i++)visit[i]=false;
}

int main(){
    cin>>t;
    while(t--){
        reset();
        cin>>n;
        result=0;
        TRY(1);
        cout<<result<<endl;
    }

}