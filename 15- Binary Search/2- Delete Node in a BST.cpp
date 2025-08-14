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

    int getMaxHelper(TreeNode* curr) {
        if(!curr->right)
            return curr->val;
        return getMaxHelper(curr->right);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return root;
        if(key > root->val)
            root->right =  deleteNode(root->right , key);
        else if(key < root->val)
            root->left = deleteNode(root->left , key);
        else {
            // Case 1 not childs
            if (!root->left && !root->right) {
                delete root ;
                return nullptr;
            }

            // case 2 has one child (left or right)
            if (!root->left) {
                TreeNode* child = root->right ;
                root->val = child->val ;
                root->left = child->left ;
                root->right = child->right;
                delete child ;
                return root ;
            }

            if (!root->right) {
                TreeNode* child = root->left ;
                root->val = child->val ;
                root->left = child->left ;
                root->right = child->right;
                delete child ;
                return root ;
            }

            // case 3 has two childs get max value from left or min value from right and swap
            root->val = getMaxHelper(root->left);
            root->left = deleteNode(root->left , root->val);
        }
        return root ; 
    }
};