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

    //faster approach :
    //https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/solutions/3532531/image-explanation-fastest-easiest-concise-c-java-python/

    //Uses following algo,
    //1. reach middle using slow and fats ptr
    //2. now from middle(slow ptr) till end (fast ptr), reverse the LL
    //3. add head + middle and keep advanceing them to find max sum

    //takes 200+ms, uses stack




    int pairSum(ListNode* head) {

//NOT WORKING
/*
    ListNode* p1 = head;
    ListNode* p2 = head;
    
    if (head->next->next == NULL) { //only 2 nodes
        return head->val + head->next->val;
    }
    while (p2) {
        p1 = p1->next;
        p2 = p2->next->next;
    }

    ListNode* tmp = p1->next;
    ListNode* cur = tmp;
    ListNode* t1, *t2;
    if (cur)
        t1 = cur->next;
    else t1 = NULL;
    while (t1) {
        t2 = t1->next;
        t1->next = cur;
        cur = t1;
        t1 = t2;
    }
    
    int maxVal = INT_MIN;
    
    ListNode* temp = head;
    while (temp && cur) {
        maxVal = max(maxVal, temp->val + cur->val);
        temp = temp->next;
        cur = cur->next;

    }
    
    return maxVal;
*/

        stack <ListNode*> s;
        int cntNodes = 0;           //total nodes in LL
        ListNode* temp = head;

        while(temp) {
            s.push(temp);
            temp=temp->next;
            cntNodes++;
        }

        int maxSum = INT_MIN;
        int cnt = 0;
        temp = head;

        while (cnt < cntNodes/2 && temp && !s.empty()) {
            ListNode* node = s.top();
            s.pop();

            //twin sum
            int sum = temp->val + node->val;
            maxSum = max(maxSum, sum);

            temp = temp->next;
            cnt++;
        }
        return maxSum;


    }


/* Recursive approach using process stack

void solve(ListNode *root, int n, int res_idx, vector<int> &result){
 
    if(n==2*result.size()) return;
    result [res_idx] += root->val;
    if(n>result.size()-1)  solve(root->next, n+1, res_idx-1, result );
    else if(n==result.size()-1) solve(root->next, n+1, res_idx, result);
    else                  solve(root->next, n+1, res_idx+1, result);
    return;
}
int pairSum(ListNode* root){
    if(!root) return 0;
    ListNode* curr = root;
    int n=0;
    while(curr) {++n; curr=curr->next;} 
    n /= 2;
    vector<int> result(n, 0);
    solve(root, 0, 0, result);
    int res_max = INT_MIN;
    for(auto elem : result) res_max = elem > res_max ? elem : res_max;
    return res_max;
}
*/
};
