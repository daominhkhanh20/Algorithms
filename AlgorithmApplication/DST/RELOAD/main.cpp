#include<bits/stdc++.h>
using namespace std;
#define NMAX 100005

int n,q,a[NMAX];

int main(){
    cin>>n;
    int result=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=2;i<=n;i++){
        if(a[i]!=a[i-1])result++;
    }
    cin>>q;
    int x,y;
    for(int i=0;i<q;i++){
        cin>>x>>y;
        if(x>1 && a[x]!=a[x-1])result--;
        if(x<n && a[x]!=a[x+1])result--;
        a[x]=y;
        if( x>1 && a[x] != a[x-1] )result++;
        if( x<n && a[x] != a[x+1] )result++;
        cout<<result<<endl;
    }
    return 0;
}
