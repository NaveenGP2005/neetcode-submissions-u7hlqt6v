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
    int fs(TreeNode*node,int &ans){
       if(!node) return 0;
       int lmax=max(0,fs(node->left,ans));
       int rmax=max(0,fs(node->right,ans));
       ans=max(ans,node->val+lmax+rmax);
       return max(lmax,rmax)+node->val;
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
      int ans=INT_MIN;
      fs(root,ans);
      return ans;
    }
};
