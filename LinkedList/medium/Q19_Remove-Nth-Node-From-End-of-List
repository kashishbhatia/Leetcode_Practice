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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = head;

        if (head == NULL)
            return NULL;

        if (head->next == NULL && n==1) //only one node
            return NULL; //remove head and return empty list


        //If more than one node
        while (n) {
            fast = fast->next;
            n--;
        }

        //If fast is NULL, which means, n = len(list), so remove head
        //and return rest of the list
        if (fast == NULL) {
           head = slow->next;
           return head; 
        }
        while (fast != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }

        
        //Now slow must be pointing to nth elem from end
        //remove slow and return head of the list
        prev->next = slow->next;
        return head;
    }
};

//Algo : find nth node from end using slow and fast pointer
