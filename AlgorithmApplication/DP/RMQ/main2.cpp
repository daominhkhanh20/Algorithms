#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
#define ll long long 
vector<pair<ll,ll>>a;
int n,m;
bool cmp(pair<ll,ll>&x,pair<ll,ll>&y){
    return x.second<y.second;
}

void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    ll x;
    for(int i=0;i<n;i++){
        cin>>x;
        a.push_back({i,x});
    }
    sort(a.begin(),a.end(),cmp);
    cin>>m;
}
void solve(){
    int x,y,i=0;
    ll sum=0;
    while(i<m){
        cin>>x>>y;
        int j=0;
        while(j<n){
            if(a[j].first>=x && a[j].first<=y){
                sum+=a[j].second;
                break;
            }
            j++;
        }
        i++;
    }
    cout<<sum<<endl;
}
int main(){
    input();
    solve();
    return 0;
}