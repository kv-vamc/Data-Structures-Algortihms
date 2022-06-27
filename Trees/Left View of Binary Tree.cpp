//GfG
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
    void solve(Node* node, vector<int>& ans, int level)
    {
        if(!node)
            return;
        if(ans.size() == level)
            ans.push_back(node -> data);
        solve(node -> left, ans, level + 1);
        solve(node -> right, ans, level + 1);
    }

    vector<int> leftView(Node *root)
    {
        vector<int> ans;
        solve(root, ans, 0); 
        return ans;   
    }
