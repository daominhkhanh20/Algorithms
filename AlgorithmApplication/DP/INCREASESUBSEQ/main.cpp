#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n;
int x[N],f[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    fill_n(f,n+1,1);
    int temp=f[1];
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            if(x[i]>x[j] ){
                f[i]=max(f[i],f[j]+1);
                temp=max(temp,f[i]);
            }
        }
    }
    cout<<temp<<endl;
    return 0;
}