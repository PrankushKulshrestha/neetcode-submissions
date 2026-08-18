class Solution {
public:
    ListNode* reverseK(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (k--) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head->next = curr;
        return prev;
    }
    ListNode* solve(ListNode* head, int k) {
        if (!head)
            return nullptr;
        ListNode* temp = head;
        for (int i = 0; i < k; i++) {
            if (!temp)
                return head;
            temp = temp->next;
        }
        ListNode* rest = solve(temp, k);
        ListNode* newHead = reverseK(head, k);
        head->next = rest;
        return newHead;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return solve(head, k);
    }
};