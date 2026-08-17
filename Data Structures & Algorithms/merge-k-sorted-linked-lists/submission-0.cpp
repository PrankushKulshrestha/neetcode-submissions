class Solution {
public:
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<
            ListNode*,
            vector<ListNode*>,
            Compare
        > pq;
        for (ListNode* node : lists) {
            if (node != nullptr) {
                pq.push(node);
            }
        }
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            if (node->next != nullptr) {
                pq.push(node->next);
            }
            tail->next = node;
            tail = tail->next;
        }
        return dummy.next;
    }
};