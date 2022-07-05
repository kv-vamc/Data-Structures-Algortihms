//Leetcode -222
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

    //function to count total no.of nodes in complete BT
    int countNodes(TreeNode* root)
    {
        //if given root is NULL
        //if we reached end of leaf
        if(!root) return 0;

        //find left height and right height
        int left_height = leftHeight(root);
        int right_height = rightHeight(root);

        //if left height and right height are equal
        //then we know formula (2^h) - 1 apply that
        if(left_height == right_height) return (1 << left_height) - 1;

        //if left height and right height are not equal
        //then find no.of nodes in left and right sub-trees and add 1(corresponds root)
        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }

    //function finds left height
    int leftHeight(TreeNode* node)
    {
        int height = 0;

        while(node)
        {
            height++;
            node = node -> left;
        }
        return height;
    }

    //function finds right height
    int rightHeight(TreeNode* node)
    {
        int height = 0;

        while(node)
        {
            height++;
            node = node -> right;
        }
        return height;
    }
};
