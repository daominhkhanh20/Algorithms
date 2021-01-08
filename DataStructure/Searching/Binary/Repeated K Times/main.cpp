//https://www.hackerearth.com/fr/practice/algorithms/searching/linear-search/practice-problems/algorithm/repeated-k-times/
#include<bits/stdc++.h>
using namespace std;
#define N 100001
int a[N];

int smallestRepeatedKTimes(int n,int k){
    unordered_map<int,int>m;
    for(int i=0;i<n;i++){
        m[a[i]]++;
    }
    int result=INT_MAX;
    for(auto i=m.begin();i!=m.end();++i){
        if(i->second==k){
            result=min(result,i->first);
        }
    }
    return (result!=INT_MAX)?result:-1;
}
int main(){
   int n;
   cin>>n;
   for(int i=0;i<n;i++){
       cin>>a[i];
   }
   int k;
   cin>>k;
   cout<<smallestRepeatedKTimes(n,k);
   return 0;

}
