class Solution {
public:

    vector<int> inordTrav;

    vector<int> inorderTraversal(TreeNode* root)
    {
        if(root == NULL) return {};

        inorderTraversal(root -> left);
        inordTrav.push_back(root -> val);
        inorderTraversal(root -> right);

        return inordTrav;
    }
};
