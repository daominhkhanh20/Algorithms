//https://leetcode.com/problems/unique-binary-search-trees/
//given n, How many structurally unique BST that store values 1... n
/*Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

*/

/*Algorithms:
 * Let's say node i is chosen to be the root. Then there are i-1 nodes smaller
 * than i and n-i nodes bigger than i.For each of these two sets of nodes, there
 * is a certain number of possible subtrees
 *
 * Let t(n) be the total of BST with n nodes. The total number of BST with i at 
 * root is t(i-1)*t(n-i)
 * */
#include<bits/stdc++.h>
using namespace std;

int numTrees(int n){
    vector<int>d(n+1,0);
    d[0]=d[1]=1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<i;j++){
            d[i]+=d[j]*d[i-j-1];
        }
    }
    return d[n];
}
int main(){
    int n;
    while(cin>>n){
        int result=numTrees(n);
        cout<<result<<endl;
    }
    return 0;
}
