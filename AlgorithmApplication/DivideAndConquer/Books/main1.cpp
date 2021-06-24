#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int N=506;
int a[N];

void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
}

bool check(int mid){

}
void print_result(int max_ele){
    int temp=0;
    for(int i=1;i<=n;i++){
        temp+=a[i];
        cout<<a[i]<<" ";
        if(temp>max_ele){
            temp=a[i];
            cout<<" / ";
        }
    }
}
void solve(){
    int *max=max_element(a,a+m+1);
    int start=*max;
    int end=0;
    for(int i=1;i<=m;i++)end+=a[i];
    int answer=0;

    while(start<end){
        int mid=(start+end)/2;
        if(check(mid)){
            answer=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    print_result(answer);
}

int main(){
    cin>>n;
    while(n>0){
        input();
        solve();
        n--;
        memset(a,0,sizeof(a));
    }
    return 0;
}