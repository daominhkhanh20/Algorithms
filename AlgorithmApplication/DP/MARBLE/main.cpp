#include<bits/stdc++.h>
using namespace std;
const int NMAX=601;
int table[NMAX][NMAX];
int w,h;
void init(){
    for(int i=1;i<=w;i++){
        for(int j=1;j<=h;j++){
            table[i][j]=i*j;
        }
    }
}

void solve(){
    for(int i=1;i<=w;i++){
        for(int j=1;j<=h;j++){
            int waste=table[i][j];
            for(int k=1;k<i;k++){
                waste=min(waste,table[k][j]+table[i-k][j]);
            }
            for(int k=1;k<j;k++){
                waste=min(waste,table[i][k]+table[i][j-k]);
            }
            table[i][j]=waste;
        }
    }
    cout<<table[w][h]<<endl;
}
int main(){
    cin>>w>>h;
    int n,temp1,temp2;
    cin>>n;
    init();
    for(int i=1;i<=n;i++){
        cin>>temp1>>temp2;
        table[temp1][temp2]=0;
    }
    solve();
    return 0;
}