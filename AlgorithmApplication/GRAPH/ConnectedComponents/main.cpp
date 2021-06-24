#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;

int n,m;
vector<int>a[N];
int cp=0;
bool visit[N];
void input(){
    cin>>n>>m;
    int x,y;
    for(int i=1;i<m;i++){
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
}

void dfs(int u){
    visit[u]=true;
    for(int i=0;i<a[u].size();i++){
        int v=a[u][i];
        if(visit[v]==false){
            dfs(v);
        }
    }
}

int main(){
    input();
    for(int i=1;i<=n;i++){
        if(visit[i]==false){
            cp++;
            dfs(i);
        }
    }
    cout<<cp;
    return 0;
}