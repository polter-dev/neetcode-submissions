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
    int kWrapper(TreeNode* root, int k, int *tracker)
    {
        if (!root) return 0;
        
        int val = 0;
        val = kWrapper(root->left, k, tracker);
        
        if (val > 0) return val;
        
        if (k == *tracker) return root->val;
        
        (*tracker)++;
        if (root->right)
            val = kWrapper(root->right, k, tracker);

        return val;
    }

    int kthSmallest(TreeNode* root, int k) 
    {
        if (!root) return 0;
        int t = 1;
        return kWrapper(root, k, &t);
    }
};
