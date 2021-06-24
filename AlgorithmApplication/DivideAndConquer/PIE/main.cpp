#include<bits/stdc++.h>
using namespace std;
#define pi 3.14159265359
#define N 10000+5
int t,n,f;
double a[N];

bool check(double mid){
    int total=0;
    for(int i=1;i<=n;i++){
        total+=int(a[i]/mid);
    }
    return total>=f;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t-->0){
        double sum=0;
        cin>>n>>f;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            a[i]=pi*a[i]*a[i];
            sum+=a[i];
        }
        f++;
        double left=0.0,right=sum/f;
        while(right-left>0.000001){
            double mid=(left+right)/2;
            if(check(mid))left=mid;
            else right=mid;
        }
        printf("%.6lf\n",left);
    }

}
