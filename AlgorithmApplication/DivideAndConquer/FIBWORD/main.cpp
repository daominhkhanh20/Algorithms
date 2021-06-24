#include<bits/stdc++.h>
using namespace std;

#define N 105
#define ll long long
struct word{
    ll cnt;
    string left,right;
}f[N];
int n;
string p;
void find(int index){
    f[0].left=f[0].right="0";
    f[1].left=f[1].right="1";
    f[0].cnt=(p=="0");
    f[1].cnt=(p=="1");

    for(int i=2;i<=n;i++){
        string mid=f[i-1].right+f[i-2].left;
        f[i].cnt=f[i-1].cnt+f[i-2].cnt+(mid.find(p)!=string::npos);

        if(f[i-1].left.length()==p.length()-1)f[i].left=f[i-1].left;
        else{
            string temp=f[i-1].left+f[i-2].left;
            if(temp.length()>p.length()-1)temp=temp.substr(0,p.length()-1);
            f[i].left=temp;
        }

        if(f[i-2].right.length()==p.length()-1)f[i].right=f[i-2].right;
        else{
            string temp=f[i-1].right+f[i-2].right;
            if(temp.length()>p.length()-1)temp=temp.substr(temp.length()-p.length()+1,p.length()-1);
            f[i].right=temp;
        }
    }
    cout<<"Case "<<index<<": "<<f[n].cnt<<endl;
}
int main(){
    int i=0;
    while(cin>>n){
        cin>>p;
        find(++i);
    }
}