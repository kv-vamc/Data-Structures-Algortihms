//GFG
class Solution {
public:

    void addLeftBoundary(Node *node, vector<int> &ans)
    {
        Node *cur = node -> left;
        while(cur)
        {
            if(!isLeaf(cur)) ans.push_back(cur -> data);
            if(cur -> left)
                cur = cur -> left;
            else
                cur = cur -> right;
        }
    }

    void addRighttBoundary(Node *node, vector<int> &ans)
    {
        vector<int> temp;
        Node *cur = node -> right;

        while(cur)
        {
            if(!isLeaf(cur))
                temp.push_back(cur -> data);
            if(cur -> right)
                cur = cur -> right;
            else
                cur = cur -> left;
        }

        for(int i = temp.size - 1; i >= 0; i--)
            ans.push_back(temp[i]);
    }

    void addLeaves(Node *node, vector<int> &ans)
    {
        if(isLeaf(node))
        {
            ans.push_back(node -> data);
            return;
        }

        if(node -> left) addLeaves(node -> left, ans);
        if(node -> right) addLeaves(node -> right, ans);
    }

    bool isLeaf(Node *node)
    {
        return !(node -> left || node -> right);
    }

    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(root == NULL) return ans;
        if(!isLeaf(root)) ans.push_back(root -> data);

        addLeftBoundary(root, ans);
        addLeaves(root, ans);
        addRighttBoundary(root, ans);

        return ans;
    }
};
