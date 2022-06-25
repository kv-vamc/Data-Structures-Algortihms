//Leetcode - 100
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
        //if both the nodes are NULL/not NULL then return true otherwise false
        //here we are intuitively checking structure of trees whether they are identical or not 
        if(p == NULL || q == NULL)
            return p == q;

        //use any tree traversal to check trees are same or not
        //here i used pre-order traversal, verifying current nodes, left & right sub-trees
        return (p -> val == q -> val) && 
                isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right);    
    }
};
