//Longest increasing subsequence
//using dynamic programming
//O(N^2) need improve the performance algorithms
#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000],l[1000];

/* Algorithm:
+l[i]=1+max(l[j]) if 0<j<i and a[j]<a[i] else l[i]=100
+return max l[i]
*/

int lenghtsSubsize(){
    l[0]=1;
    for(int i=1;i<n;i++){
        l[i]=1;
        for(int j=0;j<i;j++){
            if(a[i]>a[j]&&l[i]<l[j]+1){
                l[i]=l[j]+1;
            }
        }
    }
    return *max_element(l,l+n);
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<lenghtsSubsize()<<endl;
    return 0;
}