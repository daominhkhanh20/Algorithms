#include<bits/stdc++.h>
using namespace std; 
map<int,int>a;
int n;
vector<int>digit;
void preprocess(){
    cin>>n;
    int temp=1000-n;
    while(temp>0){
        int d=temp%10;
        digit.push_back(d);
        temp=temp/10;
    }

    // for(int i:digit)cout<<i<<" ";
    // cout<<endl;
}

int solve(int t){
    if(t<5)return t;
    return t-4;
}

int main(){
    preprocess();
    
    int result=0;
    for(int i=0;i<digit.size();i++){
        int temp=digit[i];
        result+=solve(temp);
    }
    cout<<result<<endl;
    return 0;
}