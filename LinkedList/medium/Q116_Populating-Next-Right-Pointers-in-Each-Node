/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node *> q;

        if (root == NULL) {
            return NULL;
        }

        root->next=NULL;
        q.push(root);

        Node *prev = NULL;

        while(!q.empty()) {
            int sz = q.size();

            for (int i=0; i<sz; i++) {
                Node *node = q.front();
                q.pop();

                if (node->left) {

                    //IF is also important here because
                    //we for level 2, prev will be NULL
                    if (prev)
                        prev->next = node->left;

                    prev = node->left;
                    q.push(node->left);
                }

                if (node->right) {
                    prev->next = node->right;
                    
                    //this is very important
                    if (i == sz-1) {    //if this is last node of level, set to NULL
                        prev = NULL;
                    } else {
                        prev = node->right; //else keep it cached 
                    }
                    q.push(node->right);
                }
            }

        }

        return root;
    }

/* OTHER FASTER SOLUTIONS

void connect(TreeLinkNode *root) {
    if (root == NULL) return;
    TreeLinkNode *pre = root;
    TreeLinkNode *cur = NULL;
    while(pre->left) {
        cur = pre;
        while(cur) {
            cur->left->next = cur->right;
            if(cur->next) cur->right->next = cur->next->left;
            cur = cur->next;
        }
        pre = pre->left;
    }
}

*/

};

//we can use BFS iterative here ?
