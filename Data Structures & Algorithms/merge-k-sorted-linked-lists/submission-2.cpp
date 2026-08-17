class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        int interval=1;
        int n=lists.size();
        while(interval<n){
            for(int i=0;i<n-interval;i+=interval*2){
                lists[i]=merge_lists(lists[i],lists[i+interval]);
            }
            interval*=2;
        }
        return lists[0];
    }
    ListNode* merge_lists(ListNode* l1,ListNode* l2){
        ListNode dummy(0);
        ListNode* curr=&dummy;
        while(l1!=nullptr && l2!=nullptr){
            if(l1->val <= l2->val){
                curr->next=l1;
                l1=l1->next;
            }
            else{
                curr->next=l2;
                l2=l2->next;
            }
            curr=curr->next;
        }
        if(l1!=nullptr) curr->next=l1;
        else curr->next=l2;
        return dummy.next;
    }
};
