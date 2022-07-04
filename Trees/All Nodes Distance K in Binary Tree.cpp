//Leetcode - 863
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

    void trackParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent)
    {
        queue<TreeNode*> nodes;
        nodes.push(root);

        while(!nodes.empty())
        {
            TreeNode* current = nodes.front();
            nodes.pop();

            if(current->left)
            {
                parent[current->left] = current;
                nodes.push(current->left);
            }

            if(current->right)
            {
                parent[current->right] = current;
                nodes.push(current->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
    {
        unordered_map<TreeNode*, TreeNode*> parent;
        trackParent(root, parent);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> nodes;
        nodes.push(target);
        visited[target] = true;

        int distance = 0;

        while(!nodes.empty())
        {
            if(distance++ == k) break;
            int size = nodes.size();

            for(int i = 0; i < size; i++)
            {
                TreeNode* current = nodes.front();
                nodes.pop();

                if(current->left && !visited[current->left])
                {
                    nodes.push(current->left);
                    visited[current->left] = true;
                }

                if(current->right && !visited[current->right])
                {
                    nodes.push(current->right);
                    visited[current->right] = true;
                }

                if(parent[current] && !visited[parent[current]])
                {
                    nodes.push(parent[current]);
                    visited[parent[current]] = true;
                }
            }
        }

        vector<int> nodesAtDistanceK;

        while(!nodes.empty())
        {
            TreeNode* current = nodes.front();
            nodes.pop();
            nodesAtDistanceK.push_back(current->val);
        }
        return nodesAtDistanceK;
    }
};
