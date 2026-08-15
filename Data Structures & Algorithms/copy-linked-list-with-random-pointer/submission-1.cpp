class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> temp;
        Node* cur = head;
        while(cur){
            temp[cur] = new Node(cur->val);
            cur = cur->next;
        }
        cur = head;
        while(cur){
            Node* copy = temp[cur];
            copy->next = temp[cur->next];
            copy->random = temp[cur->random];
            cur = cur->next;
        }
        return temp[head];

    }
};
