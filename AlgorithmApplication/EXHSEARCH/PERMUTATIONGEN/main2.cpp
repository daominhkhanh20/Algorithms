#include<bits/stdc++.h>
using namespace std;
#define N 10000
int x[N];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    
    if(next_permutation(x,x+n)){
        for(int i=0;i<n;i++){
            cout<<x[i]<<" ";
        }
    }
    else cout<<-1;
    return 0;
}
