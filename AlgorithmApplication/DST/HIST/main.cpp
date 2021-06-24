#include<bits/stdc++.h>
using namespace std;

long long  cal(vector<int>hist){
    stack<int>a;
    long long  result=INT_MIN,i=0;
    while(i<hist.size()){
        if(a.empty()||hist[a.top()]<=hist[i]){
            a.push(i);
            i++;
        }
        else{
            long long top=a.top();
            a.pop();
            long long w=a.empty()?i:i-1-a.top();
            result=max(result,hist[top]*w);
        }
    }

    while(!a.empty()){
        long long top=a.top();
        a.pop();
        long long w=a.empty()?i:i-1-a.top();
        result=max(result,hist[top]*w);
    }
    return result;

}
int main(){
    int n;
    while(1){
        cin>>n;
        if(n==0) break;
        vector<int>hist;
        long long x;
        for(int i=0;i<n;i++){
            cin>>x;
            hist.push_back(x);
        }
        long long result=cal(hist);
        cout<<result<<endl;            
    }
    return 0;
}
