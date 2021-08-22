#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0')return 0;
        int n=s.length();
        vector<int>dp(n,0);
        dp[0]=1;
        for(int i=1;i<n;i++){
            if(s[i]=='0' && s[i-1]=='0')return 0;
            if(s[i-1]!='0'){
                int v=stoi(s.substr(i-1,2));
                if(v<=26){
                    if(i!=1)dp[i]=dp[i-2];
                    else dp[i]=dp[i-1];
                }
            }
            if(s[i]!='0')dp[i]+=dp[i-1];
        }
        return dp[n-1];
    }
};
int main(){
    string s;
    cin>>s;
    Solution solution;
    cout<<solution.numDecodings(s);
    return 0;
}