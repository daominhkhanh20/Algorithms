#include<bits/stdc++.h>
using namespace std;
#define N 31
#define M 11
int m,n,k;
int x[N];
int result=1e9;
int max_course[M];
vector<int>list_course[N];
int course_conflict[N][N];
void input(){
    cin>>m>>n;
    int t,x;
    for(int i=1;i<=m;i++){
        cin>>t;
        for(int j=0;j<t;j++){
            cin>>x;
            list_course[x].push_back(i);
        }
    }
    cin>>k;
    int t1,t2;
    for(int i=0;i<k;i++){
        cin>>t1>>t2;
        course_conflict[t1][t2]=1;
        course_conflict[t2][t1]=1;
    }

}

void updateBest(){
    int temp=0;
    for(int i=1;i<=m;i++){
        temp=max(temp,max_course[i]);
    }
    result=min(result,temp);
}
bool check(int course,int teacher_id){
    for(int i=1;i<course;i++){
        if(course_conflict[i][course]==1){
            if(x[i]==teacher_id)return false;
        }
    }
    return true;
}
void TRY(int course){
    for(int teacher_id:list_course[course]){
        if(check(course,teacher_id)){
            x[course]=teacher_id;
            max_course[teacher_id]+=1;
            if(course==n)updateBest();
            else if(max_course[teacher_id]<result)TRY(course+1);
            max_course[teacher_id]-=1;
        }
    }
}
int main(){
    input();
    TRY(1);
    if(result==INT_MAX)cout<<-1;
    else cout<<result;
    return 0;
}
