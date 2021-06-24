#include<bits/stdc++.h>
using namespace std;
#define N 100
int n,K,q;
int d[N];// number package for each client
int dis[N][N];
bool visit[N];
int load[N];
int segment;
int y[N],x[N];
int min_dis=INT_MAX;
int result=INT_MAX;
int dis_current;
void input(){
    cin>>n>>K>>q;
    for(int i=1;i<=n;i++){
        cin>>d[i];
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cin>>dis[i][j];
            if(i!=j && min_dis>dis[i][j])min_dis=dis[i][j];
        }
    }
}

bool checkX(int k,int v){
    if(v==0)return true;
    if(visit[v])return false;
    if(load[k]+d[v]>q) return false;
    return true;
}

void updateSolution(){
    int temp=0;
    for(int i=1;i<=K;i++){
        int s=y[i];
        temp+=dis[0][s];
        while(s>0){
            temp+=dis[s][x[s]];
            s=x[s];
        }
        temp+=dis[s][0];
    }
    result=min(result,temp);
}
void TryX(int s,int k){
    for(int v=0;v<=n;v++){
        if(checkX(k,v)){
            visit[v]=true;
            segment+=1;
            load[k]+=d[v];
            x[s]=v;
            dis_current+=dis[s][v];
            if(v==0){
                if(k==K){
                    if(segment==n+K){
                        updateSolution();
                    }
                }
                else{
                    TryX(y[k+1],k+1);
                }
            }
            else TryX(v,k);

            visit[v]=false;
            segment-=1;
            load[k]-=d[v];
        }
    }
}
bool checkY(int k,int i){
    if(visit[i])return false;
    if(load[k]+d[i]>q)return false;
    return true;
}
void TryY(int k){// assign client i for truck a
    for(int v=y[k-1]+1;v<=n;v++){
        if(checkY(k,v)){
            visit[v]=true;
            segment+=1;
            y[k]=v;
            load[k]+=d[v];
            dis_current+=dis[0][v];
            if(k==K){
                TryX(y[1],1);
            }
            else{
                TryY(k+1);
            }
            visit[v]=false;
            segment-=1;
            load[k]-=d[v];
        }
    }
}

int main(){
    input();
    TryY(1);
    cout<<result;
    return 0;
}
