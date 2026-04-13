/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void fs(TreeNode*node,int &ans,int maxv){
         if(!node) return;
         if(node->val>=maxv){
            ans++;
            maxv=node->val;
         }
         fs(node->left,ans,maxv);
         fs(node->right,ans,maxv);
    }
    int goodNodes(TreeNode* root) {
        int ans=0;
        fs(root,ans,root->val);
        return ans;
    }
};
