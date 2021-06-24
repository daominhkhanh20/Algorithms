#include<bits/stdc++.h>
using namespace std;

typedef struct{
    int x,y,z;
}Block;

Block a[100];
int n,maxh[100];
void input(){
    cin>>n;
    if(n==0)exit(0);
    int x,y,z;
    for(int i=1;i<=n;i++){
        cin>>x>>y>>z;
        a[3*i-2].x=x;
        a[3*i-2].y=y;
        a[3*i-2].z=z;
        a[3*i-1].x=y;
        a[3*i-1].y=z;
        a[3*i-1].z=x;
        a[3*i].x=z;
        a[3*i].y=x;
        a[3*i].z=y;
    }
}

int dp(int index){
    if(maxh[index]!=0)return maxh[index];
    maxh[index]=a[index].z;
    for(int i=1;i<=3*n;i++){
        if( a[index].x > a[i].x && a[index].y > a[i].y || a[index].y > a[i].x && a[index].x > a[i].y){
            maxh[index]=max(maxh[index],a[index].z +dp(i));
        }
    }
    return maxh[index];
}

int main(){
    int cnt=1;
    while(1){
        memset(maxh,0,sizeof(maxh));
        input();
        int res=0;
        for(int i=1;i<=3*n;i++){
            // Choose Block i is bottom
            res=max(res,dp(i));
        }
        cout<<"Case "<<cnt++<<": maximum height = "<<res<<endl;
    }
    return 0;
}