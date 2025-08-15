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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q ;
        vector<int> ans ;
        q.push(root);
        while (!q.empty()) {
            int level = q.size() ;
            for (int i = 1 ; i <= level ; i++) {
                TreeNode* curr = q.front() ;
                q.pop();
                if (!curr)
                    continue;
                if (curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                if (i == level) // last node on this level
                    ans.push_back(curr->val);
            }
        }
        return ans ;
    }
};