#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
vector<int>a[N];
bool visit[N];
int parent[N];
int n;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int x,y;
    for(int i=1;i<n;i++){
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
}

void solve(){
    queue<int>p;
    p.push(1);
    while(!p.empty()){
        int top=p.front();p.pop();
        visit[top]=true;

        for(int i=0;i<a[top].size();i++){
            int v=a[top][i];
            if(!visit[v]){
                parent[v]=top;
                p.push(v);
            }
        }
    }
    for(int i=2;i<=n;i++){
        cout<<parent[i]<<" ";
    }
}

int main(){
    input();
    solve();
    return 0;
}