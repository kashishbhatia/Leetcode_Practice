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
    ListNode* reverseList(ListNode* head) {

        if (head == NULL) return head;

        ListNode* temp = head;
        ListNode* temp1 = head->next;
        ListNode* temp2 = temp1; //important
        head->next = NULL;
        

        while (temp2 != NULL) {
            temp2 = temp1->next; //important
            temp1->next = temp;
            temp = temp1;
            temp1 = temp2;
            
        }

        return temp;

    }
};
