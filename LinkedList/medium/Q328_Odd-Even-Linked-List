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

/* OPTIMIZED without traversing list to find tail

    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return head;
        
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *even_start = head->next;
        
        while(odd->next && even->next){
            odd->next = even->next; //Connect all odds
            even->next = odd->next->next;  //Connect all evens
            odd = odd->next;
            even = even->next;
        }
        odd->next = even_start;   //Place the first even node after the last odd node.
        return head; 
    }

*/

//MY code
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) return NULL;

        //if single node or only 2 nodes
        if (head->next == NULL || head->next->next == NULL) return head;



        //int i=1;    //index
        ListNode* temp = head;  //cur
        ListNode* evenHead = head->next;

        while(temp->next) {
            temp = temp->next;
        }

        ListNode* tail = temp;      //tail of list

        temp = head;        //serves as prev
        while (temp) {
            if (temp->next) {
                ListNode *t = temp->next;
                temp->next = t->next;    
                t->next = NULL;
                tail->next = t;
                tail = t;
            }

            temp = temp->next;

            //for even no. of nodes || for odd no. of nodes
            if (temp == evenHead || (temp->next == evenHead))
                break;
        }
        return head;
    }
};

//ALGO:

//keep odd head, and odd tail. 

//keep even head and even tail

//Also keep prev node pointer used for removal of nodes

//when odd is found, remove node using prev and add it at tail of odd. Update odd tail
//when even is found, remove node using prev and add it at tail of even. Update even tail

