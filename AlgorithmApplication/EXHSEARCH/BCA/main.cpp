#include<bits/stdc++.h>
using namespace std;

int n,m,k;
vector<int>a[31];
int list_course_conflict[33][33];
int course_id_teacher[33],result=INT_MAX;
int max_course[11];
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            int x;
            cin>>x;
            a[x].push_back(i);
        }
    }
    int n_course_conflict;
    cin>>n_course_conflict;
    int x,y;
    for(int i=1;i<=n_course_conflict;i++){
        cin>>x>>y;
        list_course_conflict[x][y]=1;
        list_course_conflict[y][x]=1;
    }
}

bool check(int course_id,int gv_i){
    for(int i=1;i<course_id;i++){
        if(list_course_conflict[i][course_id]){
            if(course_id_teacher[i]==gv_i)return false;
        }
    }
    return true;
}
void TRY(int course_id){
    for(int gv_i:a[course_id]){
        if(check(course_id,gv_i)){
            course_id_teacher[course_id]=gv_i;
            max_course[gv_i]++;
            if(course_id==m){
                int temp=0;
                for(int i=1;i<=n;i++){
                    temp=max(temp,max_course[i]);
                }
                result=min(result,temp);
            }
            else if(max_course[gv_i]<result) TRY(course_id+1);
            max_course[gv_i]-=1;
            course_id_teacher[course_id]=0;
        }
    }
}

int main(){
    input();
    TRY(1);
    if(result==INT_MAX)cout<<-1<<endl;
    else cout<<result<<endl;
    return 0;
}