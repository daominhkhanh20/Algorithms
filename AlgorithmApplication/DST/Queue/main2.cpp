#include<bits/stdc++.h>
using namespace std;
int n;
const int N=1e5+5;
int a[N],result[N];

void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
}
void solve(){
    memset(result,-1,sizeof(result));
    vector<int>v1,v2;
    for(int i=n;i>0;i--){
        if(v1.size()==0|| v1.back()>=a[i]){
            v1.push_back(a[i]);
            v2.push_back(i);
        }

        else{
            int j=lower_bound(v1.rbegin(),v1.rend(),a[i])-v1.rbegin();
            j=v1.size()-j;
            result[i]=v2[j]-i-1;
        }
    }
    for(int i=1;i<=n;i++)cout<<result[i]<<" ";
}

int main(){
    input();
    solve();
    return 0;
}