#include<bits/stdc++.h>
using namespace std;
int n,k;
const int N=5001;
map<int,int>x;
int a[N];

int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        x[a[i]]+=1;
    }
    int cnt=0;

    cout<<cnt<<endl;
    return 0;
}