#include<bits/stdc++.h>
using namespace std;
const int M=1e9+7;
int n,k1,k2;
#define N 10005
#define ll long long
int x[N];
ll segment[N];
ll result=0;
bool check(int value,int index){
    if(index==1)return true;
    if(value==0){
        if(segment[index-1]<k1)return false;
    }
    if(value==1 ){
        if(index==n){
            if(segment[index-1]+1<k1|| segment[index-1]+1>k2)return false;
        }
        else if(segment[index-1]+1>k2)return false;
    }
    return true;
    
}

void show(){
    for(int i=1;i<=n;i++){
        cout<<x[i]<<" ";
    }
    cout<<endl;
}
void TRY(int index){
    for(int v=0;v<=1;v++){
        if(check(v,index)){
            x[index]=v;
            segment[index]=v==1?++segment[index-1]:0;
            if(index==n){
                show();
                result++;
                result=result%M;
            }
            else TRY(index+1);
            if(v==1)segment[index]--;
        }
    }
}

int main(){
    cin>>n>>k1>>k2;
    if(k1>n)cout<<0<<endl;
    else{
        TRY(1);
        cout<<result;
    }
    return 0;
}
