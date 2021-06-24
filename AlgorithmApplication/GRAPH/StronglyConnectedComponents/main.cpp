#include<bits/stdc++.h>
using namespace std;
const int N=10e5+1;
vector<int>a[N],b[N];
vector<pair<int,int>>p;
int n,m;
bool cmp(pair<int,int>&a,pair<int,int>&b){
    return a.second>b.second;
}
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int x,y;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        a[x].push_back(y);
        b[y].push_back(x);
    }
}
int pre[N],post[N];
int clk=0;
bool visit[N];
void dfs(int index){
    visit[index]=true;
    pre[index]=++clk;
    for(int i=0;i<b[index].size();i++){
        int v=b[index][i];
        if(!visit[v]){
            dfs(v);
        }
    }
    clk++;
    p.push_back({index,clk});
}
void dfs2(int index){
    visit[index]=true;
    for(int i=0;i<a[index].size();i++){
        int v=a[index][i];
        if(!visit[v]){
            dfs2(v);
        }
    }
}
int main(){
    input();
    for(int i=1;i<=n;i++){
        if(visit[i]==false){
            dfs(i);
        }
    }
    memset(visit,false,sizeof(visit));
    int cnt=0;
    sort(p.begin(),p.end(),cmp);
    for(int i=0;i<p.size();i++){
        int v=p[i].first;
        if(visit[v]==false){
            dfs2(v);
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
    

}
