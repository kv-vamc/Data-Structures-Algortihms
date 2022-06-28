//Leetcode - 101
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
    bool isSymmetric(TreeNode* root)
    {
        return solve(root -> left, root -> right);    
    }

    bool solve(TreeNode* leftNode, TreeNode* rightNode)
    {
        //check whether nodes exist
        if(leftNode == NULL || rightNode == NULL)
            return leftNode == rightNode;

        //if nodes exist, check whether data is same and check for left and right sub-trees also
        return (leftNode -> val == rightNode -> val) && solve(leftNode -> left, rightNode -> right) && solve(leftNode -> right, rightNode -> left);
    }
};
