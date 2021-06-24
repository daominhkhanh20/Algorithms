#include<bits/stdc++.h>
using namespace std;
const int N=100;
bool visit[N];
int n,a[N],condition[N][N],k;

bool check(int v,int index){
    if(visit[v])return false;
    for(int i=1;i<=index-1;i++){
        if(condition[v][a[i]]==1)return false;
    }
    return true;
}
int cnt=0;
void solution(){
    cnt++;
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void TRY(int index){
    for(int i=1;i<=n;i++){
        if(check(i,index)){
            a[index]=i;
            visit[i]=true;
            if(index==n)solution();
            else TRY(index+1);
            visit[i]=false;
        }
    }
}

int main(){
    cin>>n;
    cin>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            condition[i][j]=0;
        }
    }
    int x,y;
    for(int i=0;i<k;i++){
        cin>>x>>y;
        condition[x][y]=1;
    }
    for(int i=1;i<=n;i++)visit[i]=false;
    TRY(1);
    cout<<cnt;
    return 0;
}
