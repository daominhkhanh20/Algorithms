#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    // TIME LIMIT ERROR
    int numSplits(string s) {
        map<char,int>dict1;
        int count_distinct_character=0;
        for(int i=0;i<s.size();i++){
            char temp=s[i];
            if(dict1[temp]==0){
                count_distinct_character++;
                dict1[temp]=1;
            }
        }
        int result=0;
        for(int i=0;i<s.size()-1;i++){
            int count_left=0,count_right=0;
            map<char,int>t1,t2;
            for(int j=0;j<=i;j++){
                if(t1[s[j]]==0){
                    count_left++;
                    t1[s[j]]=1;
                }
            }
            for(int j=i+1;j<s.size();j++){
                if(t2[s[j]]==0){
                    count_right++;
                    t2[s[j]]=1;
                }
            }
            if(count_left==count_right)result+=1;
        }
        return result;
    }

    int numSplits2(string s){
        map<char,int>t1,t2;
        int n=s.size();
        int d1[n],d2[n];
        t1[s[0]]=t2[s[n-1]]=1;
        d1[0]=d2[n-1]=1;
        for(int i=1;i<n;i++){
            if(t1[s[i]]==0){
                t1[s[i]]=1;
                d1[i]=d1[i-1]+1;
            }
            else d1[i]=d1[i-1];
        }

        for(int i=n-2;i>=0;i--){
            if(t2[s[i]]==0){
                t2[s[i]]=1;
                d2[i]=d2[i+1]+1;
            }
            else d2[i]=d2[i+1];
        }
        int result=0;
        for(int i=0;i<n-1;i++){
            result+=d1[i]==d2[i+1]?1:0;
        }
        return result;
    }
};

int main(){
    Solution solution;
    int result=solution.numSplits2("aaaaa");
    cout<<result<<endl;
    return 0;
}
