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
        vector<int>ans;
        void fs(TreeNode*node){
            if(!node) return;
            fs(node->left);
            ans.push_back(node->val);
            fs(node->right);
        }
    bool isValidBST(TreeNode* root) {
        fs(root);
        for(int i=1;i<ans.size();i++){
            if(ans[i]<=ans[i-1]) return 0;
        }
            return 1;
    }
};
