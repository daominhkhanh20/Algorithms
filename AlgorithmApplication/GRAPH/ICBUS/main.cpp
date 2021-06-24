#include<bits/stdc++.h>
using namespace std;
const int N=5001;
vector<int>a[N];
int dis[N],visit[N],c[N],d[N],check[N];
int n,k;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>c[i]>>d[i];
    int x,y;
    for(int i=1;i<=k;i++){
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
}

void dijkstra(int root){
    // Time complexity O(V+E)
    queue<int>q;
    q.push(root);
    for(int i=1;i<=n;i++)check[i]=-1;
    check[root]=0;
    while(q.empty()==false){
        int u=q.front();
        q.pop();
        dis[u]=min(dis[u],dis[root]+c[root]);
        if(check[u]<d[root]){
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
    //Time complexity O(V*(V+E))
    while(1){
        int u=n+1;
        for(int i=1;i<=n;i++){
            if(visit[i]==0 && dis[i]<=dis[u])u=i;
        }
        visit[u]=1;
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