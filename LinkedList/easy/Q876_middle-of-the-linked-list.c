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
    ListNode* middleNode(ListNode* head) {
        ListNode* s = head;
        ListNode* f = head;

        if (head == NULL) return head;
        if (head->next && head->next->next == NULL) return head->next;

        while (f != NULL && f->next != NULL) {
            if (s)
                s = s->next;

            if (f && f->next)
                f = f->next->next;
        }

        return s;
    }
};
