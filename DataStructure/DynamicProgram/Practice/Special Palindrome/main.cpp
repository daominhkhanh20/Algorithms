//https://www.hackerearth.com/fr/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/special-palindrome-3/
#include<bits/stdc++.h>
using namespace std;

void calculate(int sameCharacter[], string s){
	int i=0;
	int n=s.size();

	while(i<n){
		int i=j+1;
		int count=1;
		while(j<n-1){
			if(s[j]==s[j+1]){
				count++;
				j++;
			}
		}
		sameCharacter[i]=count;
		i=j;//increasing i
	}
	for(int i=1;i<n;i++){
		if(s[i]==s[i-1]){
			sameharacter[i]=sameCharacter[i-1];
		}
	}
}

int main(){
	int t;
	cin>>t;
	while(t-->0){
		char c;
		cin>>c;
		string s;
		cin>>s;
		int sameCharacter[s.size()];
		calculate(sameCharacter,s)
	}
}