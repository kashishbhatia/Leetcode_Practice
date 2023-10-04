/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        if (head == NULL ) return head;

        if (head->next == NULL) return head;

        ListNode* prev = NULL;
        ListNode* nxt = head->next;
        ListNode* cur = head;

        while (cur && nxt) {
            if (cur == head && prev == NULL) {
                cur->next = nxt->next;
                nxt->next = cur;
                head = nxt;
            } else if (prev) {
                cur->next = nxt->next;
                nxt->next = cur;
                prev->next = nxt;
            }
            prev = cur;
            cur = cur->next;
            if (cur)
                nxt = cur->next;
            else
                nxt = NULL;

        }

        return head;
        
    }
};
