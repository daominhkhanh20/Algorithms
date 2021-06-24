#include<bits/stdc++.h>
using namespace std;
int n;

bool check(string s){
    stack<char>a;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('|| s[i]=='[' || s[i]=='{'){
            a.push(s[i]);
        }
        else{
            if(s[i]==')'){
                if(a.top()=='(')a.pop();
                else return false;
            }
            else if(s[i]==']'){
                if(a.top()=='[')a.pop();
                else return false;
            }
            if(s[i]=='}'){
                if(a.top()=='{')a.pop();
                else return false;
            }
        }
    }
    if(a.empty()==false)return false;
    return true;
}
int main(){
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        if(check(s))cout<<1<<endl;
        else cout<<0<<endl;
    }
    return 0;
}
