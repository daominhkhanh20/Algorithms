#include<bits/stdc++.h>
using namespace std;
//find min number of coins in ta list or[] satisfied sum coins =S
// time complexity O(S*n) n is size list
// not optimization
int minCoin[100];
int main(){
    int v[]={1,3,5};//list coin
    int S=11;//sum 
    int n=sizeof(v)/4;// size list coin
    minCoin[0]=0;

    for(int i=1;i<=S;i++){
        minCoin[i]=INT_MAX;
        for(int j=0;j<n;j++){
            if(v[j]<=i&&minCoin[i-v[j]]+1<minCoin[i]){
                minCoin[i]=minCoin[i-v[j]]+1;
            }
        }
    }

    for(int i=1;i<=S;i++){
        cout<<i<<"-"<<minCoin[i]<<endl;
    }

    return 0;

}