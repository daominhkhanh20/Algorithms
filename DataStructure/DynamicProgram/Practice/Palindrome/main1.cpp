//https://vn.spoj.com/problems/NKPALIN/
#include<bits/stdc++.h>
using namespace std;


string result(string temp,string s){
   int m=temp.size();
   int n=m;
   vector<vector<int>> f(n+1,vector<int>(m+1,0));
   temp=" "+temp;
   s=" "+s;
   for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
         if(s[i]==temp[j]) f[i][j]=f[i-1][j-1]+1;
         else
             f[i][j]=max(f[i-1][j],f[i][j-1]);
      }
   }

   string k="";
   while(f[n][m]>0){
      if(s[n]==temp[m]){
         k+=s[n];
         n--;
         m--;
      }
      else{
         if(f[n][m]==f[n-1][m])
             n--;
         else
             m--;
      }
   }
   return k;
}
int main(){
   string s;
   cin>>s;
   string temp=s;
   reverse(temp.begin(),temp.end());
   cout<<result(temp,s);
   return 0;
}
