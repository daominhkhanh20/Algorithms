#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
vector<int>a[N];
int degree[N];
int n,m;
int result=1;
bool visit[N];
void input(){
    cin>>n>>m;
    int x,y;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
}

void solve(int u){
    visit[u]=true;
    queue<int>q;
    q.push(u);
    degree[u]=1;
    while(!q.empty()){
        int v=q.front();
        q.pop();

        for(int i=0;i<a[v].size();i++){
            int k=a[v][i];
            if(!visit[k]){
                degree[k]=degree[v]+1;
                q.push(k);
                visit[k]=true;
            }
            else{
                if(degree[v]%2==0 && degree[k]%2==0 ||degree[v]%2==1 && degree[k]%2==1){
                    result=0;
                    return ;
                }
            }
        }
    }
}

int main(){
    input();
    for(int i=1;i<=n;i++){
        if(visit[i]==false){
            solve(i);
        }
    }
    cout<<result;
    return 0;   
}