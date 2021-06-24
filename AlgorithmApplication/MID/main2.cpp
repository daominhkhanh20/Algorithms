#include<bits/stdc++.h>
using namespace std;
int n;
#define N 20
int x[N];
bool visit[N];
void show(){
    for(int i=1;i<=n;i++){
        cout<<visit[i]<<" ";
    }
    cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(!visit[i]){
            visit[i]=true;
            int temp=INT_MIN,index=1;
            for(int j=i+1;j<=n;j++){
                if(!visit[j] && x[i]+x[j]<=6){
                    if(x[j]>temp){
                        temp=x[j];
                        index=j;
                    }
                }
            }
            if(temp!=INT_MIN){
                visit[index]=true;
            }
            cnt++;
        }
        // cout<<"Index:"<<i<<endl;
        // show();
    }
    cout<<cnt;

    return 0;
}