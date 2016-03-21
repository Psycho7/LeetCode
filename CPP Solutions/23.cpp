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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        Heap heap;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) heap.Append(lists[i]);
        }
        ListNode* head = new ListNode(NULL);
        ListNode* tail = head;
        while (heap.Count()) {
            ListNode* lst = heap.Pop();
            tail->next = new ListNode(lst->val);
            tail = tail->next;
            if (lst->next) {
                heap.Append(lst->next);
            }
        }
        return head->next;
    }
private:
    #define ROOT 1
    class Heap {
        public:
            Heap() : count(0), list(10000) {}
            
            int Count() {
                return count;
            }
        
            ListNode* Pop() {
                ListNode* lst = list[ROOT];
                count--;
                if (count) {
                    list[ROOT] = list[count + 1];
                    heapify(ROOT);
                }
                return lst;
            }
            
            void Append(ListNode* node) {
                count++;
                list[count] = node;
                int k = count;
                while (k > ROOT && list[k >> 1]->val > list[k]->val) {
                    list[0] = list[k >> 1];
                    list[k >> 1] = list[k];
                    list[k] = list[0];
                    k = k >> 1;
                }
            }
        private:
            int count = 0;
            vector<ListNode*> list;
            
            void heapify(int k) {
                int l = k << 1;
                int r = (k << 1) + 1;
                int lstIdx = k;
                if (l <= count && list[l]->val < list[k]->val) {
                    lstIdx = l;
                }
                if (r <= count && list[r]->val < list[lstIdx]->val) {
                    lstIdx = r;
                }
                if (k != lstIdx) {
                    list[0] = list[k];
                    list[k] = list[lstIdx];
                    list[lstIdx] = list[0];
                    heapify(lstIdx);
                }
            }
    };
    #undef ROOT
};
