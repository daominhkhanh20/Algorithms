#include<bits/stdc++.h>
using namespace std;
#define N 1000
int n,c[N][N],x[N],cm;
int f=0,f_min=INT_MAX;
bool visit[N];

bool check(int k){
    return !visit[k];
}

void updateBest(){
    if(f_min>f+c[x[n]][1]){
        f_min=f+c[x[n]][1];
        //for(int i=1;i<=n;i++)cout<<x[i]<<" ";
        //cout<<"Update best:"<<f_min<<endl;
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
           // cout<<f<<" ";
            visit[i]=false;
            f-=c[x[k-1]][x[k]];
           // cout<<f<<endl;
        }
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>c[i][j];
            cm=min(cm,c[i][j]);
        }
        visit[i]=false;
    }
    x[1]=1;
    visit[1]=true;
    Try(2);
    cout<<f_min;
    return 0;

}
