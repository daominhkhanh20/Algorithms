//https://www.hackerearth.com/fr/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/win-the-game/description/
#include<bits/stdc++.h>
using namespace std;

int main(){
    double result[3000];
    int t;
    cin>>t;
    while(t-->0){
        double r,g;
        cin>>r>>g;
        double count=r+g;
        if(g==0||r==0){
            cout<<"1.000000"<<endl;
            continue;
        }
        result[1]=r/count;
        double x=g,y=count-1;
        for(int i=2;i<=count;i++){
            result[i]=result[i-1]*x/y;//dynamic programming expression
            if(x>0)--x;
            --y;
        }

        double ans=0;
        for(int i=1;i<=count;i+=2){
            ans+=result[i];
        }
        cout<<fixed;
        cout<<setprecision(6);
        cout<<ans<<endl;
    }
}