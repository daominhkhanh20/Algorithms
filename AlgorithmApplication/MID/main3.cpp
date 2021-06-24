#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>c,d,a,b;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    int x[n+1];
    for(int i=0;i<n;i++){
        cin>>x[i];
        if(x[i]<0)c.push_back(-x[i]);
        else if(x[i]>0)d.push_back(x[i]);
    }

    if(n==1 || c.size()==0){
        cout<<1;
        return 0;
    }

    sort(c.begin(),c.end());
    sort(d.begin(),d.end());
    if(c.size()<d.size()){
        a=c;
        b=d;
    }
    else{
        a=d;
        b=c;
    }
    int cnt=1;
    int left=0;
    for(int i=0;i<a.size();i++){
        if(i==0){
            for(int j=0;j<b.size();j++){
                if(b[j]<a[i]){
                    cnt+=1;
                    break;
                }
            }
        }
        else {
            for(int j=0;j<b.size();j++){
                if(a[left]<b[j] && b[j]<a[i]){
                    cnt+=2;
                    left=i;
                    break;
                }
            }
        }
    }
    int temp=0;
    for(int j=0;j<b.size();j++){
        if(b[j]>a[left]){
            cnt+=1;
            temp=b[j];
            break;
        }
    }

    if(temp!=0){
        for(int j=0;j<a.size();j++){
            if(a[j]>temp){
                cnt+=1;
                temp=b[j];
                break;
            }
        }
    }

    cout<<cnt<<endl;
    
    return 0;
}