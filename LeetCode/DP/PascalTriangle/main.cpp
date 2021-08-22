#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<int>> generate(int numRows){
        vector<vector<int>>result;
        for(int i=0;i<numRows;i++){
            if(i==0){
                result.push_back({1});
            }
            else if(i==1){
                result.push_back({1,1});
            }
            else{
                vector<int>temp;
                temp.push_back(1);
                for(int j=1;j<i;j++){
                    temp.push_back(result[i-1][j-1]+result[i-1][j]);
                }
                temp.push_back(1);
                result.push_back(temp);
            }
        }
        return result;
    }
};

int main(){
    Solution solution;
    vector<vector<int>>result=solution.generate(5);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}