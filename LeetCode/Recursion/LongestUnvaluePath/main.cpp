//https://leetcode.com/problems/longest-univalue-path
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
};
class Solution{
    public:
        int ans;
        int longestUnivaluePath(TreeNode *root){
            ans=0;
            passThroughTree(root);
            return ans;
        }

        int passThroughTree(TreeNode *root){
            if(root==NULL)return 0;
            
            int left=passThroughTree(root->left);
            int right=passThroughTree(root->right);

            int t_right=0,t_left=0;
            if(root->right!=NULL && root->val==root->right->val){
                t_right=right+1;
            }
            if(root->left!=NULL && root->val==root->left->val){
                t_left=left+1;
            }

            ans=max(ans,t_left+t_right);
            return max(t_left,t_right);
        }
};
