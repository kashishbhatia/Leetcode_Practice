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

/* // this will also solve but may give the different layout
    TreeNode* insert (TreeNode* root, int key) {
        if (root == NULL) {
            root = new TreeNode(key);
            return root;
        }

        if (key < root->val) {
            //go to left
            root->left = insert(root->left, key);
        } else if (key > root->val) {
            root->right = insert(root->right, key);
        }
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        TreeNode* root=NULL;
        
        // insert root
        int mid = (n/2);
        root = insert(root, nums[mid]);


        //insert left subtree
        int l = 0, r=mid-1;

        for (int i=l; i<=r; i++)
            root=insert(root, nums[i]);

        //insert right subtree
        l=mid+1;
        r=n-1;

        for (int i=l; i<=r; i++)
            root=insert(root, nums[i]);

        return root;
    }
*/

    TreeNode* sortedArrayToBSTUtil(TreeNode* root, vector<int>& nums, int min, int max) {
        if (max >= min) {
            int mid = min + (max-min)/2;

            if (root == NULL) {
                (root) = new TreeNode(nums[mid]);
            }


            root->left = sortedArrayToBSTUtil(root->left, nums, min, mid-1);
            root->right = sortedArrayToBSTUtil(root->right, nums, mid+1, max);

            
        }
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        TreeNode* root=NULL;

        root = sortedArrayToBSTUtil(root, nums, 0, n-1);
        return root;
    }

};
