#include<bits/stdc++.h>
using namespace std;
int t,n,m;
const int N=101;
#define ll long long 
vector<int>a;
int main(){
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        ll x;
        for(int i=1;i<=n;i++){
            cin>>x;
            a.push_back(x);
        }
        cin>>m;
        int cnt=0;
        for(int i=1;i<=m;i++){
            cin>>x;
            if(find(a.begin(),a.end(),x)!=a.end())cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}