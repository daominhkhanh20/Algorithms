#include<bits/stdc++.h>
using namespace std;
const int M=1e9+7;
#define N 1005
int f[N][N];
string s;
void find(){
    f[0][0]=1;
    int n=s.length()-1;
    for(int i=1;i<=n;i++){
        if(s[i]=='('){
            for(int k=0;k<=n;k++){
                f[i][k]=f[i-1][k-1];
            }
        }
        else if(s[i]==')'){
            for(int k=0;k<=n;k++){
                f[i][k]=f[i-1][k+1];
            }
        }
        else if(s[i]=='?'){
            for(int k=0;k<=n;k++){
                f[i][k]=f[i-1][k-1];
                f[i][k]+=f[i-1][k+1];
                f[i][k]=f[i][k]%M;
            }
        }
    }
    cout<<f[n][0]<<endl;
}

int main(){
    cin>>s;
    s=" "+s;
    find();
    return 0;
}