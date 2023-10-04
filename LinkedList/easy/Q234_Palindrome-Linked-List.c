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
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        ListNode* temp = head;

        if (temp == NULL) return true;

        while (temp) {
            s.push(temp->val);
            temp = temp->next;
        }

        // now pop half stack and compare with first half of the list
        int i = 0;
        temp = head;
        while (i <= s.size()/2)
        {
            int val = s.top();
            s.pop();

            if (temp->val != val) {
                return false;
            } else {
                i++;
                temp = temp->next;
            }
        }

        return true;
    }
};
