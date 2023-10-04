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

    ListNode* mergeLists(ListNode* l1, ListNode* l2) {
        ListNode* newl = new ListNode(0);   //new list
        ListNode* tmp = newl;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                ListNode* next = l1->next;
                tmp->next = l1;
                tmp = l1;
                l1 = next;

                tmp->next = NULL;
            } else {
                ListNode* next = l2->next;
                tmp->next = l2;
                tmp = l2;
                
                l2 = next;
                tmp->next = NULL;
            }
        }

        while (l1) {
           ListNode* next = l1->next; 
            tmp->next = l1;
            tmp = l1;
            
            l1 = next;
            tmp->next = NULL;
        }

        while (l2) {
           ListNode* next = l2->next; 
            tmp->next = l2;
            tmp = l2;
            
            l2 = next;
            tmp->next = NULL;
        } 

        return newl->next;     
    }


    ListNode* sortList(ListNode* head) {
       //merge sort
        if (!head) return head;

        if (head->next == NULL) return head;

        //find middle elem
        ListNode* fast = head;
        ListNode* slow = head;

        ListNode* prev = NULL;
        while (slow && fast && fast->next) {
            prev = slow;        //tracks slow prev
            slow = slow->next;
            fast = fast->next->next;
        }

        //slow prev should disconnect list1
        prev->next = NULL;

        //slow is pointing to mid
        ListNode* list2 = slow;

        ListNode* list1 = head;

        ListNode* l1 = sortList(list1);
        ListNode* l2 = sortList(list2);

        return mergeLists(l1, l2);
    }
};

//Can we do it using bubble sort  ??
