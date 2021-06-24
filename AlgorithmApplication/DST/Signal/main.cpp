#include<bits/stdc++.h>
using namespace std;
int n,b;
vector<pair<pair<int,int>,int>>a;

int cal(){
    int result=INT_MIN,t,t1,t2;
    for(int i=0;i<n;i++){
        t=a[i].second+b;
        t1=a[i].first.first;
        t2=a[i].first.second;
        //cout<<t1<<" "<<t2<<" "<<t<<endl;
        if(t1>=t&&t2>=t)result=max(result,t1+t2-2*a[i].second);  
        //cout<<result<<endl;
    }
    if(result==INT_MIN)return -1;
    return result;
}

int main(){
    cin>>n>>b;
    int x,temp=INT_MIN;
    for(int i=0;i<n;i++){
        cin>>x;
        if(i==0){
            a.push_back({{0,0},x});
            continue;
        }

        temp=max(temp,a[i-1].second);
        a.push_back({{temp,0},x});
    }
    temp=INT_MIN;
    for(int i=n-2;i>=0;i--){
        temp=max(temp,a[i+1].second);
        a[i].first.second=temp;
    }
    //for(int i=0;i<n;i++){
    //    cout<<a[i].first.first<<" "<<" "<<a[i].first.second<<" "<<a[i].second<<endl;
    //}
    int result=cal();
    cout<<result;
    return 0;

}
