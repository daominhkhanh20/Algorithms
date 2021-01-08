//https://leetcode.com/problems/longest-palindromic-substring/i
//O(N^2) for time complexity and O(1) for space
#include<bits/stdc++.h>
using namespace std;

string longestPalindromicSubstring(string s){
    if(s.length()==1) return s;
    int start=0,max_len=1;
    int len=s.length();
    for(int i=1;i<s.length();i++){

        //find longest substring which has old length
        int low=i-1;
        int high=i+1;
        while(low>=0 && high<len&& s[low]==s[high]){
            if(high-low+1>max_len){
                start=low;
                max_len=high-low+1;
            }
            low--;
            high++;
        }
        // find longest substring which has even length;
        low=i-1;
        high=i;
        while(low>=0 && high<len&& s[low]==s[high]){
            if(high-low+1>max_len){
                start=low;
                max_len=high-low+1;
            }
            low--;
            high++;
        }
    }
    //cout<<start<<" "<<max_len<<endl;
    string result=s.substr(start,max_len);
    return result;
}

int main(){
    freopen(".inp","r",stdin);
    string s;
    while(cin>>s){
        //cout<<s<<endl;
        string result=longestPalindromicSubstring(s);
        cout<<result<<endl;
    }
    return 0;
}
