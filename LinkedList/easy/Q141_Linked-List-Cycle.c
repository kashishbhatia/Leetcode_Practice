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
    bool hasCycle(ListNode *head) {
       ListNode *fast = head;
       ListNode *slow=head;

        if (head == NULL)
            return false;
       while(1) {

           slow = slow->next;

           if (fast->next)
                fast = fast->next->next;

           if (fast == NULL || fast->next == NULL) {
               break;
           }
           if (fast == slow) {
               return true;
           }
       } 

       return false;
        
    }
};
