#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int countSubstrings(string s,string t){
        int result=0,n=s.size(),m=t.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s[i]!=t[j]){//point 2 substring different
                    int c1=0,c2=0,i_left=i-1,i_right=i+1,j_left=j-1,j_right=j+1;
                    while(i_left>=0 && j_left>=0 && s[i_left]==t[j_left]){
                        i_left-=1;
                        j_left-=1;
                        c1++;
                    }
                    while(i_right<n && j_right<m && s[i_right]==t[j_right]){
                        i_right+=1;
                        j_right+=1;
                        c2+=1;
                    }
                    result+=c1*c2+c1+c2+1;
                }
            }
        }
        return result;
    }
};

int main(){
    Solution solution;
    int c;
    cin>>c;
    while(c-->0){
        string s,t;
        cin>>s>>t;
        cout<<solution.countSubstrings(s,t)<<endl;
    }
    return 0;
}