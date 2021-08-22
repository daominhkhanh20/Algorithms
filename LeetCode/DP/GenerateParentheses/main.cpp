#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    static vector<string>generateString(vector<string>result,string current,int num_open,int num_end,int max_pair){
        if(current.length()==2*max_pair){
            result.push_back(current);

        }
        if(num_open<max_pair){
            current+='(';
            result=generateString(result,current,num_open+1,num_end,max_pair);
            current=current.substr(0,current.length()-1);
        }
        if(num_end<num_open){
            current+=')';
            result=generateString(result,current,num_open,num_end+1,max_pair);
            current=current.substr(0,current.length()-1);
        }
        return result;
    }
    vector<string>generateParenthesis(int n){
        vector<string>temp;
        vector<string>result=generateString(temp,"",0,0,n);
        return result;
    }
};

int main(){
    Solution solution;
    vector<string>result=solution.generateParenthesis(3);
    for(string s:result){
        cout<<s<<endl;
    }
    return 0;
}