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
unordered_map<int,int>mp;
int preidx=0;
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int start,int end){
         if(start>end) return NULL;
         int rootval=preorder[preidx++];
         TreeNode*root=new TreeNode(rootval);
         int inidx=mp[rootval];
         root->left=build(preorder,inorder,start,inidx-1);
         root->right=build(preorder,inorder,inidx+1,end);
         return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++) mp[inorder[i]]=i;

        return build(preorder,inorder,0,preorder.size()-1);
    }
};
