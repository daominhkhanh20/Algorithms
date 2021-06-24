#include <bits/stdc++.h>
using namespace std;
string t;
int k;
int res=0;
int v[1000];
int mark[1000];
int tong=0;
void TRY(int e){
        if(mark[e]==0){
            for(int i=-1;i<2;i=i+2){
                v[e]=i;
                mark[e]=1;
                tong+=v[e];
                if(tong>0) {
                    tong-=v[e];
                    mark[e]=0;
                    continue;
                }
                if(e==k-1) {
                    if(tong==0) 
                    {
                        res++;
                        // for(int r=0;r<k;r++) cout<<v[r];
                        // cout<<"\n";
                    }
                } 
                else{

                    TRY(e+1);
                }
                tong-=v[e];
                mark[e]=0;
            }
        }
        else{
            tong+=v[e];
            if (tong > 0)
            {
                // tong -= v[e];
                // mark[e]=0;
                
            }
            else if(e==k-1) {
                if(tong==0) 
                    {
                        res++;
                        // for(int r=0;r<k;r++) cout<<v[r];
                        // cout<<"\n";
                    }
            }
            else TRY(e+1);
            tong-=v[e];
        }
}
int main(){
    memset(mark,0,sizeof(mark));
    getline(cin,t);
    k= t.length();
    // cout<<k;
    if(k==0 ) {
        cout<<0;
        return 0;
    }
    if(k%2==1){
        cout<<0;
        return 0;
    }
    for(int i=0;i<k;i++){
        if(t[i]=='(') {
            v[i]=-1;
            mark[i]=1;}
        else if(t[i]==')') {
            v[i]=1;
            mark[i]=1;
        }
        else {
            v[i]=100;
            mark[i]=0;
        }
    }
    TRY(0);
    cout<<res;

}