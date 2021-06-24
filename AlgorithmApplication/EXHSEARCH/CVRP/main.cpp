#include<bits/stdc++.h>
using namespace std;
#define N 1000
/*
n: number customer
K: number truck
q: maximum kg for each truck can carry
 * */
int n,K,q;
int d[N];//save number package for each user
int x[N];//x[v] is the next point of v on the route
int y[N];//y[v] is the first client point of the route
int load[N];
bool visit[N];
int segment;//when number segments is n+K, that mean we ca finished algorithms
int result=0;
//void solution(){
//    for(int k=1;k<=K;k++){
//        cout<<"Route["<<k<<"]"<<endl;
//        cout<<0<<"-->";
//        int s=y[k];
//        while(s>0){
//            cout<<s<<"-->";
//            s=x[s];
//        }
//        cout<<0<<" Load:"<<load[k]<<endl;
//    }
//    cout<<"----------------------------------"<<endl;
//}
void updateBest(){
    int temp=0;
    for(int i=1;i<=K;i++){
        temp+=d[0][y[i]];
    }
}
bool checkX(int v,int k){
    if(v==0)return true;
    if(visit[v]) return false;
    if(load[k]+d[v]>q)return false;
    return true;
}
bool checkY(int v,int k){
    if(visit[v])return false;
    else if(load[k]+d[v]>q)return false;
    return true;
}
void TryX(int s, int k){
    for(int v=0;v<=n;v++){
        if(checkX(v,k)){
            x[s]=v;
            load[k]+=d[v];
            visit[v]=true;
            segment+=1;
            if(v==0){
                if(k==K){
                    if(segment==n+K){
                        result++;
                        updateBest();
                    }
                }
                else{
                    TryX(y[k+1],k+1);
                }
            }
            else TryX(v,k);

            load[k]-=d[v];
            visit[v]=false;
            segment-=1;
        }
    }

}

void TryY(int k ){
    /*
     *Main idea:
     - First, we assign 1 package for each truck
     - Second,  each truck i-th, we search list destination that can move and back to 
     the storage(destination 0). When it come back to storage, we search route for truck (i+1)th
     
     * */
    for(int v=y[k-1]+1;v<=n;v++){
        if(checkY(v,k)){
            y[k]=v;
            visit[v]=true;
            segment+=1;
            load[k]+=d[v];
            if(k==K){
                // we have been assigned 1 package for all truck
                TryX(y[1],1);
            }
            else{
                //next to the truck (i+1)th
                TryY(k+1);
            }
            visit[v]=false;
            load[k]-=d[v];
            segment-=1;

        }
    }
}

void solver(){
    y[0]=0;
    d[0]=0;
    segment=0;
    for(int i=1;i<=K;i++)load[i]=0;
    for(int i=1;i<=n;i++)visit[i]=false;
    TryY(1);
}
void input(){
    cin>>n>>K>>q;
    for(int i=1;i<=n;i++){
        cin>>d[i];
    }
}
int main(){
    input();
    solver();
    cout<<result;
    return 0;
}
