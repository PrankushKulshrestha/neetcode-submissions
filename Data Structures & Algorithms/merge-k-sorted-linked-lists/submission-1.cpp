class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<
            pair<int, ListNode*>,
            vector<pair<int, ListNode*>>,
            greater<pair<int, ListNode*>>
        > pq;
        for (ListNode* node : lists) {
            if (node != nullptr) {
                pq.push({node->val, node});
            }
        }
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (!pq.empty()) {
            ListNode* node = pq.top().second;
            pq.pop();

            if (node->next != nullptr) {
                pq.push({node->next->val, node->next});
            }
            tail->next = node;
            tail = tail->next;
        }
        return dummy.next;
    }
};