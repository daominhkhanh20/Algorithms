#include<bits/stdc++.h>
using namespace std;

class Solution{
    int dp[1005]={0};
    public:
    void init(){
        dp[0]=0;
        dp[1]=0;
        dp[2]=1;
        dp[3]=7;
    }

    int calculate(int value){
        if(dp[value]!=0)return dp[value];

        if(value%2==0)dp[value]=calculate(value/2)+1;
        else dp[value]=calculate(3*value+1)+1;
        return dp[value];
    }
    static bool cmp(pair<int,int>&a,pair<int,int>&b){
        if(a.first<b.first)return true;
        else if(a.first==b.first)return a.second<b.second;
        return false;
    }
    int getKth(int lo,int hi,int k){
        init();
        vector<pair<int,int>>a;
        for(int i=lo;i<=hi;i++){
            int value=calculate(i);
            a.push_back({value,i});
        }
        sort(a.begin(),a.end(),cmp);
        return a[k-1].second;
    }
};

int main(){
    Solution solution;
    int value=solution.getKth(12,15,2);
    cout<<value<<endl;
    return 0;
}