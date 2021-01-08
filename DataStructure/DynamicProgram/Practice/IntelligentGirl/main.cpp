#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n=s.size();
    int *a=new int[n];
    a[n-1]=((int)(s[n-1])-48)%2==0?1:0;

    for(int i=n-2;i>=0;--i){
        a[i]=a[i+1]+(((int)(s[i])-48)%2==0?1:0);
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}