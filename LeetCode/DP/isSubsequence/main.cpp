//https://leetcode.com/problems/is-subsequence/
#include<bits/stdc++.h>
using namespace std;

bool isSubsequence(string s,string t){
    if(s.length()==0)return true;
    int i=0,j=0;
    while(i<t.length()){
        if(t[i]==s[j]){
            j++;
            if(j==s.length()) return true;
        }
        i++;
    }
    return false;
}
int main(){
    string s,t;
    while(cin>>s>>t){
        bool result=isSubsequence(s,t);
        if(result) cout<<"True"<<endl;
        else cout<<"False"<<endl;
    }
    return 0;
}
