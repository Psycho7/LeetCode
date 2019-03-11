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
    ListNode* sortList(ListNode* head) {
        // Merge sort, ignore the dirty O(1) space constraint
        
        if (!head || !head->next) return head;
        
        ListNode* walk = head;
        ListNode* jump = head->next;
        while (jump && jump->next) {
            walk = walk->next;
            jump = jump->next->next;
        }
        
        ListNode* left = head;
        ListNode* right = walk->next;
        walk->next = NULL;
        left = sortList(left);
        right = sortList(right);
        
        ListNode* tmpHead = new ListNode(0);
        ListNode* tail = tmpHead;
        while (left && right) {
            if (left->val <= right->val) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
            tail->next = NULL;
        }
        while (left) {
            tail->next = left;
            left = left->next;
            tail = tail->next;
            tail->next = NULL;
        }
        while (right) {
            tail->next = right;
            right = right->next;
            tail = tail->next;
            tail->next = NULL;
        }
        ListNode* result = tmpHead->next;
        delete tmpHead;
        return result;
    }
};