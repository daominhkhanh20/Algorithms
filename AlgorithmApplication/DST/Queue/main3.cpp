#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
vector<int>v1,v2;
int a[maxn];
int ans[maxn];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        v1.clear();
        v2.clear();
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=n;i>=1;i--)
        {
            if(v1.size()==0||v1.back()>=a[i])
            {
                v1.push_back(a[i]);
                v2.push_back(i);
                ans[i]=-1;
            }
            else
            {//C.rbegin () Returns a reverse iterator that points to the last element of the container c
                           //c.rend () Returns a reverse iterator that points to the first element in front of the position of the container c
                                 int j = lower_bound (v1.rbegin (), v1.rend (), a [i]) - v1.rbegin (); // we find a [i] n order to sort according to the lower limit position.
                                 cout<<j<<" "<<v1.size()<<" "<<a[i]<<" "<<v1[j]<<endl;;
                                 j = v1.size () - j; // v1 j has not less than one a [i] is.
                                 ans [i] = v2 [j] -i-1; // j + 1 is the first v2 [j], this time is the rearmost smaller than the number of a [i].
            }
        }
        printf("%d",ans[1]);
        for(int i=2;i<=n;i++)
            printf(" %d",ans[i]);
        printf("\n");
    }
}