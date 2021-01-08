//https://leetcode.com/problems/unique-paths/submissions/
#include<bits/stdc++.h>
using namespace std;

int uniquePaths(int m,int n){
    int result[m][n];
    for(int i=0;i<m;i++) result[i][0]=1;
    for(int i=0;i<n;i++)result[0][i]=1;
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            result[i][j]=result[i-1][j]+result[i][j-1];
        }
    }
    return result[m-1][n-1];
}
int main(){
    freopen(".inp","r",stdin);
    int m,n;
    while(cin>>m>>n){
        int result=uniquePaths(m,n);
        cout<<result<<endl;
    }
    return 0;
}
