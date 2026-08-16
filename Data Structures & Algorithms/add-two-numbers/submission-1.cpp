class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int v1 = (l1 != nullptr) ? l1->val : 0;
            int v2 = (l2 != nullptr) ? l2->val : 0;
            int sum = v1 + v2 + carry;
            carry = sum / 10;
            int dig = sum%10;
            cur->next = new ListNode(dig);
            cur = cur->next;
            if (l1 != nullptr) { l1 = l1->next; }
            if (l2 != nullptr ) { l2 = l2->next;}
        }   
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};
