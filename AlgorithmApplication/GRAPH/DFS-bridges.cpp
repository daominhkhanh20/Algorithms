#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
int n,m;
vector<int> A[N];// A[v] is list of adjacent nodes of v
int low[N], num[N];// num[v] = -1 indicates that v has not been visited
int t;
int nbBridges, nbArticulations;
bool arti[N];
int root, nbChildren;
void dfs(int u, int pu){// DFS fromu, pu is the parent of u
    //cout << "dfs(" << u << "," << pu << ") starts" << endl;
    t++;
    num[u] = t; low[u] = t;
    for(int i = 0; i < A[u].size(); i++){
        int v = A[u][i];
        if(v == pu) continue;
        if(num[v] == -1){// v has not been visited
            if(u == root)nbChildren ++;
            dfs(v,u);
            low[u] = min(low[u],low[v]);
            if(low[v] > num[u]){
                //cout << "(" << u << "," << v << ") is a bridge" << endl;
                nbBridges++;
            }
            //cout << "dfs(v = " << v << "," << u << ") finished, low[" << v << "] = "
            //<< low[v] << ", low[" << u << "] = " << low[u] << " num[" << u << "] = " << num[u] << endl;
            if(low[v] >= num[u] && u != root){
                arti[u] = true;
                //cout << "node " << u << " is arti" << endl;
            }
        }else{// (u,v) is a  back-edge
            low[u] = min(low[u],num[v]);
        }
    }
}
void init(){
    t = 0;
    for(int v = 1; v <= n; v++){
        num[v] = -1; //
    }
}
void dfs(){
    init();
    for(int v = 1; v <= n; v++) arti[v] = false;
    nbBridges = 0;
    nbArticulations = 0;
    for(int v = 1; v <= n; v++){
        if(num[v] == -1){
            root = v; nbChildren = 0;
            dfs(v,-1);
            if(nbChildren > 1){
                    arti[root] = true;
            }
        }
    }
    for(int v = 1; v <= n; v++)
        if(arti[v] == true) nbArticulations++;
    cout << nbArticulations << " " << nbBridges;
}
void input(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u,v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
}
int main(){
    input();
    dfs();
}
