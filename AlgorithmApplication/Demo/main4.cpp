#include<bits/stdc++.h>
using namespace std; 
#define N 1000000+5
int n;
vector<int>x;

void find_h(vector<int>a){
    int base=0;
    int n=a.size();
    int result=0;
    while(base<n){
        int end=base;
        if(end+1<n &&a[end+1]>a[end]){
            while(end+1<n &&a[end+1]>a[end])end++;
            int left=end-base;
            int des=end;
            while(end+1<n && a[end+1]<a[end])end++;
            int right=end-des;
            result=max(result,min(left,right));
        }
        base=max(end,base+1);
    }
    cout<<result<<" ";
}

void find_l(vector<int>a){
    int base=0;
    int n=a.size();
    int result=0;
    while(base<n){
        int end=base;
        if(end+1<n &&a[end+1]<a[end]){
            while(end+1<n &&a[end+1]<a[end])end++;
            int left=end-base;
            int des=end;
            while(end+1<n && a[end+1]>a[end])end++;
            int right=end-des;
            result=max(result,min(left,right));
        }
        base=max(end,base+1);
    }
    cout<<result<<" ";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    int t;
    for(int i=1;i<=n;i++){
        cin>>t;
        x.push_back(t);
    }
    find_h(x);
    find_l(x);
    return 0; 
    
}

