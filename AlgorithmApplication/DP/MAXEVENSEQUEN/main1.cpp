#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=1e6+5;
bool solve0[N]; //sovle0[i]=true if s0[i] exist (#0)
bool solve1[N]; // solve1[i]=true if s1[i]exist (#0)
ll s0[N],s1[N];// sum seven, sum old 
ll start_index0[N],start_index1[N];
ll n,a[N];
ll ans=INT_MIN;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
}

void solve(){
    if(a[1]%2==0){
        s0[1]=a[1];solve0[1]=true; 
        solve1[1]=false;start_index0[1]=1;
    }
    else{
        s1[1]=a[1];solve1[1]=true,
        solve0[1]=false;start_index1[1]=1;
    }

    for(int i=2;i<=n;i++){
        if(a[i]%2==0){
            if(solve0[i-1]){
                if(s0[i-1]>0){
                    s0[i]=a[i]+s0[i-1];
                    start_index0[i]=start_index0[i-1];
                }
                else{
                    s0[i]=a[i];
                    start_index0[i]=i;
                }
            }
            else{
                s0[i]=a[i];
                start_index0[i]=i;
            }
            solve0[i]=true;

            if(solve1[i-1]){
                s1[i]=a[i]+s1[i-1];
                start_index1[i]=start_index1[i-1];
                solve1[i]=true;
            }
            else solve1[i]=false;
        }
        else{
            if(solve1[i-1]){
                s0[i]=s1[i-1]+a[i];
                start_index0[i]=start_index1[i-1];
                solve0[i]=true;
            }
            else{
                solve0[i]=false;
            }

            if(solve0[i-1]){
                if(s0[i-1]>0){
                    s1[i]=a[i]+s0[i-1];
                    start_index1[i]=start_index0[i-1];
                }
                else{
                    s1[i]=a[i];
                    start_index1[i]=i;
                }
            }
            else{
                s1[i]=a[i];
                start_index1[i]=i;
            }
            solve1[i]=true;

        }
    }
    bool not_found=true;
    for(int i=1;i<=n;i++){
        if(solve0[i]){
            if(not_found){
                ans=s0[i];
                not_found=false;
            }
            else{
                if(ans<s0[i]){
                    ans=s0[i];
                }
            }
        }
    }
    if(not_found)cout<<"NOT_FOUND";
    cout<<ans<<endl;
}

int main(){
    input();
    solve();
    return 0;
}