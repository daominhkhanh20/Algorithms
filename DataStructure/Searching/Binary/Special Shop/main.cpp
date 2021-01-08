//https://www.hackerearth.com/fr/practice/algorithms/searching/linear-search/practice-problems/algorithm/special-shop-69904c91/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int q;
    cin>>q;
    while(q-->0){
        int n,a,b;
        cin>>n>>a>>b;
        int result=0;
        if ((n*b)%(a+b)!=0){
			int temp=n*b/(a+b);
			int count1=a*pow(temp,2)+b*pow(n-temp,2);
			int count2=a*pow(temp+1,2)+b*pow(n-1-temp,2);
			result=count1<count2?count1:count2;
		}
		else{
			int temp=n*b/(a+b);
			result=a*pow(temp,2)+b*pow(n-temp,2);
		}
		cout<<result<<endl;
	}
	return 0;
}
    
