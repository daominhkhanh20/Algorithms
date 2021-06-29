#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int f[N];
vector<int>a;
int n,m;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        a.push_back(x);
    }
    cin>>m;
}
void solve(){
    int x,y;
    long long result=0;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        result+=*min_element(a.begin()+x,a.begin()+y+1);
    }
    cout<<result<<endl;
}

int main(){
    input();
    solve();
    return 0;
}

