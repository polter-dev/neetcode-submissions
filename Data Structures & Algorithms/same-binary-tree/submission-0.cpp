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
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if (!p && !q) return true;
        if (!p && q || p && !q) return false;
        
        bool t = isSameTree(p->left, q->left);
        if (!t) return false;
        t = isSameTree(p->right, q->right);
        if (!t) return false;

        if (p->val == q->val)
            return true;
        return false;
    }
};
