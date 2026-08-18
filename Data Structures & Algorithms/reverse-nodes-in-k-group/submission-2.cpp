class Solution {
   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1) {
            return head;
        }
        ListNode* temp = head;
        for (int i = 0; i < k; i++) {
            if (temp == NULL) {
                return head;
            }
            temp = temp->next;
        }
        ListNode* prev = NULL;
        ListNode* nexty = NULL;
        ListNode* curr = head;
        ListNode* first = head;
        for (int i = 0; i < k; i++) {
            nexty = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nexty;
        }
        first->next = reverseKGroup(curr, k);
        return prev;
    }
};
