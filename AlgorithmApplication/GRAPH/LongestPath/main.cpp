#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1;
vector<pair<int,int>>a[N];
int p[N],d[N];
int n;
void init(){
    for(int i=1;i<=n;i++)d[i]=p[i]=-1;
}
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int x,y,z;
    for(int i=1;i<=n;i++){
        cin>>x>>y>>z;
        a[x].push_back({y,z});
        a[y].push_back({x,z});
    }
}

void bfs(int root){
    queue<int>q;
    d[root]=0;
    q.push(root);

    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=0;i<a[u].size();i++){
            int v=a[u][i].first,w=a[u][i].second;
            if(p[u]==v)continue;
            p[v]=u;
            d[v]=d[u]+w;
            q.push(v);
        }
    }
}
int find_max(){
    int dis=INT_MIN,u=-1;
    for(int i=1;i<=n;i++){
        if(d[i]>dis){
            dis=d[i];
            u=i;
        }
    }
    return u;
}
void solve(){
    init();
    bfs(1);
    int u=find_max();
    init();
    bfs(u);
    int v=find_max();
    cout<<d[v];
}

int main(){
    input();
    solve();
    return 0;
}