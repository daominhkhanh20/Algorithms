#include<bits/stdc++.h>
using namespace std;
#define N 10005
#define ll long long
int n,k;
int x[N],s[N];
void find(){
    ll max_current=s[k];
    int max_length=k;
    for(int i=k;i<=n;i++){
        for(int j=i;j<=n;j++){
            if((s[j]-s[j-i])*1.0/i>max_current*1.0/max_length){
                max_current=s[j]-s[j-i];
                max_length=i;
            }
        }
    }
    printf("%.5lf",max_current*1.0/max_length);
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>x[i];
        s[i]+=x[i]+s[i-1];
    }
    find();
    return 0;

}
