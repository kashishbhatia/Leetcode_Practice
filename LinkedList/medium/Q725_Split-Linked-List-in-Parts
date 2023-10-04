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

/* CORRECT METHOD

    // Finds no. of nodes in list
    // TC: O(N)
    int nodeCount(ListNode* head) {
        int c = 0;
        while(head) {
            ++c;
            head = head->next;
        }
        return c;
    }
    
    // TC: O(N)
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        // N/k gives max equal no. of nodes per block. In order to keep the
        // max diff 1, we add 1 from each of the remaining N % k elements
        // to the groups from start
        const int N = nodeCount(root);
        
        int elements_per_group = N / k;
        int extra_nodes = N % k;
        
        vector<ListNode*> result(k);
        
        ListNode *curr = root;
        
        for(int i = 0; i < k; i++) {
            int remaining = elements_per_group;
            // if any extra nodes needs to added
            if(extra_nodes > 0) {
                remaining += 1;
                --extra_nodes;
            }

            result[i] = curr;
            ListNode *prev = nullptr;
            // traverse the no. of nodes that will be assigned
            while(remaining--) {
                prev = curr;
                curr = curr->next;
            }
            // end the list
            if(prev)
                prev->next = nullptr;
        }    
        
        return result;
    }

*/






//MY FAULTY CODE
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode *> res(k);
        if (head == NULL) return res;

        int totNodes=0, partNodeCnt=0, leftNodes=0;

        ListNode* temp = head;
        while (temp) {
            totNodes++;
            temp = temp->next;
        }

        partNodeCnt = totNodes/k;
        leftNodes = totNodes%k;
        int i=0;

        temp = head;
        ListNode* partHead = temp;
        
        int Kparts = k;
        ListNode *prev;
        int idx=0;
        while (Kparts) {

            if (i < partNodeCnt) {
                i++;
                prev = temp;
                temp = temp->next;

                continue;
            }

            
            if (!temp) {
                res[idx++] = (partHead);
                break;
            }

            if (leftNodes) {
                prev = temp;
                temp = temp->next;
                leftNodes--;
            }

            ListNode* nextList;
            if (temp) {
                nextList = temp;
                
            } else {
                nextList = NULL;
            }

            prev->next=NULL;
            //insert in res
            res[idx++] = (partHead);

            temp = nextList;
            if (!temp) {
                break;
            }

            //if (temp->next)
            partHead = temp;//->next;

            partNodeCnt = totNodes/k;
            Kparts--;
            i=0;
            //temp= temp->next;
        }
        
        return res;
    }
};
