#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        return nums[n/2]; 
    }

    int majorityElement2(vector<int>&nums){
        int result=INT_MIN;
        int count=0;
        for(int value:nums){
            if(count==0)result=value;
            count+=result==value?1:-1;
        }
        return result;
    }
};