//Leetcode - 199
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
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> ans;
        solve(root, ans, 0); 
        return ans;   
    }

    void solve(TreeNode* node, vector<int>& ans, int level)
    {
        if(!node)
            return;
        if(ans.size() == level)
            ans.push_back(node -> val);
        solve(node -> right, ans, level + 1);
        solve(node -> left, ans, level + 1);
    }
};
