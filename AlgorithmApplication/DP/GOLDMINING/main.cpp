#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
#define ll long long 
int n,l1,l2;
ll a[N];
vector<ll>f;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>l1>>l2;
    f.push_back(0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
}

void show(){
    for(int i=1;i<=n;i++){
        cout<<f[i]<<" ";
    }
    cout<<endl;
}

void solve(){
    f.push_back(a[1]);
    ll best=0;
    for(int i=2;i<=n;i++){
        if(i-l1>=1){
            int temp=*max_element(f.begin()+max(i-l2,1),f.begin()+(i-l1+1));
            f.push_back(temp+a[i]);
        }
        else{
            f.push_back(a[i]);
        }
        best=max(best,f[i]);
    }
    cout<<best<<endl;
}

int main(){
    input();
    solve();
    return 0;
}