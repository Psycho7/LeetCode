/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* preHead = new ListNode(0);
        ListNode* tail = preHead;
        
        while (l1 || l2) {
            if (l1 && (!l2 || (l2 && l1->val <= l2->val))) {
                tail->next = l1;
                l1 = l1->next;
            } else if (l2 && (!l1 || (l1 && l1->val > l2->val))) {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
            tail->next = NULL;
        }
        
        tail = preHead->next;
        delete preHead;
        return tail;
    }
};