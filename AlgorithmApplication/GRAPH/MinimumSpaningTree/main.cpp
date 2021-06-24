#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;

struct Edge{
    int u,v,w;
    Edge(int _u,int _v,int _w){
        u=_u;
        v=_v;
        w=_w;
    }
};
vector<Edge>l;
int n,m;
int p[N],r[N];
long long result=0;
void input(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        l.push_back(Edge(u,v,w));
    }
}
void make_set(int x){
    p[x]=x;
    r[x]=0;
}
bool cmp(Edge &x,Edge &y){
    return x.w<y.w;
}

int find(int x){
    if(x!=p[x])p[x]=find(p[x]);
    return p[x];
}

void unifi(int x,int y){
    if(r[x]>r[y]){
        p[y]=x;
    }
    else{
        p[x]=y;
        if(r[x]==r[y])r[y]+=1;
    }
}
void Kruscal(){
    for(int i=1;i<=n;i++){
        make_set(i);
    }

    sort(l.begin(),l.end(),cmp);
    int cnt=0;
    for(int i=0;i<l.size();i++){
        int ru=find(l[i].u);
        int rv=find(l[i].v);
        if(ru!=rv){
            unifi(ru,rv);
            cnt++;
            result+=l[i].w;
            if(cnt==n-1)break;

        }

    }
    cout<<result<<endl;

}

int main(){
    input();
    Kruscal();
    return 0;
}