#include<bits/stdc++.h>
using namespace std;
const int N= 100;
int n;
int a[N];

void print(){
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
    cout<<endl;
}
void TRY(int index){
    for(int i=0;i<2;i++){
        a[index]=i;
        if(index==n-1)print();
        else TRY(index+1);
    }
}
int main(){
    cin>>n;
    TRY(0);
    return 0;
}
