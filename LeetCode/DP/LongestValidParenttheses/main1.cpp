#include<bits/stdc++.h>
using namespace std;
// Time complexity O(N)
int solver(string s){
    stack<int>a;
    int result=0;
    a.push(-1);
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            a.push(i);
        }
        else{
            a.pop();
            if(a.empty())a.push(i);
            else{
                result=max(result,i-a.top());
            }
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
