#include<bits/stdc++.h>
using namespace std;
const int N=1e4+1;
vector<pair<int,int>>a[N];
int d[N];
vector<int>topo;
int income[N];
int ans,f[N];//f[u] thoi diem som nhat de cong viec u co the bat dau
int n,m;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;

    for(int i=1;i<=n;i++)cin>>d[i];
    int x,y;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        a[x].push_back({y,d[x]});
        income[y]++;
    }
}

void search_topo(){
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(income[i]==0)q.push(i);
    }

    while(!q.empty()){
        int u=q.front();
        q.pop();
        topo.push_back(u);
        for(int i=0;i<a[u].size();i++){
            int v=a[u][i].first;
            income[v]-=1;
            if(income[v]==0)q.push(v);
        }
    }
}

void solve(){
    memset(f,0,sizeof(f));
    ans=0;
    for(int i=0;i<topo.size();i++){
        int u=topo[i];
        ans=max(ans,f[u]+d[u]);
        for(int j=0;j<a[u].size();j++){
            int v=a[u][j].first,w=a[u][j].second;
            f[v]=max(f[v],f[u]+w);
        }
    }
    cout<<ans;
}
int main(){
    input();
    search_topo();
    solve();
    return 0;
}