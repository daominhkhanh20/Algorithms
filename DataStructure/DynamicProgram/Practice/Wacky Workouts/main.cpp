//https://www.hackerearth.com/fr/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/angry-neighbours/description/
#include<bits/stdc++.h>
using namespace std;
/* suppose dp[i] represent the number of possible way to complete the health plan until i days
 There are two ways
 +You go to the workouts on this days. So this is possible in all plan till (i-2) days
 + You don't go to the workout on this days. So this is possible in all plan till (i-1)day
*/
#define ll long long
//dp[i]=dp[i-1]+dp[i-2]
ll numberWay(int n){
	if(n==0)return 1;
	else if(n==1) return 2;

	ll result =0;
	ll s=1,s1=2;
	for(int i=1;i<n;i++){
		result=s+s1;
		s=s1;
		s1=result;
	}
	return result;
}
int main(){
	int t;
	cin>>t;
	while(t-->0){
		int n;
		cin>>n;
		cout<<numberWay(n)<<endl;
	}
	return 0;
}