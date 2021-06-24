#include<bits/stdc++.h>
using namespace std;
#define N 10000

int n,x[N];

void show(){
    for(int i=1;i<=n;i++){
        cout<<x[i];
        if(i!=n)cout<<" ";
    }
}

void find(){
    int i;
    for(i=n-1;i>0;i--){
        if(x[i]<x[i+1])break;
    }
    if(i==0){
        cout<<-1;
        return ;
    }
    int t=i+1;
    for(int j=t;j<=n;j++){
        if(x[j]>x[i])t=j;
    }
    swap(x[i],x[t]);
    i++;
    sort(x+i,x+n+1);
    show();
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    x[0]=0;
    find();
    return 0;
}
