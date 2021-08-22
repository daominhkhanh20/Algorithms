#include<bits/stdc++.h>
using namespace std;

class Solution {
    int dp[10000005]={0};
    public:
    int calculate(int value){
        if(dp[value]!=0)return dp[value];
        if(value%2==0)dp[value]=calculate(value/2);
        else dp[value]=1+calculate(value/2);
        return dp[value];
    }
    vector<int> countBits(int n) {
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;dp[3]=2;dp[4]=1;dp[5]=2;
        vector<int>result;
        result.push_back(0);
        for(int i=1;i<=n;i++){
            int value=calculate(i);
            result.push_back(value);
        }
        return result;
    }
};

int main(){
    Solution solution;
    vector<int>result=solution.countBits(5);
    for(int i=0;i<result.size();i++)cout<<result[i]<<" ";
    return 0;
}