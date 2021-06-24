#include<bits/stdc++.h>
using namespace std;
string s;
stack<int>a;
int result,start_index,last_index;
void solve(){
    int temp=0;
    for(int i=0;i<s.length();i++){
        char t=s[i];
        if(a.empty() || t=='(' || t=='['){
            a.push(i);
            if(t=='[')temp++;
        }
        else{
            if(t==')'){
                if(s[a.top()]=='('){
                    a.pop();
                }
                else a.push(i);
            }
            else if(t==']'){
                if(s[a.top()]=='['){
                    a.pop();
                }
                else a.push(i);
            }
        }
    }
    if(a.empty()){
        start_index=0;
        last_index=s.length();
        result=temp;
        return;
    }
    stack<int>x;
    while(!a.empty()){
        x.push(a.top());
        a.pop();
    }
    int start=0,last,cnt;
    while(!x.empty()){
        last=x.top();
        x.pop();
        cnt=0;
        for(int i=start;i<last;i++){
            if(s[i]=='['){
                cnt++;
            }
        }
        if(cnt>result){
            result=cnt;
            start_index=start;
            last_index=last;
        }
        start=last+1;
    }
    cnt=0;
    for(int i=start;i<s.length();i++){
        if(s[i]=='['){
            cnt++;
        }
    }
    if(cnt>result){
        result=cnt;
        start=last+1;
        last_index=s.length();
    }

}
int main(){
    cin>>s;
    solve();
    cout<<result<<endl;
    for(int i=start_index;i<last_index;i++){
        cout<<s[i];
    }
    if(result==0)cout<<endl;
    return 0;
}
