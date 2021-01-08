//https://leetcode.com/problems/minimum-path-sum/
#include<bits/stdc++.h>
using namespace std;

int solver(vector<vector<int>> &a){
    int m=a.size();//row
    int n=a[0].size();//column
    int result[m][n];
    result[0][0]=a[0][0];
    for(int i=1;i<m;i++){
        result[i][0]=result[i-1][0]+a[i][0];
    }
    for(int i=1;i<n;i++){
        result[0][i]=result[0][i-1]+a[0][i];
    }

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            result[i][j]=min(result[i-1][j],result[i][j-1])+a[i][j];
        }
    }
    return result[m-1][n-1];

}
void show(vector<vector<int>>a){
    int m=a.size();
    int n=a[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    //freopen(".inp","r",stdin);
    int n,m;
    while(cin>>m>>n){
        int x;
        vector<vector<int>> a;
        for(int i=0;i<m;i++){
            vector<int>temp;
            for(int j=0;j<n;j++){
                cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
        show(a);
        int result=solver(a);
        cout<<result<<endl;
    }
    return 0;
}
