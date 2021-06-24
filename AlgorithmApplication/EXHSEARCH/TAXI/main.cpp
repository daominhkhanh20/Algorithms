#include<bits/stdc++.h>
using namespace std;
#define N 15
int n;
int dis[N][N];
bool visit[N];
int x[2*N];
int distance_curr=0;
int result=INT_MAX;
int cmin=INT_MAX;
int load=0;
void input(){
    cin>>n;
    for(int i=0;i<=2*n;i++){
        for(int j=0;j<=2*n;j++){
            cin>>dis[i][j];
            if(dis[i][j])cmin=min(cmin,dis[i][j]);
        }
    }
}
void updateBest(){
    distance_curr+=dis[x[2*n]][0];
    result=min(result,distance_curr);
    distance_curr-=dis[x[2*n]][0];
}
bool check(int a,int v){
    if(v<=n && load==1)return false;
    if(dis[x[a-1]][v]==0)return false;
    if(visit[v])return false;
    if(v>n && visit[v-n]==false)return false;
    return true;
}

void TRY(int a){
    for(int v=1;v<=2*n;v++){
        if(check(a,v)){
            if(v<=n)load++;
            else load--;
            visit[v]=true;
            x[a]=v;
            distance_curr+=dis[x[a-1]][v];
            if(a==2*n)updateBest();
            else if(distance_curr+cmin*(2*n+1-a)<result){
                TRY(a+1);
            }
            visit[v]=false;
            distance_curr-=dis[x[a-1]][v];
            if(v<=n)load++;
            else load--;
        }

    }
}
int main(){
    x[0]=0;
    for(int i=0;i<=2*n;i++)visit[i]=false;
    input();
    TRY(1);
    cout<<result;
    return 0;
}
