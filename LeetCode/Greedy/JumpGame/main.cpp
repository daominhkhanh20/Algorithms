//https://leetcode.com/problems/jump-game/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size=nums.size();
        int step=0;
        for(int i=0;i<size;i++){
            if(step<0)return false;
            step=max(step,nums[i])-1;
        }
        return true;
    }
};