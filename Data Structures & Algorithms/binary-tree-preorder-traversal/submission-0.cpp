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
    void wrapper(TreeNode* root, vector<int>&ret)
    {
        if (!root) return;
        ret.push_back(root->val);
        wrapper(root->left, ret);
        wrapper(root->right, ret);
    }
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> ret;
        wrapper(root, ret);
        return ret;
    }
};