#include<bits/stdc++.h>
using namespace std;

int t;
vector<int>a,b;
int main(){
    cin>>t;
    for(int i=1;i<=t;i++){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            a.push_back(x);
        }
        int res=0;
        b=a;
        while(true){
            a=b;
            // cout<<"a.size():"<<a.size()<<endl;
            if(b.size()==2){
                res+=(b[0]+b[1]);
                break;
            }
            n=a.size();
            b.clear();
            int i,temp=0;
            for(i=0;i<n-1;i+=2){
                temp=max(temp,a[i]+a[i+1]);
                b.push_back(a[i]+a[i+1]);
            }
            res+=temp;
            if(n%2==1)b.push_back(a[n-1]);
            a.clear();
        }
        cout<<res<<endl;
        a.clear();
        b.clear();
    }
    return 0;
}