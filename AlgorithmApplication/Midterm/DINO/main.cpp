#include<bits/stdc++.h>
using namespace std;
#define N 10000+3
int x[N],n;
string s;
stack<int>a;
queue<int>b;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    int z;
    for(int i=1;i<=n;i++){
        cin>>z;
        x[i]=z;
    }
    for(int i=n;i>=1;i--){
        a.push(x[i]);
    }
    cin>>s;
    int k;
    for(int i=0;i<s.length();i++){
        char t=s[i];
        if(t=='C'){
            if(!a.empty()){
                k=a.top();
                a.pop();
                b.push(k);
            }
        }
        else if(t=='H'){
            if(!b.empty()){
                k=b.front();
                b.pop();
                a.push(k);
            }
        }
    }
    while(!a.empty()){
        cout<<a.top()<<" ";
        a.pop();
    }
    return 0;
    
}
