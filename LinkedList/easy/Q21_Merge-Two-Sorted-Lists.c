/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */



struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){

    struct ListNode* t1 = list1;
    struct ListNode* t2 = list2;
    struct ListNode* final = NULL;
    struct ListNode* tail;
    struct ListNode* cur;
    //traverse both lists together and add the smaller node in final lsit

    while (t1 != NULL && t2 != NULL) {
        if (t1->val < t2->val) {
            //remove from list1
            cur = t1;
            t1 = t1->next;
            //insert in final
            if (final == NULL) {
                final = cur;
            } else {
                tail->next = cur;
            }
            tail = cur;   
        } else {
            //remove from list2
            cur = t2;
            t2 = t2->next;
            //insert in final
            if (final == NULL) {
                final = cur;
            } else {
                tail->next = cur;
            }
            tail = cur;   
        }
    }

//now add remaining nodes from the lists if any
    while (t1) {
        //remove from list1
        cur = t1;
        t1 = t1->next;
        //insert in final
        if (final == NULL) {
            final = cur;
        } else {
            tail->next = cur;
        }
        tail = cur;            
    }

    while(t2) {
        //remove from list2
        cur = t2;
        t2 = t2->next;
        //insert in final
        if (final == NULL) {
            final = cur;
        } else {
            tail->next = cur;
        }
        tail = cur;             
    }

  return final;  
    
}
