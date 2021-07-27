#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(string a,string b){
        return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>temp;
        for(int i=0;i<nums.size();i++)temp.push_back(to_string(nums[i]));
        sort(temp.begin(),temp.end(),cmp);
        string result="";
        for(int i=0;i<temp.size();i++){
            if(result=="" && temp[i]=="0")continue;
            result+=temp[i];
        }
        return result==""?"0":result;
    }
};

int main(){
    //vector<int>nums={432,43243};    
    vector<int>nums={0,0};

    Solution g;
    string res=g.largestNumber(nums);
    cout<<res<<endl;
    // string a="ab";
    // string c="abc";
    // if(a==c.substr(0,a.size()))cout<<"True";
    return 0;
}