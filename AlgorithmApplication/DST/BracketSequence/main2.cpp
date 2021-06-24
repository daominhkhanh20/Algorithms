#include<bits/stdc++.h>
using namespace std;
string s;
int result=INT_MIN;
int cnt=0,start_index,last_index;
void solve(){
    stack<int>a;
    for(int i=0;i<s.length();i++){
        char temp=s[i];
        if(i==0 || temp=='(' || temp=='['){
            a.push(i);
            if(temp=='[')cnt++;
        }
        else{
            if(temp==')'){
                if(s[a.top()]=='(')a.pop();
                else a.push(i);
            }
            else if(temp==']'){
                if(s[a.top()]=='[')a.pop();
                else a.push(i);
            }
        }
    }
    if(a.empty()){
        result=cnt;
        start_index=0;
        last_index=s.length();
    }
    int last=s.length();
    while(!a.empty()){
        int start=a.top()+1;
        int temp=0;
        for(int i=start;i<last;i++){
            if(s[i]=='[')temp++;
        }
        if(temp>result){
            result=temp;
            start_index=start;
            last_index=last;
        }
        last=a.top();
        a.pop();
    }
    if(last>0){
        int temp=0;
        for(int i=0;i<last;i++){
            temp+=(s[i]=='[')?1:0;
        }
        if(temp>result){
            result=temp;
            start_index=0;
            last_index=last;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    if(s.length()==0)cout<<0<<'\n'<<s<<endl;
    else{
        solve();
        cout<<result<<endl;
        for(int i=start_index;i<last_index;i++)cout<<s[i];
    }
    return 0;
}