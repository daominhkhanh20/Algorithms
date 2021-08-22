//https://leetcode.com/problems/jump-game-ii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int>a(10001,INT_MAX);
        a[0]=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int jump=1;jump<=nums[i]&& i+jump<n;jump++){
                a[i+jump]=min(a[i+jump],a[i]+1);
            }
        }
        return a[n-1];
    }
};
int main(){
    vector<int>nums={2,3,0,1,4};
    Solution solution;
    cout<<solution.jump(nums);
    return 0;
}