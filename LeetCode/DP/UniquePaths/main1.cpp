#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size(),m=obstacleGrid[0].size();
        int a[105][105]={0};
        int exist=0,x=0,y=0;
        while(x<m){
            exist+=obstacleGrid[0][x]==1?1:0;
            if(exist)break;
            a[0][x]=1;
            x++;
        }
        exist=0;
        while(y<n){
            if(obstacleGrid[y][0]==1)exist++;
            if(exist)break;
            a[y][0]=1;
            y++;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(obstacleGrid[i][j]!=1)a[i][j]+=a[i-1][j]+a[i][j-1];
            }
        }
        return a[n-1][m-1];
    }
};

int main(){
    //vector<vector<int>>a={{0,0,0},{0,1,0},{0,0,0}};
    vector<vector<int>>a={{0,0}};
    Solution soluton;
    cout<<soluton.uniquePathsWithObstacles(a);
    return 0;
}