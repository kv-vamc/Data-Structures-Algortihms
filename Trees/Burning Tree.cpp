//GFG
class Solution {
  public:

    Node* trackParent(Node* root, unordered_map<Node*, Node*> &parent, int target)
    {
        queue<Node*> nodes;
        nodes.push(root);
        Node* start;

        while(!nodes.empty())
        {
            Node* current = nodes.front();
            //checking for target node
            if(current->data == target) start = current;
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
        return start;
    }

    int minTime(Node* root, int target) 
    {
      //To store parent pointers
      //using unordered_map for faster search and inserton
      unordered_map<Node*, Node*> parent;

      //while storing parent pointer we will find for address of target node and store it in start node
      Node* start = trackParent(root, parent, target);

      //used to know whether a node is visited or not
      //using unordered_map for faster search and inserton
      unordered_map<Node*, bool> visited;
      
      //subtracting by '1' because we will get height as #nodes in that path.
      //But, we want path length so subtracting by '1'
      return solve(start, parent, visited) - 1;
    }

    int solve(Node* node, unordered_map<Node*, Node*> &parent, unordered_map<Node*, bool> &visited)
    {
      //if given node is NULL or we reached end of the path
      if(!node) return 0;
      //if node is visited then we dont consider it
      if(visited[node]) return 0;

      //After visiting mark the node as true(means it's been visited)
      visited[node] = true;

      //we need max among all left, right and parent paths. So, initialize with min value.
      int lh = INT_MIN, rh = INT_MIN, ph = INT_MIN;

      //explore left, right and parent paths
      lh = solve(node->left, parent, visited);
      rh = solve(node->right, parent, visited);
      ph = solve(parent[node], parent, visited);

      //take max among left, right and parent paths
      return 1 + max(ph, max(lh, rh));
    }
};
