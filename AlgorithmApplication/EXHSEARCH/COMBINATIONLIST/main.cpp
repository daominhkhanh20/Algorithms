#include<bits/stdc++.h>
using namespace std;
int n,m;
bool visit[10000];
int x[10000];

void show(){
    for(int i=1;i<=m;i++){
        cout<<x[i]<<" ";
    }
    cout<<endl;
}
void TRY(int index){
    for(int i=x[index-1]+1;i<=n;i++){
        if(!visit[i]){
            x[index]=i;
            visit[i]=true;
            if(index==m)show();
            else(TRY(index+1));
            visit[i]=false;
        }
    }
}
int main(){
    x[0]=0;
    cin>>n>>m;
    TRY(1);
    return 0;
}
