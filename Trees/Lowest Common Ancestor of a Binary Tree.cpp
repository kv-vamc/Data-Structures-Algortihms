//Leetcode - 236
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {   
        //traversal might end when we reach NULL
        //if we found p then return p, if we found q then return q
        if(root == NULL || p == root || q == root)
            return root;

        //traverse left and right sub-trees to find LCA
        TreeNode* left = lowestCommonAncestor(root -> left, p, q);
        TreeNode* right = lowestCommonAncestor(root -> right, p, q);

        if(left == NULL)
            return right;
        if(right == NULL)
            return left;
        return root;
    }
};
