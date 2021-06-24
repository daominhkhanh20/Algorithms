#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long x;
    cin>>n;
    vector<long long>s;
    for(int i=0;i<n;i++){
        cin>>x;
        s.push_back(x);
    }

    long long result=INT16_MIN,sum=0;
    for(int i=0;i<n;i++){
        sum+=s[i];
        if(sum>result)result=sum;
        if(s[i]>result)result=s[i];
        if(s[i]>sum)sum=s[i];

    }
    cout<<result;
    return 0;
}