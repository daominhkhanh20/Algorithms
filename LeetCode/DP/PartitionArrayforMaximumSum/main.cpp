
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        int temp[n];
        memset(temp,0,sizeof(temp));
        for(int i=0;i<n;i++){
            int max_temp=0;
            for(int j=1;j<=k && i-j+1>=0;j++){
                max_temp=max(max_temp,arr[i-j+1]);
                temp[i]=max(temp[i],(i>=j?temp[i-j]:0)+max_temp*j);
            }
        }
        return temp[n-1];
    }
};

int main(){
    vector<int>arr={1,15,7,9,2,5,10};
    Solution solution;
    int result=solution.maxSumAfterPartitioning(arr,3);
    cout<<result<<endl;
    return 0;
}
