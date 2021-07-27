#include<bits/stdc++.h>
using namespace std;

vector<int> final(vector<int>temp){
    temp.push_back(5);
    return temp;
}

int main(){
    vector<int>temp;
    vector<int>result=final(temp);
    for(int i:result){
        cout<<i<<endl;
    }
    return 0;
}