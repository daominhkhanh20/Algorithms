//Optimization solution
//O(NlogN)
//Algorithms:
//https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/

//https://codeforces.com/group/FLVn1Sc504/contest/274518/my
#include<bits/stdc++.h>
using namespace std;
int ceilIndex(vector<int>&t,int l,int r,int key){
    while(r-l>1){
        int m=l+(r-l)/2;
        if(t[m]>=key){
            r=m;
        }
        else{
            l=m;
        }
    }
    return r;

}
int lis(vector<int>&a){
    int n=a.size();
    vector<int>t(a.size(),0);
    if(n==0){
        return 0;
    }
    int length=1;
    t[0]=a[0];
    for(int i=1;i<n;++i){
        if(a[i]<t[0]){
            t[0]=a[i];
        }

        else if(a[i]>t[length-1]){
            t[length++]=a[i];
        }

        else{
            t[ceilIndex(t,-1,length-1,a[i])]=a[i];
        }

    }
    return length;
}
int main(){
    int n;
    cin>>n;
    vector<int>a;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    reverse(a.begin(),a.end());
    cout<<lis(a);
    return 0;
}
