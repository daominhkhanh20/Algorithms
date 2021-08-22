#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int f,s,g,u,d,count_step[N];
bool visit[N];
void input(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>f>>s>>g>>u>>d;
}

void solve(){
    queue<int>a;
    a.push(s);
    count_step[s]=0;
    while(!a.empty()){
        int current_node=a.front();a.pop();
        if(current_node==g){
            cout<<count_step[g]<<endl;
            break;
        }
        if(current_node+u<=f && !visit[current_node+u]){
            visit[current_node+u]=true;
            a.push(current_node+u);
            count_step[current_node+u]=count_step[current_node]+1;
        }
        
        if(current_node-d>=1 && !visit[current_node-d]){
            visit[current_node-d]=true;
            a.push(current_node-d);
            count_step[current_node-d]=count_step[current_node]+1;
        }
    }
    if(count_step[g]==0)cout<<"use the stairs"<<endl;
}

int main(){
    input();
    solve();
    return 0;
}