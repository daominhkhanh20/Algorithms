#include<bits/stdc++.h>
using namespace std;

map<char,int>decode={
    {'a',1},{'b',2},{'c',3},
    {'d',1},{'e',2},{'f',3},
    {'g',1},{'h',2},{'i',3},
    {'j',1},{'k',2},{'l',3},
    {'m',1},{'n',2},{'o',3},
    {'p',1},{'q',2},{'r',3},{'s',4},
    {'t',1},{'u',2},{'v',3},
    {'w',1},{'x',2},{'y',3},{'z',4}
};

int main(){
    int n,count;
    cin>>n;
    string s;
    cin.ignore();
    for(int i=0;i<n;i++){
        count=0;
        getline(cin,s);
        //cout<<s<<endl;
        int n=s.length();
        for(int j=0;j<n;j++){
            if(s[j]==' '){
                count++;
                continue;
            }
            count+=decode[s[j]];
        }
        cout<<"Case #"<<i+1<<": "<<count<<endl;
    }
}