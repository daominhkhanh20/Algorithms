#include<bits/stdc++.h>
using namespace std;
const int MAX=10;
int n,a[MAX];
bool visit[MAX];

bool check(int value){
    return !visit[value];
}

void solution(){
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void TRY(int index){
    for(int i=1;i<=n;i++){
        if(check(i)){
            a[index]=i;
            visit[i]=true;
            if(index==n)solution();
            else TRY(index+1);
            visit[i]=false;
        }
    }
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)visit[i]=false;
    TRY(1);
    return 0;
}
