/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)return NULL;
        unordered_map<int, Node*> cloned;
        queue<Node*> q;
        cloned[node->val] = new Node(node->val);
        q.push(node);

        while(q.size()){
            Node* old = q.front();
            q.pop();
            Node* c = cloned[old->val];
            for(Node* n: old->neighbors){
                if(cloned.count(n->val) == 0){
                    cloned[n->val] = new Node(n->val);
                    q.push(n);
                }
                c->neighbors.push_back(cloned[n->val]);
            }
        }
        return cloned[node->val];
    }
};
