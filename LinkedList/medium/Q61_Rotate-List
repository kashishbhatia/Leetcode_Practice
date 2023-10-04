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


    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        
        if (head->next == NULL) return head;


        int len=1; // number of nodes
        ListNode *newH, *tail;
        newH=tail=head;
        
        while(tail->next)  // get the number of nodes in the list
        {
            tail = tail->next;
            len++;
        }

        if (len == k || k==0)       //rotation will not cause any change
            return head;


        tail->next = head; // circle the link


        k %= len;
        if(k) 
        {
            //start from last tail only
            for(auto i=0; i<len-k; i++) tail = tail->next; // the tail node is the (len-k)-th node (1st node is head)
        }

//This does not work for list = [1,2], k=1
/*
        int i;

        i = 0;
        

        ListNode *temp = head;
        while (i!=k) {
            temp = temp->next;
            i++;
        }
*/
        newH = tail->next; 
        tail->next = NULL;
        return newH;
    }




/*
    ListNode* rotateRight(ListNode* head, int k) {
        //we can do this using vector stack
        //disadv : uses extra space

        if (head == NULL) return NULL;

        if (head->next == NULL) return head;

        int len = 0;
        ListNode* temp = head;
        ListNode* prev = NULL;

        //prev, cur
        vector<pair<ListNode*, ListNode*>> v;

        while (temp) {
            len++;
            v.push_back({prev, temp});
            prev = temp;
            temp=temp->next;
        }


        if (len == k)       //rotation will not cause any change
            return head;
        
        int indx = len-1;

        ListNode *tail = v[indx].second;    //last elem's cur is tail

        while (k) {
            prev = v[indx].first;
            tail = v[indx].second;

            tail->next = head;
            prev->next = NULL;
            head = tail;

            //update map
            int end = indx;
            int beg = len-indx-1;
            if (beg != end) {
                v[beg].first = head;
                v[end].first = NULL;
            }

            //tail = prev;
            //tail->next = NULL;
            indx--;
            if (indx < 0) {
                indx = len-1;
            }
            k--;

        }

        return head;   
    }
*/
};
