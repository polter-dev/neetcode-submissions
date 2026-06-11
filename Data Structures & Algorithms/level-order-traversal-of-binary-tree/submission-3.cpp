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
    void wrapper(vector<vector<int>> &tracker, int k, TreeNode* root)
    {
        if (!root) return;
        if (k == tracker.size())
        {
            tracker.push_back(vector<int>());    
        }
        wrapper(tracker, k+1, root->left);
        wrapper(tracker, k+1, root->right);
        tracker[k].push_back(root->val);
    }
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> t;
     wrapper(t, 0, root);   
        return t;
    }
};
