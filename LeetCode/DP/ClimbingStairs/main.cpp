#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int minCostClimbingStairs(vector<int>&cost){
        int n=cost.size();
        int dp[n];
        memset(dp,0,sizeof(dp));
        dp[0]=cost[0];dp[1]=cost[1];
        for(int i=2;i<n;i++){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        for(int i=0;i<n;i++)cout<<dp[i]<<" ";
        cout<<endl;
        return min(dp[n-1],dp[n-2]);
    }
};

int main(){
    vector<int>cost={1,100,1,1,1,100,1,1,100,1};
    Solution solution;
    cout<<solution.minCostClimbingStairs(cost);
    return 0;
}
