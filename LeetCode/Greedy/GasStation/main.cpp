#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int flag=0;
        int result=-1;
        for(int i=0;i<n;i++){
            int temp=i,cur=gas[i];
            cout<<i<<"--->";
            while((temp+1)%n!=i){
                if(cur<cost[temp])break;
                int tt=(temp+1)%n;
                cur=cur+gas[tt]-cost[temp];
                temp=(temp+1)%n;
                //cout<<temp<<"-"<<cur<<"--->";
            }
            if(cur>0 && (temp+1)%n==i){
                if(cur-cost[temp]>=0){
                    result=i;
                    break;
                };
            }
            //cout<<endl;
        }
        return result;
    }
};
int main(){
    Solution temp;
    vector<int>gas={1,2,3,4,5};
    vector<int>cost={3,4,5,1,2};
    int result=temp.canCompleteCircuit(gas,cost);
    cout<<result<<endl;
    return 0;
}