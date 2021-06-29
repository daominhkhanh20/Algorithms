#include<bits/stdc++.h>
using namespace std;

const int N=55;
int n,k;
bool visit[N];
int d[N][N],a[N];
int temp_distance,min_distance=INT_MAX;
int pre[N];
int temp_weight=0;
vector<int>list_node;
int max_search=10,cnt_search=0;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cin>>d[i][j];
        }
    }
}
void print_result(){
    cout<<min_distance<<endl;
    cout<<list_node.size()<<endl;
    for(int i=0;i<list_node.size();i++){
        cout<<list_node[i]<<" ";
    }
}

void solution(int current_index){
    temp_distance+=d[current_index][0];
    min_distance=temp_distance;
    temp_distance-=d[current_index][0];
    list_node.clear();
    list_node.push_back(current_index);
    while(pre[current_index]!=0){
        current_index=pre[current_index];
        list_node.push_back(current_index);
    }
    // cnt_search+=1;
    // if(cnt_search==max_search){
    //     cout<<"max"<<endl;
    //     print_result();
    //     exit(0);
    // }
}
bool check(int index){
    if(visit[index])return false;
    return true;
}

void TRY(int start){
    for(int i=1;i<=n;i++){
        if(check(i)){
            visit[i]=true;
            temp_distance+=d[start][i];
            pre[i]=start;
            // for(int j=1;j<=a[i];j++){
            //     temp_weight+=j;
            //     if(temp_weight>=k && temp_distance+d[i][0]<min_distance)solution(i);
            //     else TRY(i);
            //     temp_weight-=j;
            // }
            temp_weight+=a[i];
            if(temp_weight>=k && temp_distance+d[i][0]<min_distance)solution(i);
            else TRY(i);
            temp_weight-=a[i];

            temp_distance-=d[start][i];
            pre[i]=-1;
            visit[i]=false;
        }
    }
}
void solve(){
    memset(pre,-1,sizeof(pre));
    visit[0]=true;
    TRY(0);
    print_result();
    
}

int main(){
    input();
    solve();
    return 0;
}