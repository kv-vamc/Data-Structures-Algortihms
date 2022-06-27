//GFG
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        map<int, int> nodes;
        queue<pair<Node*, int>> q;

        q.push({root, 0});

        while(!q.empty())
        {
            auto p = q.front();
            q.pop();

            int vertical = p.second;
            Node* curNode = p.first;

            if(nodes.find(vertical) == nodes.end())
                nodes[vertical] = curNode -> data;

            if(curNode -> left) q.push({curNode -> left, vertical - 1});
            if(curNode -> right) q.push({curNode -> right, vertical + 1});
        }

        vector<int> ans;
        for(auto it : nodes)
            ans.push_back(it.second);

        return ans;
    }

};
