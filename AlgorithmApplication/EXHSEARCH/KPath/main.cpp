#include<bits/stdc++.h>
using namespace std;
#define N 50
int n,k;
int m;
vector<int>a[N];
long long cnt=0;
bool visit[N];
int segment=0;
void dfs(int index){
    for(int i=0;i<a[index].size();i++){
        int v=a[index][i];
        if(!visit[v]){
            segment+=1;
            visit[v]=true;
            if(segment==k)cnt++;
            else dfs(v);
            visit[v]=false;
            segment-=1;
        }
    }
}
int main(){
    cin>>n>>k>>m;
    int u,v;
    a[0].push_back(0);
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        memset(visit,false,sizeof(visit));
        visit[i]=true;
        dfs(i);
    }
    cout<<cnt/2;
    return 0;
}