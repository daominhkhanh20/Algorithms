//https://leetcode.com/problems/maximum-units-on-a-truck/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n=boxTypes.size();
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(boxTypes[i][0]>truckSize){
                cnt+=truckSize*boxTypes[i][1];
                    break;
            }
            else{
                cnt+=boxTypes[i][0]*boxTypes[i][1];
                truckSize-=boxTypes[i][0];
            }
        }
        return cnt;
    }
};