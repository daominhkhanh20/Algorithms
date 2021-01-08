//https://www.hackerearth.com/fr/practice/algorithms/searching/linear-search/practice-problems/algorithm/square-transaction-20/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100000
ll a[N];
int binarySearch(ll target,int left,int right){
    if(target>a[right]){
        return -1;
    }
   
  int result=0;
    while(left<=right){
		 int med=(left+right)/2;
        if(a[med]>=target){
		     right=med-1;
		     result=med;
		}
		else{
		     left=med+1;
		}
    }
    return result;         
    
}
int main(){
    int t;
    cin>>t;
    a[0]=0;
    for(int i=1;i<=t;i++){
        cin>>a[i];
        a[i]+=a[i-1];
    }
    int q;
    cin>>q;
    while(q-->0){
        ll target;
        cin>>target;
        cout<<binarySearch(target,1,t)<<endl;
    }
    return 0;
}
