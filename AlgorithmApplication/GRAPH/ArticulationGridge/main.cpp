#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m;
vector<int>a[N];
int num[N],low[N];
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int x,y;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
}
bool visit[N];
int bridge,art;
bool articulation[N];
int n_child=0;
int root,t;
void dfs(int s,int ps){
    visit[s]=true;
    t++;
    num[s]=low[s]=t;
    for(int i=0;i<a[s].size();i++){
        int v=a[s][i];
        if(v==ps)continue;
        else if(visit[v]){
            low[s]=min(low[s],num[v]);//back edge
        }
        else{
            if(s==root)n_child++;
            dfs(v,s);
            low[s]=min(low[s],low[v]);
            if(low[v]>num[s]){
                bridge++;//s is bridge
            }

            if(low[v]>=num[s] && s!=root){
                articulation[s]=true;// s is articulation
            }
        }
    }
}

int main(){
    input();
    for(int i=1;i<=n;i++){
        if(visit[i]==false){
            root=i;
            n_child=0;
            dfs(i,-1);
            if(n_child>1)articulation[i]=true;
        }
    }
    for(int i=1;i<=n;i++){
        if(articulation[i])art++;
    }
    cout<<art<<" "<<bridge<<endl;
    return 0;
}