#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,r;
#define N 105
int x[N][N];
bool visit[N];
vector<int>edge[N];
int sum=0;
int segment=0;
int min_result=INT_MAX;
void dfs(vector<int>list_des,int start,int end){
    for(int i=0;i<edge[start].size();i++){
        int v=edge[start][i];
        if(!visit[v] && find(list_des.begin(),list_des.end(),v)!=list_des.end()){
            visit[v]=true;
            sum+=x[start][v];
            segment-=1;
            if(segment==1){
                if(x[v][end]!=0){
                    sum+=x[v][end];
                    min_result=min(sum,min_result);
                }
            }
            else{
                dfs(list_des,v,end);
            }
            visit[v]=false;
            sum-=x[start][v];
            segment+=1;
        }
    }
}

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>r;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>x[i][j];
            if(x[i][j]!=0){
                edge[i].push_back(j);
                edge[j].push_back(i);
            }
        }
    }
    cin.ignore(1);
    for(int i=0;i<r;i++){
        vector<int>list_des;
        string s;
        getline(cin,s);
        int value;
        stringstream str(s);
        while(str>>value){
            list_des.push_back(value);
        }
        segment=list_des.size()-1;
        int start=list_des[0];
        int end=list_des[list_des.size()-1];
        list_des.erase(list_des.begin()+0);
        list_des.pop_back();
        if(list_des.size()==1){
            if(x[start][list_des[0]]==0 || x[list_des[0]][end]==0){
                cout<<0<<endl;
            }
            else cout<<x[start][list_des[0]]+x[list_des[0]][end]<<endl;
        }
        else{
            sum=0;
            memset(visit,false,sizeof(visit));
            visit[start]=true;
            visit[end]=true;
            dfs(list_des,start,end);
            if(min_result==INT_MAX)cout<<0<<endl;
            else cout<<min_result<<endl;
        }        
    }

}