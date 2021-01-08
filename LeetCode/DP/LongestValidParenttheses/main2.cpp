#include<bits/stdc++.h>
using namespace std;
// Using dynamic programming
// Time complexity O(N)
// Space complexity O(n): dp array of size n is used
int solver(string s){
    int n=s.length();
    vector<int>dp(n,0);
    int result=0;
    for(int i=1;i<n;i++){
        if(s[i]==')'&&s[i-1]=='('){
            dp[i]=(i>=2?dp[i-2]:0)+2;
        }
        else if(s[i]==')'&& s[i-1]==')'&&i-dp[i-1]>0 &&s[i-1-dp[i-1]]=='('){
            //+2: because s[i-1-dp[i-1]]='(' and s[i]=')'
            dp[i]=dp[i-1]+2+(i-dp[i-1]-2>=0?dp[i-2-dp[i-1]]:0);
        }
        result=max(result,dp[i]);
    }
    return result;
}
int main(){
    string s;
    while(cin>>s){
        int result=solver(s);
        cout<<result<<endl;
    }
    return 0;
}
