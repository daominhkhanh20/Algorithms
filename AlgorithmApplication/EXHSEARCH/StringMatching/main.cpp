#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int last[N],p[260];
string P,T;
void computeLast(){
    for(int i=0;i<256;i++){
        last[i]=0;
    }
    for(int i=P.length()-1;i>=0;i--){
        if(last[P[i]]==0)last[P[i]]=i;
    }
}

void BoyerMoore(){
    computeLast();
    int s=0,result=0,n=T.length(),m=P.length();

    while(s<=n-m){
        int j=m-1;
        while(j>=0 && T[s+j]==P[j])j--;

        if(j==-1){
            result++;
            s++;
        }
        else{
            int step_size=last[T[s+j]];
            s=s+max(j-step_size,1);
        }
    }
    cout<<result<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    getline(cin,P);
    getline(cin,T);
    BoyerMoore();
    return 0;
}