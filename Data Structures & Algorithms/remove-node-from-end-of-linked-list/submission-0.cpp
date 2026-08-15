class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int c = 0;
        auto i = head;
        while (i) {
            c++;
            i = i->next;
        }
        if (n == c)
            return head->next;
        i = head;
        for (int j = 1; j < c - n; j++) {
            i = i->next;
        }
        i->next = i->next->next;
        return head;
    }
};