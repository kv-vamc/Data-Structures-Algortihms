//Leetcode - 987
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
    vector<vector<int>> verticalTraversal(TreeNode* root)
    {
        //Suitable data structure to store nodes in vertical order
        map<int, map<int, multiset<int>>> nodes;

        //using queue to traverse nodes in level order & assign vertical and level no.s to every node
        queue<pair<TreeNode*, pair<int, int>>> q;

        //Initially push root, it is at cell(0, 0)
        q.push({root, {0, 0}});

        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            TreeNode* curNode = p.first;

            int vertical = p.second.first, level = p.second.second;

            nodes[vertical][level].insert(curNode -> val);

            if(curNode -> left) q.push({curNode -> left, {vertical - 1, level + 1}});
            if(curNode -> right) q.push({curNode -> right, {vertical + 1, level + 1}});
        }

        vector<vector<int>> ans;
        //Iterate through nodes data structure and store in 2D vector and return it.
        for(auto vertical : nodes)
        {
            vector<int> col;
            for(auto level : vertical.second)
            {   
                //inserts values at end of vector
                col.insert(col.end(), level.second.begin(), level.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
