#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

int bfs(int a,int b,int c){
    int x=a,y=0;
    int res=1,temp;
    while(x!=c || y!=c ){
        temp=min(x,b-y);
        x-=temp;
        y+=temp;
        res++;
        if(x==c || y==c) break;
        if(x==0){
            x=a;
            res++;
        }
        if(y==b){
            y=0;
            res++;
        }
    }
    return res;
}
int gcd(int x,int y){
    if(y==0)return x;
    return gcd(y,x%y);
}
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if(c>max(a,b) || c%gcd(a,b)!=0)cout<<-1;
    else {
        cout<<min(bfs(a,b,c),bfs(b,a,c));
    }
    return 0;
}
