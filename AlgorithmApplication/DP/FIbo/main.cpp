#include<bits/stdc++.h>
using namespace std;
#define N 10000000
int f[N];
int fibo(int n){
    if(n<=1){
        f[n]=1;
        return 1;
    }

    if(f[n]>0)return f[n];
    f[n]=fibo(n-1)+fibo(n-2);
    return f[n];
}
int main(){
    cout<<fibo(5);
    return 0;
}
