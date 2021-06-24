#include<bits/stdc++.h>
using namespace std;
#define N 12
int n,K=1;
int d[2*N][2*N];//save distance
bool visit[2*N];
int x[2*N];//x[i]=p when p is next point when we move from destination i
int passengers;
int minDis=INT_MAX;
int distance_current=0;
int result=INT_MAX;
void input(){
    cin>>n>>K;
    for(int i=0;i<2*n+1;i++){
        for(int j=0;j<2*n+1;j++){
            cin>>d[i][j];
            if(d[i][j])minDis=min(minDis,d[i][j]);
        }
    }
}

void update(){
    distance_current+=d[x[2*n]][0];
    result=min(result,distance_current);
    distance_current-=d[x[2*n]][0];
}

bool check(int v,int a){
    if(passengers==K && v<=n) return false;
    if(d[x[a-1]][v]==0)return false;
    if(v>n && visit[v-n]==false)return false;
    if(!visit[v])return true;
    return false;
}
//a: number destination has been visited
void TRY(int a){
    for(int i=1;i<=2*n;i++){
        if(check(i,a)){
            if(i<=n)passengers+=1;
            else passengers-=1;

            visit[i]=true;
            x[a]=i;
            distance_current+=d[x[a-1]][i];
            if(a==2*n)update();
            else{
                if(distance_current+(2*n-a)*minDis< result)TRY(a+1);
            }
            visit[i]=false;
            distance_current-=d[x[a-1]][i];
            if(i<=n)passengers-=1;
            else passengers+=1;
                        
        }
    }
}
int main(){
    input();
    x[0]=0;
    TRY(1);
    cout<<result;
}
