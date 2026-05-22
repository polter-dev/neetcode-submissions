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
    int wrapper(TreeNode *root, int val)
    {
        if (!root) return 0;

        if (root->val >= val) return 1 + wrapper(root->left, root->val) + wrapper(root->right, root->val);
        else return wrapper(root->left, val) + wrapper(root->right, val);
    }
    int goodNodes(TreeNode* root) 
    {
        return wrapper(root, -10000000);
    }
};
