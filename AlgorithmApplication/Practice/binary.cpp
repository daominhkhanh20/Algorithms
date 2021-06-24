#include<bits/stdc++.h>
using namespace std;
const int N= 100;
int n;
int a[N];

bool check(int v,int k){
    if(k==0)return true;
    if(v==1 && a[k-1]==1)return false;
    return true;
}
void print(){
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
    cout<<endl;
}
void TRY(int index){
    for(int i=0;i<2;i++){
        if(check(i,index)) {
            a[index]=i;
            if(index==n-1)print();
            TRY(index+1);
        }
    }
}
int main(){
    cin>>n;
    TRY(0);
    return 0;
}
