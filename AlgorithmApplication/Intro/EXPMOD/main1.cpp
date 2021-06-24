#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long 
ull P=1e9+7;

 ull addMod(ull a,ull b){
    a=a%P;
    b=b%P;
    ull c=P-a;
    if(c>b)return a+b;
    return b-c;
}

ull mulMOD(ull a,ull b){
    if(b==0)return 0;
    a=a%P;
    b=b%P;
    ull c=mulMOD(a,b/2);
    c=addMod(c,c);
    if(b&1)c=addMod(a,c);
    return c;

}

ull EXPMOD(ull a,ull b){
    if(b==0)return 1;
    ull c=EXPMOD(a,b/2);
    c=mulMOD(c,c);
    if(b&1)mulMOD(c,a);
    return c;
}
ull main(){
    ull a,b;
    cin>>a>>b;
    cout<<EXPMOD(a,b);
    return 0;
}
