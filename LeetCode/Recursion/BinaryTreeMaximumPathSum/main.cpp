//https://leetcode.com/problems/binary-tree-maximum-path-sum/

/*Given the root of a binary tree, return the maximum path sum.
For this problem, a path is defined as any node sequence from some starting node to any node in the tree along the parent-child connections. 
The path must contain at least one node and does not need to go through the root.
*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(): val(0),right(NULL),left(NULL){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int result=INT_MIN;
    
int calculate(TreeNode*root){
    if(root->left==NULL && root->right==NULL){
        result=max(result,root->val);
        return root->val;
    }

    int max_left=-10e6,max_right=-10e6;
    if(root->left)max_left= calculate(root->left);
    if(root->right)max_right=calculate(root->right);

    int t=max(root->val,max(max_left+root->val,root->val+max_right));
    result=max(t,max(result,max_left+root->val+max_right));
    return t;
}
int maxPathSum(TreeNode* root) {
    if(root==NULL)return 0;
    if(root->left==NULL && root->right==NULL)return root->val;
    calculate(root);
    return result;
}
