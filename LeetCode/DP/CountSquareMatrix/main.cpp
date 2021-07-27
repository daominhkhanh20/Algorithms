#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static void show(vector<vector<int>>temp){
        int n=temp.size();
        int m=temp[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<temp[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    int countSquares(vector<vector<int>>&matrix){
        int n=matrix.size();
        int m=matrix[0].size();
        int result=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i && j && matrix[i][j]){
                    matrix[i][j]=min(matrix[i-1][j-1],min(matrix[i][j-1],matrix[i-1][j]))+1;
                }
                result+=matrix[i][j];
            }
        }
        show(matrix);
        return result;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<int>> matrix;
    int n,m,x;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        vector<int>temp;
        for(int j=0;j<m;j++){
            cin>>x;
            temp.push_back(x);            
        }
        matrix.push_back(temp);
    }
    Solution solution;
    int result=solution.countSquares(matrix);
    cout<<result<<endl;
    return 0;
}