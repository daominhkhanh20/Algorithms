#include<bits/stdc++.h>
using namespace std;
const int N=20,M=10;
int load[M],a[N][N],c[N],n,m;
int result=INT_MAX;
int list_course[N];
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)cin>>a[i][j];
    }
}
void update(){
    int temp=INT_MIN;
    for(int i=1;i<=m;i++)temp=max(temp,load[i]);
    result=min(result,temp);
}
bool check(int peroid,int course_id){
    for(int i=1;i<=course_id;i++){
        if(a[i][course_id]==1){
            if(list_course[i]>=peroid)return false;
        }
    }
    return true;
}
void TRY(int course_id){
    for(int i=1;i<=m;i++){
        if(check(i,course_id)){
            list_course[course_id]=i;
            load[i]+=c[course_id];
            if(course_id==n)update();
            else if(load[i]<result) TRY(course_id+1);
            load[i]-=c[course_id];
            list_course[course_id]=0;
        }
    }
}

int main(){
    input();
    TRY(1);
    cout<<result<<endl;
    return 0;
}