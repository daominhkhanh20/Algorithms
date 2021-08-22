#include<bits/stdc++.h>
using namespace std;
const int N=5005,K=1e4+5;
int n,k,C[N],check[N],D[N],dis[N];
bool visit[N];
vector<int>a[N];
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>C[i]>>D[i];
    }
    int x,y;
    for(int i=1;i<=k;i++){
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
}

void dijkstra(int root){
    queue<int>q;
    q.push(root);
    for(int i=1;i<=n;i++)check[i]=-1;
    check[root]=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        dis[u]=min(dis[u],dis[root]+C[root]);
        if(check[u]<D[root]){
            for(int i=0;i<a[u].size();i++){
                int v=a[u][i];
                if(check[v]!=-1)continue;
                check[v]=check[u]+1;
                q.push(v);
            }
        }
    }
}
void solve(){
    for(int i=1;i<=n+1;i++)dis[i]=INT_MAX;
    dis[1]=0;
    
    while(true){
        int u=n+1;
        for(int i=1;i<=n;i++){
            if(visit[i]==0 && dis[i]<=dis[u])u=i;
        }
        visit[u]=true;
        if(u==n)break;
        dijkstra(u);
    }
    cout<<dis[n]<<endl;
}

int main(){
    input();
    solve();
    return 0;
}