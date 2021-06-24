#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define N 10000
int t;

int main(){
    cin>>t;
    for(int j=1;j<=t;j++){
        int n;
        cin>>n;
        vector<ll>x,y;
        ll k,h;
        for(int i=0;i<n;i++){
            cin>>k;
            x.push_back(k);
        }
        for(int i=0;i<n;i++){
            cin>>h;
            y.push_back(h);
        }

        sort(x.begin(),x.end());
        sort(y.begin(),y.end(),greater<int>());
        ll s=0;
        for(int i=0;i<n;i++){
            s+=x[i]*y[i];
        }
        cout<<"Case #"<<j<<": "<<s<<endl;
    }
    return 0;
}