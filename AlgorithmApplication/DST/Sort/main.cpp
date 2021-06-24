#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin>>n;
    vector<int>a;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
