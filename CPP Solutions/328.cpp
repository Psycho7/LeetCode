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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* oddTail = head;
        ListNode* evenHead = head->next;
        ListNode* evenTail = evenHead;
        
        while (oddTail->next && evenTail->next) {
            oddTail->next = oddTail->next->next;
            evenTail->next = evenTail->next->next;
            oddTail = oddTail->next;
            evenTail = evenTail->next;
        }
        oddTail->next = evenHead;
        
        return head;
    }
};