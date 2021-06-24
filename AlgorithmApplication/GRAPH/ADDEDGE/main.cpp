#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=1e5+6;
ll n,m;
ll t=0;
vector<ll>a[N],aId[N];
ll x[N],y[N],num[N],low[N];
vector<ll>bridge;
bool visit1[N];
ll cnt=0,dem[N],cnt1;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>x[i]>>y[i];
        a[x[i]].push_back(y[i]);
        a[y[i]].push_back(x[i]);
        aId[x[i]].push_back(i);
        aId[y[i]].push_back(i);//determine edge x[i]<-->y[i] using index i 
    }
}

//find bridge edge
void find_bridge_edge(int du,int u){//father for u and u
    num[u]=low[u]=t++;
    for(int i=0;i<a[u].size();i++){
        int v=a[u][i];
        if(v==du)continue;
        else if(num[v]){
            low[u]=min(low[u],num[v]);
        }
        else{
            find_bridge_edge(u,v);
            low[u]=min(low[u],low[v]);
            if(low[v]>num[u])bridge.push_back(aId[u][i]);
        }
    }
}
void delete_circle(){
    for(int i=1;i<=n;i++){
        if(num[i]==0){
            find_bridge_edge(0,i);
        }
    }
}

void build_new_graph(){
    for(int i=1;i<=n;i++)a[i].clear();
    for(int i=0;i<bridge.size();i++){
        int u=x[bridge[i]];
        int v=y[bridge[i]];
        a[u].push_back(v);
        a[v].push_back(u);
    }
}

void dfs(int u){
    visit1[u]=true;
    dem[cnt]=++cnt1;
    for(int i=0;i<a[u].size();i++){
        int v=a[u][i];
        if(visit1[v]==false){
            dfs(v);
        }
    }
}
void solve(){
    delete_circle();
    build_new_graph();
    for(int i=1;i<=n;i++){
        if(visit1[i]==false){
            dfs(i);
            cnt++;
            cnt1=0;
        }
    }
    ll ans=0;
    for(int i=0;i<cnt;i++){
        int t=(dem[i]-1)*dem[i];
        ans+=t/2-(dem[i]-1);
    }
    cout<<ans;
}

int main(){
    input();
    solve();
    return 0;
}
