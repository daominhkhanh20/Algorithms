//https://www.hackerearth.com/fr/practice/algorithms/searching/linear-search/practice-problems/algorithm/joker-and-thieves-53e59f4a/
#include<bits/stdc++.h>
using namespace std;

int numberCaughtThieves(char a[],int n,int k){
    vector<int>police;
    vector<int>thieves;
    for(int i=0;i<n;i++){
        if(a[i]=='T'){
            thieves.push_back(i);
        }
        else if(a[i]=='P'){
            police.push_back(i);
        }
    }
    int s=0;
    int i=0,j=0;
    while(i<police.size()&&j<thieves.size()){
        if(abs(police[i]-thieves[j])<=k){
            s++;
            i++;
            j++;
        }

        else if(police[i]<thieves[j])
            i++;

        else
            j++;
    }
    return s;
}


int main(){
    int t;
    cin>>t;
    while(t-->0){
		int result=0;
		int n,k;
		cin>>n>>k;
		int temp=n;
		while(temp-->0){
			char a[n];
			for(int i=0;i<n;i++)
				cin>>a[i];
			result+=numberCaughtThieves(a,n,k);
		}
		cout<<result;
		
    }

    return 0;
}
