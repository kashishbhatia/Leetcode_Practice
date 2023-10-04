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
        if (head == NULL || head->next == NULL) return head;

        ListNode* cur = head;
        ListNode* prev = NULL, *temp=NULL, *t = NULL, *t2=NULL;

        if (head->val == head->next->val && head->next->next==NULL) return NULL;

        while (cur && cur->next) {
            if (cur->next && cur->val != cur->next->val) {
                prev = cur;
                cur = cur->next;
            } else { //equal

                while(cur->next && cur->val == cur->next->val) {
                    cur = cur->next;
                }

                if (prev == NULL) { //means head need to be shifted
                    head = cur->next;
                    cur->next = NULL;
                    cur = head;
                } else {
                    prev->next = cur->next;
                    cur->next = NULL;
                    cur = prev->next;
                }
            }
        }
        return head;
    }

/*
    ListNode* deleteDuplicates(ListNode* head) {

        if (head == NULL || head->next == NULL) return head;

        ListNode* cur = head;
        ListNode* prev = NULL, *temp=NULL, *t = NULL, *t2=NULL;

        if (head->val == head->next->val && head->next->next==NULL) return NULL;

        while (cur) {
            if (cur->next && cur->val != cur->next->val) {
                if (temp || t2) {
                    if (t2 && t2->next == head) {
                        head = cur->next;
                        t2 = NULL;
                    }
                    temp->next = cur->next;
                    t = cur;
                    prev = temp;
                    temp = NULL;
                } else 
                    prev = cur;
            
                cur = cur->next;

                if (t) {
                    t->next = NULL;
                }
            } else if (cur->next && cur->val == cur->next->val){
                if (cur != head) {
                    temp = prev;

                    prev = cur;
                    cur = cur->next;
                } else {

                        t2 = new ListNode(0);
                        t2->next = head;

                    prev = cur;
                    cur = cur->next;


                }
            } else if (cur->next == NULL){ 
                    //COMMENT THIS, DOESNT WORK
                    if (temp)
                    temp->next = cur->next;
                    t = cur;
                    prev = temp;
                    temp = NULL;
                    t->next = NULL;      
     
            }
        }

        return head;
        
    }

*/
};
