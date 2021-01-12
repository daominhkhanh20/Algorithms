//https://leetcode.com/problems/stone-game/
#include<bits/stdc++.h>
using namespace std;

bool stoneGame(vector<int>piles){
    if(piles.size()==0)return false;
    else if(piles.size()==1) return true;

    int alex=0,lee=0,i=0,j=piles.size()-1,flag=1;
    while(i!=j){
        if(flag==1){
            if(piles[i]>=piles[j]){
                alex+=piles[i];
                i++;
            }
            else{
                alex+=piles[j];
                j--;
            }
            flag=0;
        }
        else{
            if(piles[i]>=piles[j]){
                lee+=piles[i];
                i++;
            }
            else{
                lee+=piles[j];
                j--;
            }
            flag=1;
        }
    }
    if(alex>lee) return true;
    return false;
}

int main(){
    int n,x;
    vector<int>piles;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        piles.push_back(x);
    }
    if(stoneGame(piles)){
        cout<<"True"<<endl;
    }
    else cout<<"False"<<endl;
    return 0;
}
