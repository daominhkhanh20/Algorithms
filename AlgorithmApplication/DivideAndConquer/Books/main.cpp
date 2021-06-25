#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int N=506;
int a[N];

void input(){
    cin>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
}

int check(int mid){
    int cnt=0,temp=0;
    for(int i=1;i<=m;i++){
        temp+=a[i];
        if(temp>mid){
            cnt++;
            temp=a[i];
        }
    }
    if(cnt==k)return 1;
    else if(cnt>k)return 0;
    return -1;
}
void print_result(int max_ele){
    int temp=0;
    for(int i=1;i<=m;i++){
        temp+=a[i];
        if(temp>max_ele){
            temp=a[i];
            if(i==m){
                cout<<a[i];
                break;
            }
            cout<<" / ";
        }
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void solve(){
    int start=0,end;
    for(int i=1;i<=m;i++)end+=a[i];
    int answer=0;

    while(start<end){
        int mid=(start+end)/2;
        int kk=check(mid);
        if(kk==1){
            answer=mid;
            start=mid+1;
        }
        else if(kk==0){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    print_result(answer);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    while(n>0){
        input();
        solve();
        n--;
        memset(a,0,sizeof(a));
    }
    return 0;
}