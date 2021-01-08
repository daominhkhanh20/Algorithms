#include<bits/stdc++.h>
using namespace std;
// time complexity O(N^3)
bool check(string s){
    stack<char>k;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(') k.push(s[i]);
        else if(!k.empty() && k.top()=='(')k.pop();
        else {
            return false;
        }
    }
    return k.empty();
}

int solver(string s){
    if(s.length()==0|| s.length()==1) return 0;
    int n=s.length();
    int result=0;
    for(int i=0;i<=n-2;i++){
        for(int j=i+2;j<=n;j+=2){
            string temp=s.substr(i,j-i);
            if(check(temp))result=max(result,j-i);
        }
    }
    return result;
}

int main(){
    string s;
    while(cin>>s){
        int result=solver(s);
        cout<<result<<endl;
    }
    return 0;
}
