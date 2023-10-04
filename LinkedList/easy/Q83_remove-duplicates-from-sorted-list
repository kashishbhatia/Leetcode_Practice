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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        ListNode* temp1 = NULL;

        if (head == NULL) return NULL;
        if (head->next == NULL) return head;

        while (temp) {
            if (temp->next && temp->val == temp->next->val) {
                if (!temp1)
                    temp1 = temp;

                temp = temp->next;
            } else {
                ListNode* t = NULL;
                if (temp1) {
                    temp1 ->next = temp->next;
                    t = temp;
                    
                }
                temp = temp->next;
                if (t) {
                    t->next = NULL;
                }


                //reset temp1
                temp1 = NULL;
            }
        }
        return head;
    }
};
