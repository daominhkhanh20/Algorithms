#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1;
vector<int>A[N];
//num[v]=-1, that mean v isn' visited
int low[N],num[N];
int n,m;
int t=0;
int n_bridge=0,n_articulation=0;
int root,n_children;
bool articulation[N];
void input(){
    cin>>n>>m;
    int x,y;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        A[x].push_back(y);
        A[y].push_back(y);
    }
}

//pu is the parent of u
void dfs(int u, int pu){
    t++;
    num[u]=t;
    low[u]=t;
    for(int i=0;i<A[u].size();i++){
        int v=A[u][i];
        if(v==pu)continue;
        if(num[v]==-1){
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>num[u]){
                n_bridge++;
            }
        }
        else{
            low[u]=min(low[u],num[v]);
        }

    }

}
void solve(){
    for(int i=1;i<+n;i++)num[i]==-1;
    for(int i=1;i<+n;i++){
        if(num[i]==-1){
            // n_children=0;
            // root=i;
            dfs(i,-1);
            //if(n_children>1)articulation[i]=true;
        }
    }
    for(int i=1;i<=n;i++){
        n_articulation++;
    }
    cout<<n_articulation<<" "<<n_bridge<<endl;

}
int main(){
    input();
    solve();
    return 0;
}
