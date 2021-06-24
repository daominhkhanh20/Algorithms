#include<bits/stdc++.h>
using namespace std;
#define N 1000
#define ull unsigned long long 
ull n,k;
ull temp=1;
vector<ull>a;

bool check(){
    ull s=1;
    for(int i=2;i<=n;i++){
        s*=i;
        if(s>k)return false;
    }
    return true;
}
ull calculate(int n){
    ull s=1;
    if(n==0){
        s=1;
    }
    else{
        s=n;
        while(n>1 && k>s){
            s*=n-1;
            n--;
        }
    }
    temp=k%s;
    return k/s;
}

void find(){
    k-=1;
    while(a.size()!=0){
        if(n==0){
            cout<<a[0];
            break;
        }
        ull sele=calculate(n-1);
        cout<<a[sele]<<" ";
        a.erase(a.begin()+sele);
        k=temp;
        n--;
    }
}
int main(){
    cin>>n>>k;
    if(check()){
        cout<<-1;
        return 0;
    }
    for(int i=1;i<=n;i++){
        a.push_back(i);
    }
    find();
    return 0;


}
