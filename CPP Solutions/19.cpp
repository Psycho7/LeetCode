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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pre = NULL;
        ListNode* now = head;
        ListNode* pilot = head;
        
        while (n) {
            pilot = pilot->next;
            n--;
        }
        
        while (pilot) {
            pre = now;
            now = now->next;
            pilot = pilot->next;
        }
        
        if (now == head) {
            return head->next;
        }
        
        pre->next = now->next;
        return head;
    }
};