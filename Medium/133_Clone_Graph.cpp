class Solution {
   public:
    unordered_map<Node*, Node*> visited;

    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;

        Node* ans = new Node(node->val, {});
        visited[node] = ans;

        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            for (auto n : curr->neighbors) {
                // Add neighbour to visited
                if (visited.find(n) == visited.end()) {
                    visited[n] = new Node(n->val, {});
                    q.push(n);
                }

                // Copy neighbour to curr node
                visited[curr]->neighbors.push_back(visited[n]);
            }
        }

        return ans;
    }
};