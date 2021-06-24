#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int f,s,g,u,d;
int deep[N];
void solve(){
    queue<int>a;
    a.push(s);
    while(!a.empty()){
        int top=a.front();a.pop();
        if(top==g)break;
        if(top-d>0 && deep[top-d]==0){
            a.push(top-d);
            deep[top-d]=deep[top]+1;
        }
        if(top+u<=f && deep[top+u]==0){
            a.push(top+u);
            deep[top+u]=deep[top]+1;
        }
    }
    if(deep[g]==0)cout<<"use the stairs";
    else cout<<deep[g]<<endl;
}
int main(){
    cin>>f>>s>>g>>u>>d;
    solve();
    return 0;
}