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
    unordered_map<TreeNode*, int>tracker;

    int countHeight(TreeNode* root)
    {
        if (!root) return 0;
        try {
            return tracker.at(root);
        } catch (std::out_of_range) {
            tracker[root] = max(countHeight(root->left), countHeight(root->right)) + 1;
            return tracker[root];
        }
        return 1;
    }

    bool isBalanced(TreeNode* root) 
    {
        if (!root) return true;
        bool l = isBalanced(root->left);
        bool ri = isBalanced(root->right);
        if (!l || !ri) return false;
        int left = countHeight(root->left);
        int right = countHeight(root->right);
        int r = countHeight(root);
        if (abs(left - right) > 1) return false;
        return true;
    }
};
