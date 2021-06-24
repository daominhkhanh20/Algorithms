#include<bits/stdc++.h>
using namespace std;
#define N 1000
int n,m,c[N][N],x[N],cm;
int f=0,f_min=INT_MAX;
bool visit[N];

bool check(int k){
    return !visit[k];
}

void updateBest(){
    if(f_min>f+c[x[n]][1]){
        f_min=f+c[x[n]][1];
    }
}
void Try(int k){
    for(int i=2;i<=n;i++){
        if (check(i)){
            x[k]=i;
            visit[i]=true;
            f+=c[x[k-1]][x[k]];
            if(k==n)updateBest();
            else{
                int g=f+cm*(n-k+1);
                if(g<f_min) Try(k+1);
            }
            visit[i]=false;
            f-=c[x[k-1]][x[k]];
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            c[i][j]=1e6;
        }
        visit[i]=false;
    }
    int p,q,d;
    for(int i=0;i<m;i++){
        cin>>q>>p>>d;
        c[q][p]=d;
        cm=min(cm,d);
    }
    x[1]=1;
    visit[1]=true;
    Try(2);
    cout<<f_min;
    return 0;

}
