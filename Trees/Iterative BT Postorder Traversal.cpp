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

// Iterative way using 2 stacks
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> ans;

        if(root == NULL) return ans;

        stack<TreeNode*> st1, st2;
        st1.push(root);

        while(!st1.empty())
        {
            TreeNode* temp = st1.top();
            st1.pop();
            st2.push(temp);

            if(temp -> left != NULL) st1.push(temp -> left);
            if(temp -> right != NULL) st1.push(temp -> right);
        }

        while(!st2.empty())
        {
            ans.push_back(st2.top() -> val);
            st2.pop();
        }
        return ans;
    }
};

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

// Iterative way using 1 stack
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> ans;

        if(root == NULL) return ans;

        stack<TreeNode*> st;
        TreeNode* cur = root;

        while(cur != NULL || !st.empty())
        {
            if(cur != NULL)
            {
                st.push(cur);
                cur =  cur -> left;
            }
            else
            {
                TreeNode* temp = st.top() -> right;

                if(temp == NULL)
                {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp -> val);

                    while(!st.empty() && temp == st.top() -> right)
                    {
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp -> val);
                    }
                }
                else
                    cur = temp;
            }
        }
        return ans;
    }
};
