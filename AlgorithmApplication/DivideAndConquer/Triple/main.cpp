#include<bits/stdc++.h>
using namespace std;
int n,k;
const int N=5001;
int a[N];

int search(int start,int last,int key){
    if(start<=last){
        int mid=start+(last-start)/2;
        if(a[mid]==key) return 1+search(start,mid-1,key)+search(mid+1,last,key);
        else if(a[mid]<key)return search(mid+1,last,key);
        else return search(start,mid-1,key);
    }
    return 0;
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int cnt=0;
    sort(a,a+n+1);
    for(int i=1;i<=n-2;i++){
        for(int j=i+1;j<=n-1;j++){
            int temp=k-a[i]-a[j];
            if(temp<=0)continue;
            cnt+=search(j+1,n,temp);
        }
    }
    cout<<cnt;
    return 0;
}