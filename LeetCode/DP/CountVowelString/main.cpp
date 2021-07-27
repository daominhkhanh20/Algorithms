#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countVowelStrings(int n) {
        int result[6];
        for(int i=1;i<=5;i++)result[i]=1;
        for(int i=2;i<=n;i++){
            result[1]+=result[2]+result[3]+result[4]+result[5];
            result[2]+=result[3]+result[4]+result[5];
            result[3]+=result[4]+result[5];
            result[4]+=result[5];
        }
        return result[1]+result[2]+result[3]+result[4]+result[5];
    }
};

int main(){
    Solution solution;
    cout<<solution.countVowelStrings(33);
    return 0;
}