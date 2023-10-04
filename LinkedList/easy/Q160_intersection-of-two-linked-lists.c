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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if (headA == NULL || headB == NULL)
            return NULL;
        
        //get len of 1st list
        ListNode *temp = headA;
        int lenA = 0;
        while (temp != NULL) {
            lenA++;
            temp=temp->next;
        }

        //get len of 2nd list
        temp = headB;
        int lenB = 0;
        while (temp != NULL) {
            lenB++;
            temp=temp->next;
        }

        int diff = 0;
        ListNode *temp1 = NULL;
        if (lenA > lenB) {
            diff = lenA-lenB;
            temp = headA;
            temp1 = headB;
        } else if (lenB > lenA) {
            diff = lenB-lenA;
            temp = headB;
            temp1 = headA;
        } else {
            temp = headA;
            temp1 = headB;
        }

        while(diff && temp) {
            temp = temp->next;
            diff--;
        }

        while (temp && temp1) {
            if (temp == temp1)
                return temp;
            
            temp = temp->next;
            temp1=temp1->next;
        }

        return NULL;
    }
};
