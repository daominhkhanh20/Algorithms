#include<bits/stdc++.h>
using namespace std;
#define N 20
#define M 10
int n,m;
int load_of_preiod[M];
int credits[N];
int prerequisites[N][N];
int x[N];//x[i]=k: course i is assigned for period k-th
int result=INT_MAX;
int load;
void input(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>credits[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>prerequisites[i][j];
        }
    }    
}
void update(){
    int temp=INT_MIN;
    for(int i=1;i<=m;i++){
        temp=max(temp,load_of_preiod[i]);
    }
    result=min(result,temp);
}
bool check(int period,int course){
    for(int i=1;i<=course;i++){
        if(prerequisites[i][course]==1){
            if(x[i]>=period) return false;
        }
    }
    return true;
}
void TRY(int course){
    for(int i=1;i<=m;i++){
        if(check(i,course)){
            x[course]=i;
            load_of_preiod[i]+=credits[course];
            if(course==n)update();
            else if(load_of_preiod[i]<result) TRY(course+1);
            load_of_preiod[i]-=credits[course];

        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    TRY(1);
    cout<<result;
    return 0;
}
