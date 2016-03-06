class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode head(0);
        ListNode *p = &head;
        while( l1 || l2 || carry) {
            if (l1) {
                carry += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                carry += l2->val;
                l2 = l2->next;
            }
            p->next = new ListNode(carry % 10);
            carry = carry >= 10;
            p = p->next;
        }
        return head.next;
    }
};