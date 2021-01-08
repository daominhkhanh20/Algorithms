#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=-1;
    for(int i=1;i<n;i++){
        int c=i,b=i;
        while(c>=1&&b<n-1&&a[c-1]<a[c]&&a[b+1]<a[b]){
            c--;
            b++;
        }
        ans=max(ans,abs(c-i));
    }
    cout<<2*ans+1;
}