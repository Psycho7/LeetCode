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
    ListNode* swapPairs(ListNode* head) {
        ListNode* preHead = new ListNode(0);
        preHead->next = head;
        ListNode* pre = preHead;
        while (pre && pre->next && pre->next->next) {
            ListNode* first = pre->next;
            ListNode* second = first->next;
            ListNode* third = second->next;
            pre->next = second;
            second->next = first;
            first->next = third;
            pre = first;
        }
        return preHead->next;
    }
};
