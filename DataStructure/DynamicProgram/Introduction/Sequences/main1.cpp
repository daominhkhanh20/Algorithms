#include<bits/stdc++.h>
using namespace std;
#define N 100000
#define ll long long
ll m[N],a[N],b[N];
ll sequence(int n){
    a[0]=1;
    for(int i=1;i<n;i++){
        if(m[i]>m[i-1]){
            a[i]=a[i-1]+1;
        }
        else{
            a[i]=1;
        }
    }
    b[n-1]=1;
    for(int i=n-2;i>=0;i--){
        if(m[i]>m[i+1]){
            b[i]=b[i+1]+1;
        }
        else{
            b[i]=1;
        }
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,2*min(a[i],b[i])-1);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m[i];
    }
    cout<<sequence(n);
    return 0;
}