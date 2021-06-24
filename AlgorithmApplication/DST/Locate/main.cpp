#include<bits/stdc++.h>
using namespace std;
#define N 1000
int t;
int main(){
    cin>>t;
    int temp=0;
    int f[2*N+1][2*N+1];
    while(temp<t){
        int l,c;
        cin>>l>>c;
        vector<pair<int,int>>b;
        memset(f,0,sizeof(f));

        int x;
        for(int i=0;i<l;i++){
            for(int j=0;j<c;j++){
                cin>>x;
                if(x)b.push_back({i,j});
            }
        }
        int result=0;
        for(int i=0;i<l;i++){
            for(int j=0;j<c;j++){
                cin>>x;
                if(x){
                    for(int k=0;k<b.size();k++){
                        int t1=b[k].first,t2=b[k].second;
                        f[i-t1+N][j-t2+N]+=1;
                        result=max(result,f[i-t1+N][j-t2+N]);
                    }
                }
            }
        }
        cout<<result<<endl;
        temp++;
    }
    return 0;
}
