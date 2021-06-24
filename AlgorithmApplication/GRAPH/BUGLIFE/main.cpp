#include<bits/stdc++.h>
using namespace std;

int t;
const int N=2001;
vector<int>a[N];
int n,k,col[N];
void input(){
    cin>>n>>k;
    int x,y;
    for(int i=1;i<=n;i++){
        a[i].clear();
        col[i]=0;
    }
    for(int i=1;i<=k;i++){
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
}
int sus=0;
void solve(int index,int color){
    if(col[index]!=0){
        if(col[index]!=color){
            sus=1;
            return;
        }
    }
    else{
        col[index]=color;
        for(int i=0;i<a[index].size();i++){
            solve(a[index][i],(color%2)+1);
            if(sus)return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    for(int i=1;i<=t;i++){
        sus=0;
        input();
        solve(1,1);
        cout<<"Scenario #"<<i<<":"<<endl;
        if(sus)cout<<"Suspicious bugs found!"<<endl;
        else cout<<"No suspicious bugs found!"<<endl;
    }
    return 0;
}