//https://leetcode.com/problems/maximum-subarray
#include<bits/stdc++.h>
using namespace std;
vector<int>a;

int find(){
    int result=INT_MIN,sum=0;
    for(int i=0;i<a.size();i++){
        sum+=a[i];
        if(sum>result) result=sum;
        if(a[i]>result) result=a[i];
        if(a[i]>sum)sum=a[i];
    }
    return result;
}
int main(){
    freopen(".inp","r",stdin);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    int result=find();
    cout<<result;
    return 0;
}
