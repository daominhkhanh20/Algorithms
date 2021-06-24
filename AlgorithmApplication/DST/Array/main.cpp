#include<bits/stdc++.h>
using namespace std;
int n;
const int N=104;
vector<int>a,b,c;
int m[N];
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int x;
    for(int i=1;i<=n;i++){
        cin>>m[i];
    }
    sort(m+1,m+n+1);
    for(int i=1;i<=n;i++){
        int x=m[i];
        if(x<0)a.push_back(x);
        else if(x==0)b.push_back(x);
        else c.push_back(x);
    }
}

void solve(){
    if(a.size()==1)cout<<1<<" "<<a[0]<<endl;
    else if(a.size()==2){
        cout<<1<<" "<<a[0]<<endl;
        b.insert(b.begin(),a[1]);
    }
    else if(a.size()>=3){
        cout<<a.size()-2<<" ";
        for(int i=0;i<a.size()-2;i++)cout<<a[i]<<" ";
        cout<<endl;
        c.insert(c.begin(),a[a.size()-2]);
        c.insert(c.begin(),a[a.size()-1]);
    }
    cout<<c.size()<<" ";
    for(int i=0;i<c.size();i++){
        cout<<c[i]<<" ";
    }
    cout<<endl;
    cout<<b.size()<<" ";
    for(int i=0;i<b.size();i++)cout<<b[i]<<" ";
}
int main(){
    input();
    solve();
    return 0;
}