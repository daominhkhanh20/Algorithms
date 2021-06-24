#include<bits/stdc++.h>
using namespace std;
 
int main(){
        string a,b;
        cin>>a;
        cin>>b;
        int n=a.length(),m=b.length();
        int len=max(n,m),x=0,y=0,i=n-1,j=m-1;
        vector<int>s(len,0);
        int mem=0,index=len-1;
        while(i>=0 || j>=0){
            if(i>=0 && j>=0){
                x=a[i]-'0';
                y=b[j]-'0';
                s[index]=(x+y+mem)%10;
                mem=(x+y+mem)/10;
                i--;j--;index--;
            }
            else if(i>=0 && j<0){
                x=a[i]-'0'+mem;
                mem=x/10;
                s[index]=x%10;
                index--;i--;
        }
        else if(i<0 || j>=0){
            y=b[j]-'0'+mem;
            mem=y/10;
            s[index]=y%10;
            index--;j--;
        }
    }

    if(mem!=0)s.insert(s.begin(),mem);
    for(int i=0;i<s.size();i++){
        cout<<s[i];
    }
    return 0;
}
