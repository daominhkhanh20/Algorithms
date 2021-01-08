#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> kClosest(vector<vector<int>> points,int k){
    vector<vector<int>>result;
    priority_queue<pair<float,int>,vector<pair<float,int>>,greater<pair<float,int>>>a;
    int n=points.size();
    cout<<n<<endl;
    for(int i=0;i<n;i++){
        int x=points[i][0],y=points[i][1];
        a.push({sqrt(x*x+y*y),i});
    }
    for(int i=0;i<k;i++){
        int index=a.top().second;
        result.push_back(points[index]);
        a.pop();
    }
    return result;

}

int main(){
    int n,k;
    cin>>k>>n;
    vector<vector<int>> points;
    int x,y;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        vector<int>t;
        t.push_back(x);
        t.push_back(y);
        points.push_back(t);
    }
    vector<vector<int>>result=kClosest(points,k);
    for(int i=0;i<k;i++){
        cout<<result[i][0]<<" "<<result[i][1]<<endl;
    }
    return 0;
}
