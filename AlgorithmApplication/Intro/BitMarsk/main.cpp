#include<bits/stdc++.h>
using namespace std;

vector<int>b;
int n,m,res;
bool check(){
    for(int i=0;i<b.size();i++){
        int a=b[i];
        if(res&(1<<a))continue;
        return false;
    }
    return true;
}
int main(){
    cin>>n;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        if(i==0)res=(1<<x);
        else res|=(1<<x);
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>x;
        b.push_back(x);
    }
    bool t=check();
    if(t)cout<<1<<endl;
    else cout<<0;
    return 0;
}
