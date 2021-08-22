#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    int numTeams(vector<int>& rating) {
        int n=rating.size();
        int result=0;
        for(int i=1;i<n-1;i++){

            int less_left=0,greater_left=0;
            for(int j=0;j<i;j++){
                if(rating[j]>rating[i])greater_left++;
                else less_left++;
            }
            
            int less_right=0,greater_right=0;
            for(int j=i+1;j<n;j++){
                if(rating[j]>rating[i])greater_right++;
                else less_right++;
            }
            //cout<<less_left<<" "<<greater_left<<" "<<less_right<<" "<<greater_right<<endl;
            result+=less_left*greater_right+greater_left*less_right;
        }
        return result;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>a;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    Solution solution;
    int result=solution.numTeams(a);
    cout<<result;
    return 0;
}