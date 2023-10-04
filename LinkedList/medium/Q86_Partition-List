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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL) return NULL;

        ListNode* temp = head;

        //testcase head = [1], x=0
        if (head->next == NULL)
            return head;

        ListNode* ptr1 = NULL, *ptr2 = NULL;   //tail of each list
        ListNode *foundNode = NULL, *tempHead1=NULL;
        while (temp) {
            if (temp->val < x) {
                ListNode *cur;
                if (!tempHead1) {
                    cur = temp;
                    temp = temp->next;
                    cur->next = NULL;

                    tempHead1 = ptr1 = cur;
                } else {
                    cur = temp;
                    temp = temp->next;
                    cur->next = NULL;

                    ptr1->next = cur;
                    ptr1 = cur;
                }
            } else if (temp->val >= x) {
                ListNode *cur;

                if (!foundNode) {
                    cur = temp;
                    temp = temp->next;
                    cur->next = NULL;

                    foundNode = ptr2 = cur;
                } else {
                    cur = temp;
                    temp = temp->next;
                    cur->next = NULL;

                    ptr2->next = cur;
                    ptr2 = cur;
                }
            }

        }

        if (ptr1) {
            ptr1->next = foundNode;
            return tempHead1;
        }

        return foundNode;
        
    }
};
