#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
vector<pair<int,int>>a[N];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
int n,m;
int s,d;
int dis[N];
void input(){
    cin>>n>>m;
    int u,v,w;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        a[u].push_back({v,w});
    }
    cin>>s>>d;
}

void solve(){
    for(int i=1;i<=n;i++){
        dis[i]=INT_MAX;
    }
    dis[s]=0;
    p.push({0,s});
    while(!p.empty()){
        pair<int,int>temp=p.top();
        p.pop();
        int kc=temp.first;
        int node=temp.second;
        if(node==d)break;
        for(int i=0;i<a[node].size();i++){
            int w=a[node][i].second;
            int v=a[node][i].first;
            if(dis[v]>dis[node]+w){
                dis[v]=dis[node]+w;
                p.push({dis[v],v});
            }
        }
    }
    cout<<dis[d]<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solve();
    return 0;
}