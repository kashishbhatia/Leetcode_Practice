/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
//A difficult question for me
//because it is difficult to visualize

//with stack it is easy to understand 
    void flatten(TreeNode* root) {

        stack <TreeNode *> s;

        if (root == NULL) return;

        s.push(root);
        TreeNode* cur;

        while(!s.empty()) {
            cur = s.top();
            s.pop();

            if (cur && cur->right)
                s.push(cur->right);

            if (cur && cur->left)
                s.push(cur->left);

            TreeNode* t = NULL;
            if (!s.empty())
            t = s.top();

            if (t)
            cur->right = t;
            cur->left = NULL;
            //cur = t;
        } 
    }
};


